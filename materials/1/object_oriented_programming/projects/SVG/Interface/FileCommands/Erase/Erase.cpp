#include <iostream>
using namespace std;

#include "Erase.h"

Erase::Erase(const string &line) : Command(line) {}

bool Erase::execute() {
  if (!Command::fileOpen) {
    cout << "Erase: You don't have opened file." << endl;
    return false;
  }

  if (args.size() == 0) {
    cout << "Erase: no shape index given" << endl;
    return false;
  } else if (args.size() > 1) {
    cout << "Erase: too many arguments (" << args.size() << " > 1)" << endl;
    return false;
  } else {
    Command::file.removeShape(stoi(args[0]));

    return true;
  }
}
