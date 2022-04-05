#include <iostream>
using namespace std;

#include "../../utils/string/string.h"
#include "subject.h"

Subject::Subject(String name, String description) {
  this->name = name;
  this->description = description;
}

Subject::~Subject() { cout << "Subject destructor called" << endl; }

Subject &Subject::operator=(const Subject &subject) {
  this->name = subject.name;
  this->description = subject.description;
  return *this;
}

String Subject::getName() { return this->name; }

String Subject::getDescription() { return this->description; }
