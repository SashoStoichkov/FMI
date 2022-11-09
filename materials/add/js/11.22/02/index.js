const fs = require("fs");

function calculateScore(recieves, credits) {
  if (recieves === "xxx") return 0;
  return (recieves / 6) * credits;
}

fs.readFile("./inputFiles/Students.txt", "utf-8", (err, data) => {
  if (err) throw err;

  const students = data
    .split("\n")
    .filter((student) => !student.startsWith("#"));

  const outputStudents = students.map((student) => {
    const info = student.split(" ");

    const id = info.pop();
    const name = info.join(" ");

    return { name: name, id: id };
  });

  fs.readFile("./inputFiles/Marks.txt", "utf-8", (err, data) => {
    if (err) throw err;

    const marks = data.split("\n").filter((mark) => !mark.startsWith("#"));

    const outputMarks = outputStudents.map((student) => {
      const mark = marks.find((mark) => mark.startsWith(student.id));

      const info = mark.split(" ");
      info.shift();

      return {
        name: student.name,
        marks: info,
      };
    });

    fs.readFile("./inputFiles/Credits.txt", "utf-8", (err, data) => {
      if (err) throw err;

      const credits = new Map();

      const subject = data.split("\n")[0].split(" ");
      const credit = data.split("\n")[1].split(" ");

      for (let i = 0; i < subject.length; i++) {
        credits.set(subject[i], credit[i]);
      }

      const output = outputMarks.map((student) => {
        const mathematics = calculateScore(
          student.marks[0],
          credits.get("mathematics")
        ).toFixed(2);
        const literature = calculateScore(
          student.marks[1],
          credits.get("literature")
        ).toFixed(2);
        const geography = calculateScore(
          student.marks[2],
          credits.get("geography")
        ).toFixed(2);

        return {
          name: student.name,
          mathematics: mathematics,
          literature: literature,
          geography: geography,
        };
      });

      console.log(output);

      fs.writeFile(
        "Output.txt",
        JSON.stringify(output, null, 2),
        (err) => {
          if (err) throw err;

          console.log("File created successfully");
        }
      );
    });
  });
});
