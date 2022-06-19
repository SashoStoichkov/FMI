#include <iostream>
using namespace std;

#include "Close.h"

Close::Close(const string &line) : Command(line) {}

bool Close::execute() {
  if (!Command::fileOpen) {
    cout << "You don't have opened file." << endl;
    return false;
  }

  if (args.size() != 0) {
    cout << "Close: too many arguments (" << args.size() << " > 0)" << endl;
    return false;
  } else {
    Command::fileOpen = false;
    Command::prompt = "> ";

    cout << "Close: file successfully closed" << endl;

    return true;
  }
}
