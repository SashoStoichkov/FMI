function Point(x, y) {
  this.x = x;
  this.y = y;
}

Point.prototype.getDinstance = function (point2) {
  return Math.sqrt(
    Math.pow(point2.x - this.x, 2) + Math.pow(point2.y - this.y, 2)
  );
};

var p1 = new Point(0, 0);
var p2 = new Point(3, 4);
console.log(p1.getDinstance(p2));

function Circle(x, y, radius) {
  Point.call(this, x, y);
  this.radius = radius;
}

Circle.prototype = Object.create(Point.prototype);

Circle.prototype.getCircumference = function () {
  return 2 * Math.PI * this.radius;
};
Circle.prototype.getArea = function () {
  return Math.PI * Math.pow(this.radius, 2);
};
Circle.prototype.intersects = function (circle2) {
  return this.getDinstance(circle2) <= this.radius + circle2.radius;
};

var c1 = new Circle(0, 0, 5);
var c2 = new Circle(0, 0, 10);
console.log("Circumference: " + c1.getCircumference());
console.log("Area: " + c1.getArea());
console.log("Intersects: " + c1.intersects(c2));

function Rectangle(x, y, width, height) {
  Point.call(this, x, y);
  this.width = width;
  this.height = height;
}

Rectangle.prototype = Object.create(Point.prototype);

Rectangle.prototype.getPerimeter = function () {
  return 2 * (this.width + this.height);
};
Rectangle.prototype.getArea = function () {
  return this.width * this.height;
};
Rectangle.prototype.getLengthOfDiagonals = function () {
  return Math.sqrt(Math.pow(this.width, 2) + Math.pow(this.height, 2));
};
Rectangle.prototype.getBiggestCircle = function () {
  return new Circle(
    this.width / 2,
    this.height / 2,
    Math.min(this.width, this.height) / 2
  );
};

var r = new Rectangle(0, 0, 10, 20);
console.log("Perimiter: " + r.getPerimeter());
console.log("Area: " + r.getArea());
console.log("Diagonals: " + r.getLengthOfDiagonals());
console.log(r.getBiggestCircle());

function RectanglePrism(x, y, width, height, c) {
  Rectangle.call(this, x, y, width, height);
  this.c = c;
}

RectanglePrism.prototype = Object.create(Rectangle.prototype);
RectanglePrism.prototype.getVolume = function () {
  return this.width * this.height * this.c;
};

var rp = new RectanglePrism(0, 0, 10, 20, 30);
console.log("Volume: " + rp.getVolume());
