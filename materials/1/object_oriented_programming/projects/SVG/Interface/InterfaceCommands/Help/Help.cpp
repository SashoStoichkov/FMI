#include <iostream>
using namespace std;

#include "Help.h"

Help::Help(const string &line) : Command(line) {}

bool Help::execute() {
  cout << "The following commands are supported:" << endl;
  cout << "- open <file> \t opens <file>" << endl;
  cout << "- close \t closes currently opened file" << endl;
  cout << "- save \t\t saves the currently open file" << endl;
  cout << "- saveas <file>  saves the currently open file in <file>" << endl;
  cout << "- help \t\t prints this information" << endl;
  cout << "- exit \t\t exists the program" << endl;

  return true;
}
