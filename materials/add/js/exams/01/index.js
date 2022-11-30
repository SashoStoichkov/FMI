// FN: 0MI0800024

// Write a simple implementation of a EventEmitter class that when extended can be used to emit events and
// listen for certain events using the “emit" and “on” methods. Also add an "unsubscribe" method, to stop listening

class EventEmitter {
  constructor() {
    this.events = {};
  }

  on(eventName, handler) {
    if (!this.events[eventName]) {
      this.events[eventName] = [];
    }
    this.events[eventName].push(handler);
  }

  emit(eventName, data) {
    if (this.events[eventName]) {
      this.events[eventName].forEach((handler) => handler(data));
    }
  }

  unsubscribe(eventName, handler) {
    if (this.events[eventName]) {
      this.events[eventName] = this.events[eventName].filter(
        (event) => event !== handler
      );
    }
  }
}

// For more information check the example bellow:
class Person extends EventEmitter {
  constructor(age) {
    super();
    this.age = age;
  }
  getOlder() {
    this.age++;
    this.emit("get-older", this.age);
  }
}

// const ivan = new Person(23);
// const handler = (age) => console.log(`Happy ${age}th birthday! 🎂`);
// ivan.on("get-older", handler);
// ivan.getOlder(); // Happy 24th birthday! 🎂
// ivan.getOlder(); // Happy 25th birthday! 🎂

// ivan.unsubscribe("get-older", handler);
// ivan.getOlder(); // *nothing*

// var thing = 5;

// function tryToMessWithGlobals() {
//   console.log(1, thing);
//   thing = 15;

//   var thing;
//   console.log(2, thing);
// }

// console.log(3, thing);
// tryToMessWithGlobals();
// console.log(4, thing);

// function middleScope() {
//   console.log(1, scopedInTheMiddle);

//   function innerScope() {
//     console.log(2, scopedInTheMiddle);
//     scopedInTheMiddle = 120;
//   }

//   var scopedInTheMiddle = 42;

//   console.log(3, scopedInTheMiddle);
//   innerScope();
//   console.log(4, scopedInTheMiddle);
// }

// middleScope();

// let fns = [];
// for (let i = 0; i < 3; i += 1) {
//   fns.push(() => i);
// }
// console.log(fns.map((f) => f()).join(", "));

// function Foo() {}

// Foo.__proto__ = { bar: 42 };

// var obj = new Foo();
// console.log(obj.bar);

// function Superhero() {
//   setTimeout(() => {
//     console.log(this.constructor);
//   }, 0);
// }

// Superhero();
// new Superhero();

// function foo() {}

// foo.prototype = {
//   bar: 42,
// };
// var o1 = new foo();
// var o2 = new foo();

// o2.bar = 42;
// o1.__proto__.bar += 1;

// console.log(o1.bar === o2.bar);

var obj = {
  foo: function () {
    this.bar(); },
  bar: function () {
    console.log('bar'); }
},
temp = obj.foo;
temp();
