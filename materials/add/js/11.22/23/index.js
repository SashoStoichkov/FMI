const fs = require("fs");
const { pipeline, Transform } = require("stream");

const readStream = fs.createReadStream("input.txt", { highWaterMark: 5 });
const writeStream = fs.createWriteStream("output.txt", { highWaterMark: 5 });

let line = "";
const re = [/asd/g, /[A-Z]/g, /[0-9]/g];

function lineTransform(line, re) {
  let result = line;

  re.forEach((regex) => {
    result = result.replace(regex, (match) => "*".repeat(match.length));
  });

  return result;
}

const transformStream = new Transform({
  transform(chunk, encoding, callback) {
    for (let i = 0; i < chunk.length; i++) {
      if (String.fromCharCode(chunk[i]) === "\n") {
        this.push(lineTransform(line, re));
        this.push("\n");

        line = "";
      } else {
        line += String.fromCharCode(chunk[i]);
      }
    }

    this.push(lineTransform(line, re));

    callback();
  },
});

pipeline(readStream, transformStream, writeStream, (err) => {
  if (err) {
    console.log("Pipeline failed.", err);
  } else {
    console.log("Pipeline succeeded.");
  }
});
