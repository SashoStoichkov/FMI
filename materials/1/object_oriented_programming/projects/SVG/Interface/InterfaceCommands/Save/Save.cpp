#include <iostream>
using namespace std;

#include "Save.h"

Save::Save(const string &line) : Command(line) {}

bool Save::execute() {
  if (!Command::fileOpen) {
    cout << "You don't have opened file." << endl;
    return false;
  }

  if (args.size() >= 1) {
    cout << "Save: too many arguments (" << args.size() << " > 0)" << endl;
    return false;
  } else {
    cout << "Save: saving file " << Command::file.getPath() << endl;

    Command::file.save();

    return true;
  }
}
