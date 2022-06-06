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

  print();

  if (args.size() == 0) {
    cout << "Open: no file name given" << endl;
    return false;
  } else if (args.size() > 1) {
    cout << "Open: too many arguments (" << args.size() << " > 1)" << endl;
    return false;
  } else {
    cout << "Open: opening file " << args[0] << endl;

    // open file
    fstream oFile(args[0], ios::out);

    // check if file is empty
    if (oFile.peek() == ifstream::traits_type::eof()) {
      cout << "Open: file " << args[0] << " doesn't exist, creating it" << endl;

      fstream iFile(args[0], ios::in);

      iFile << "<?xml version=\"1.0\" standalone=\"no\"?>" << endl;
      iFile << "<!DOCTYPE svg PUBLIC \"-//W3C//DTD SVG 1.1//EN\" "
              "\"http://www.w3.org/Graphics/SVG/1.1/DTD/svg11.dtd\">"
           << endl;
      iFile << "<svg></svg>" << endl;

      iFile.close();
    }

    // close file
    oFile.close();

    Command::fileOpen = true;
    Command::prompt = "> " + args[0] + " > ";

    return true;
  }
}
