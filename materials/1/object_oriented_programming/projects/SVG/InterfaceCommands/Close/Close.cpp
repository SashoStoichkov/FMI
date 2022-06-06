#include <iostream>
using namespace std;

#include "Close.h"

Close::Close(const string &line) : Command(line) {}

bool Close::execute() {
  Command::fileOpen = false;
  Command::prompt = "> ";

  cout << "Close: file successfully closed" << endl;

  return true;
}
