const http = require("http");
// const https = require("https");

class MyPromise {
  constructor(fn) {
    this.cbs = [];

    fn(
      (val) => this.resolve(val),
      (err) => this.reject(err)
    );
  }

  resolve(val) {
    let cb;
    while ((cb = this.cbs.shift())) {
      val = cb(val);

      if (val instanceof Promise) {
        return val.then((val) => this.resolve(val));
      }
    }
  }

  reject(err) {
    console.error(err);
  }

  then(cb) {
    this.cbs.push(cb);
    return this;
  }

  catch(cb) {
    this.cbs.push(cb);
    return this;
  }
}

// const promise = new MyPromise((resolve, reject) => {
//   setTimeout(() => {
//     // resolve(1);
//     // resolve(2);
//     resolve(Math.floor(Math.random() * 10));
//   }, 1000);
// });

// promise.then((res) => {
//   if (res % 2 === 0) {
//     setTimeout(() => {
//       console.log(res);
//       return Promise.resolve(res);
//     }, 1000);
//   } else {
//     http.get("http://example.com", (response) => {
//       setTimeout(() => {
//         response.on("data", (data) => {
//           console.log(data.toString());
//           return Promise.resolve(data.toString());
//         });
//       }, 1000);
//     });

//     // https.get("https://www.google.com", (res) => {
//     //   res.on("data", (data) => {
//     //     console.log(data.toString());
//     //   });
//     // });
//   }
// });

const p1 = new Promise((resolve, reject) => {
  setTimeout(() => {
    resolve("Success");
  }, 1000);
});

// The following behaves the same as above
p1.then((value) => {
  console.log(value); // "Success!"
  return p1.reject("oh, no!");
})
  .catch((e) => {
    // console.error(e); // "oh, no!"
    return Promise.resolve("oh, no!");
  })
  .then(() => console.log("after a catch the chain is restored"))
  // .then(() => console.log("Not fired due to the catch"))
  .catch((e) => console.error("Not fired due to the catch"));
