#include <iostream>
using namespace std;

#include "name.h"

Name::Name(String firstName, String lastName) {
  this->firstName = firstName;
  this->lastName = lastName;
}

void Name::setFirstName(String firstName) { this->firstName = firstName; }

void Name::setLastName(String lastName) { this->lastName = lastName; }

String Name::getFirstName() const { return this->firstName; }

String Name::getLastName() const { return this->lastName; }