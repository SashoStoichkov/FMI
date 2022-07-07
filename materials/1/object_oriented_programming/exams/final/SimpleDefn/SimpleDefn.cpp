#include <iostream>
using namespace std;

#include "SimpleDefn.h"

void SimpleDefn::copy(const SimpleDefn &other) {
  strcpy(other.name, this->name);
  strcpy(other.value, this->value);
}

void SimpleDefn::free() {
  delete[] name;
  delete[] value;
}

bool isNameValid(char *name) {
  if (name[0] < 'a' || name[0] > 'z') {
    return false;
  }

  for (int i = 1; i < strlen(name); i++) {
    if (name[i] < 'a' || name[i] > 'z') {
      if (name[i] != '_') {
        return false;
      }
    }
  }

  return true;
}

SimpleDefn::SimpleDefn(char *name, char *value) {
  if (!isNameValid(name)) {
    throw "Name is invalid";
  } else {
    this->name = new char[strlen(name) + 1];
    strcpy(this->name, name);

    this->value = new char[strlen(value) + 1];
    strcpy(this->value, value);
  }
}

SimpleDefn::SimpleDefn(const SimpleDefn &other) { copy(other); }

SimpleDefn::SimpleDefn(SimpleDefn &&other) {
  // move other's attributes to this
  this->name = move(other.name);
  this->value = move(other.value);

  // free other
  other.free();
}

SimpleDefn::~SimpleDefn() { free(); }

SimpleDefn &SimpleDefn::operator=(const SimpleDefn &other) {
  if (this != &other) {
    free();
    copy(other);
  }
  return *this;
}

SimpleDefn &SimpleDefn::operator=(SimpleDefn &&other) {
  if (this != &other) {
    free();

    // move other's attributes to this
    this->name = move(other.name);
    this->value = move(other.value);

    // free other
    other.free();
  }
  return *this;
}

char *SimpleDefn::getName() const { return this->name; }

char *SimpleDefn::getValue() const { return this->value; }
