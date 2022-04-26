#include <iostream>
using namespace std;

#include "phone.h"

Phone::Phone(String number) {
  if (number.length() == 9 || number.length() == 10) {
    if (number.length() == 9 && number[0] != '0') {
      this->number = String("+359").append(number);
    } else if (number.length() == 10 && number[0] == '0') {
      this->number = String("+359").append(number.substr(1, number.length()));
    } else {
      throw "Invalid phone number!";
    }
  }
}

void Phone::setNumber(String number) { this->number = number; }

String Phone::getNumber() const { return number; }