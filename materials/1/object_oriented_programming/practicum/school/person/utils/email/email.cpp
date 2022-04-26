#include <iostream>
using namespace std;

#include "email.h"

Email::Email() { address = "__@email.bg"; }

Email::Email(Name name) {
  address = name.getFirstName()
                .append(".")
                .append(name.getLastName())
                .append("@email.bg");
}

void Email::setAddress(String address) { this->address = address; }

String Email::getAddress() const { return address; }
