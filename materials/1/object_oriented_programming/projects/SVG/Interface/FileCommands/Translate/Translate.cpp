#include <iostream>
using namespace std;

#include "Translate.h"

Translate::Translate(const string &line) : Command(line) {}

bool Translate::execute() {
  if (!Command::fileOpen) {
    cout << "Translate: You don't have opened file." << endl;
    return false;
  }

  if (args.size() == 0) {
    cout << "Translate: no arguments given" << endl;
    return false;
  } else if (args.size() == 1) {
    cout << "Translate: too few arguments (" << args.size() << " < 2)" << endl;
    return false;
  } else if (args.size() != 2 && args.size() != 3) {
    cout << "Translate: too many arguments (" << args.size() << " > 2)" << endl;
    return false;
  } else {
    int dx = 0, dy = 0;

    if (args.size() == 2) {
      if (args[0].find("vertical=") == 0) {
        dx = stoi(args[0].substr(9, args[0].length() - 9));
      } else if (args[0].find("horizontal=") == 0) {
        cout << args[0].substr(11, args[0].length() - 11);
        dy = stoi(args[0].substr(11, args[0].length() - 11));
      } else {
        cout << "Translate: invalid argument " << args[0] << endl;
        return false;
      }

      if (args[1].find("vertical=") == 0) {
        dx = stoi(args[1].substr(9, args[1].length() - 9));
      } else if (args[1].find("horizontal=") == 0) {
        dy = stoi(args[1].substr(11, args[1].length() - 11));
      } else {
        cout << "Translate: invalid argument " << args[1] << endl;
        return false;
      }

      Command::file.translateShape(-1, dx, dy);
    } else {
      int index = stoi(args[0]);

      if (args[1].find("vertical=") == 0) {
        dx = stoi(args[1].substr(9, args[1].length() - 9));
      } else if (args[1].find("horizontal=") == 0) {
        cout << args[1].substr(11, args[1].length() - 11);
        dy = stoi(args[1].substr(11, args[1].length() - 11));
      } else {
        cout << "Translate: invalid argument " << args[1] << endl;
        return false;
      }

      if (args[2].find("vertical=") == 0) {
        dx = stoi(args[2].substr(9, args[2].length() - 9));
      } else if (args[2].find("horizontal=") == 0) {
        dy = stoi(args[2].substr(11, args[2].length() - 11));
      } else {
        cout << "Translate: invalid argument " << args[2] << endl;
        return false;
      }

      Command::file.translateShape(index, dx, dy);
    }

    return true;
  }
}
