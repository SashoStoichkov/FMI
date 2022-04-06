#include <iostream>
using namespace std;

#include "template.h"

void Template::copy(const Template &other) {}

void Template::free() {}

Template::Template(/* attributes */) {}

Template::Template(const Template &other) { copy(other); }

// move constructor
Template::Template(Template &&other) {
  // move other's attributes to this
  // ... ex. this->a = move(other.a);
  // free other's attributes
  other.free();
}

Template::~Template() { free(); }

Template &Template::operator=(const Template &other) {
  if (this != &other) {
    free();
    copy(other);
  }
  return *this;
}

Template &Template::operator=(Template &&other) {
  if (this != &other) {
    free();
    // move other's attributes to this
    // ... ex. this->a = move(other.a);
    // free other's attributes
    other.free();
  }
  return *this;
}