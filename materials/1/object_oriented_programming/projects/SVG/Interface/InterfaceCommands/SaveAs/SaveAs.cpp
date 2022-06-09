#include <iostream>
using namespace std;

#include "SaveAs.h"

SaveAs::SaveAs(const string &line) : Command(line) {}

bool SaveAs::execute() {
  if (!Command::fileOpen) {
    cout << "You don't have opened file." << endl;
    return false;
  }

  if (args.size() == 0) {
    cout << "SaveAs: no file name given" << endl;
    return false;
  } else if (args.size() > 1) {
    cout << "SaveAs: too many arguments (" << args.size() << " > 1)" << endl;
    return false;
  } else if (!Command::checkExtension(args[0], "svg")){
    cout << "SaveAs: file extension is not .svg" << endl;
    return false;
  } else {
    cout << "SaveAs: saving file " << args[0] << endl;

    Command::file.save(args[0]);

    return true;
  }
}
