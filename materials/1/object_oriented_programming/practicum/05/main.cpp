// https://bit.ly/28MAr2022

#include <iostream>
using namespace std;

#include "subject.h"

int main() {

  Subject subject1("C++", "C++ is a programming language");

  subject1.getName().print();
  subject1.getDescription().print();

  return 0;
}