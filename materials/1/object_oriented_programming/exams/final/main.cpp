#include <iostream>
using namespace std;

#include "./SimpleDefn/SimpleDefn.h"
#include "./ParamDefn/ParamDefn.h"

int main() {
  // try {
  //   SimpleDefn("asd", "asdf");
  // } catch (const char* e) {
  //   cout << e << endl;
  // }

  // try {
  //   ParamDefn("asd", "asd #1 #2 #1!");
  // } catch (const char* e) {
  //   cout << e << endl;
  // }

  ParamDefn a("asd", "My name is #1. - Hello #1, I'm #2!");
  a.printValue();

  return 0;
}