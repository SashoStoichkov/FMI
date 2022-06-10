#include <fstream>
#include <iostream>
using namespace std;

#include "Open.h"

Open::Open(const string &line) : Command(line) {}

bool Open::execute() {
  if (Command::fileOpen) {
    cout << "You have an open file with unsaved changes, please select "
            "close or save first."
         << endl;
    return false;
  }

  if (args.size() == 0) {
    cout << "Open: no file name given" << endl;
    return false;
  } else if (args.size() > 1) {
    cout << "Open: too many arguments (" << args.size() << " > 1)" << endl;
    return false;
  } else if (args[0].substr(args[0].find_last_of('.') + 1) != "svg") {
    cout << "Open: file extension is not .svg" << endl;
    return false;
  } else {
    cout << "Open: opening file " << args[0] << endl;

    // check if file exists
    ifstream file(args[0]);

    if (!file.is_open()) {
      cout << "Open: file not found. Creating file" << endl;

      // create file
      ofstream file(args[0]);
      file.close();
    } else {
      Command::file = File(args[0]);
      Command::file.load();
    }

    file.close();

    cout << "Open: successfully opened " << args[0] << endl;

    Command::fileOpen = true;
    Command::prompt = "> " + args[0] + " > ";

    return true;
  }
}
