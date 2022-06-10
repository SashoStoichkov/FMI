#include <iostream>
using namespace std;

#include "Print.h"

Print::Print(const string &line) : Command(line) {}

bool Print::execute() {
  if (!Command::fileOpen) {
    cout << "Print: You don't have opened file." << endl;
    return false;
  }

  if (args.size() >= 1) {
    cout << "Print: too many arguments (" << args.size() << " > 0)" << endl;
    return false;
  } else {
    cout << "Print: printing file " << Command::file.getPath() << endl;

    Command::file.print();

    return true;
  }
}
