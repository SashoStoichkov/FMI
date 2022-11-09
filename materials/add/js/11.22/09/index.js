const http = require("http");
const https = require("https");
const querystring = require("querystring");

// Task 1
// handleGetRequest = function (req, res) {
//   const query = req.url.split("?")[1];
//   const queryObject = querystring.parse(query);

//   const url = queryObject.url;

//   if (url) {
//     const client = url.startsWith("https") ? https : http;

//     client.get(url, (response) => {
//       let data = "";
//       response.on("data", (chunk) => {
//         data += chunk;
//       });
//       response.on("end", () => {
//         res.end(data);
//       });
//     });
//   } else {
//     res.end();
//   }
// };

// Task 2
const localJson = {
  name: "John",
  age: "30",
  city: "New York",
};

handleGetRequest = function (req, res) {
  const prop = req.url.split("/")[2].split(":")[1];
  res.end(localJson[prop]);
};

const sever = http.createServer(function (req, res) {
  const method = req.method.toUpperCase();
  if (method === "GET") {
    return void handleGetRequest(req, res);
  }
  if (method === "POST") {
    return void handlePostRequest(req, res);
  }
});

sever.listen(8080, () => {
  console.log("Server is listening :8080");
});

const proxy = new Proxy(
  {},
  {
    get(target, prop) {
      http.get(`http://localhost:8080/load/:${prop}`, (response) => {
        let data = "";
        response.on("data", (chunk) => {
          data += chunk;
        });
        response.on("end", () => {
          console.log(data);
        });
      });
    },
  }
);

proxy.name;
