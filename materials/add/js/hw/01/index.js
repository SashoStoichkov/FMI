const fs = require("fs");

const http = require("http");
const https = require("https");

const express = require("express");
const app = express();

const PORT = 8080;

// gets regex from file and if anything matches it, it will be replaced with "*"
function sanitize(data) {
  const regex = fs.readFileSync("regex.txt", "utf8").split("\n");

  for (let i = 0; i < regex.length; i++) {
    const re = new RegExp(regex[i], "g");
    data = data.replace(re, (match) => "*".repeat(match.length));
  }

  return data;
}

// get /sanitize?url= - sanitize a url
// response: sanitized data
app.get("/sanitize", (req, res) => {
  let url = req.query.url;

  if (!url) {
    res.status(400).send("Missing url");
    return;
  }

  url = url.replace(/"/g, "");

  const protocol = url.startsWith("https") ? https : http;

  protocol
    .get(url, (response) => {
      let data = "";

      response.on("data", (chunk) => {
        data += chunk;
      });

      response.on("end", () => {
        res.send(sanitize(data));
      });
    })
    .on("error", (err) => {
      res.status(500).send(err);
    });
});

// get /condition - get all regex
// response: [regex]
app.get("/condition", (req, res) => {
  fs.readFile("regex.txt", "utf8", (err, data) => {
    if (err) {
      res.status(500).send("Error");
      return;
    }

    res.send(data.split("\n"));
  });
});

// post /condition - add a regex to regex.txt
// request: regex
// response: "Regex added"
app.post("/condition", (req, res) => {
  let regex = req.body.regex;

  if (!regex) {
    res.status(400).send("Missing regex");
    return;
  }

  const regexes = fs.readFileSync("regex.txt", "utf8").split("\n");
  for (let i = 0; i < regexes.length; i++) {
    if (regexes[i] === regex) {
      res.status(400).send("Regex already exists");
      return;
    }
  }

  fs.appendFile("regex.txt", regex + "\n", (err) => {
    if (err) {
      res.status(500).send("Error");
      return;
    }

    res.send("Regex added");
  });
});

// delete /condition/:id - remove a regex from regex.txt by id (line number)
// response: "Regex removed"
app.delete("/condition/:id", (req, res) => {
  const id = +req.params.id;

  if (!id) {
    res.status(400).send("Missing id");
    return;
  }

  fs.readFile("regex.txt", "utf8", (err, data) => {
    if (err) {
      res.status(500).send("Error");
      return;
    }

    const regex = data.split("\n");

    if (id > regex.length - 1) {
      res.status(404).send("Regex not found");
      return;
    }

    regex.splice(id - 1, 1);

    fs.writeFile("regex.txt", regex.join("\n"), (err) => {
      if (err) {
        res.status(500).send("Error");
        return;
      }

      res.send("Regex removed");
    });
  });
});

app.listen(PORT, () => {
  console.log(`Server started on port ${PORT}`);
});
