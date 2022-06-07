#include <iostream>
using namespace std;

#include "Shape.h"

vector<string> Shape::availableColors = {"red",    "green", "blue",
                                         "yellow", "black", "white"};

void Shape::copy(const Shape &other) { name = other.name; }

void Shape::free() { name.clear(); }

Shape::Shape(string name) : name(name) {}

Shape::Shape(const Shape &other) { copy(other); }

Shape::~Shape() { free(); }

Shape &Shape::operator=(const Shape &other) {
  if (this != &other) {
    free();
    copy(other);
  }
  return *this;
}

string Shape::getName() const { return name; }

ostream &operator<<(ostream &os, const Shape &shape) {
  os << "Shape name: " << shape.name << endl;
  return os;
}
