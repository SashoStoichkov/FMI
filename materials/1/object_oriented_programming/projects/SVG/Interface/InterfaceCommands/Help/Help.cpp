#include <iostream>
using namespace std;

#include "Help.h"

Help::Help(const string &line) : Command(line) {}

bool Help::execute() {
  if (args.size() != 0) {
    cout << "Help: too many arguments (" << args.size() << " > 0)" << endl;
    return false;
  } else {
    cout << "The following commands are supported:" << endl;
    cout << "- open <file> \t opens <file>" << endl;
    cout << "- close \t closes currently opened file" << endl;
    cout << "- save \t\t saves the currently open file" << endl;
    cout << "- saveas <file>  saves the currently open file in <file>" << endl;
    cout << "- help \t\t prints this information" << endl;
    cout << "- exit \t\t exits the program" << endl;

    cout << endl;

    cout << "### Commands that require an opened file ###" << endl;
    cout << "- create <shape> \t creates a new shape" << endl;
    cout << "- erase <shapeid> \t erases the shape with id <shapeid>" << endl;
    cout << "- print \t\t prints all shapes from the currently open file"
         << endl;
    cout << "- translate [<shapeid>]  translates the shape with id [<shapeid>]"
         << endl;
    cout << "- within <shape> \t prints all shapes that are within the shape"
         << endl;

    cout << endl;

    cout << "### Shapes ###" << endl;
    cout << "- circle \t cx cy r [fill]" << endl;
    cout << "- rectangle \t x1 y1 width height [fill]" << endl;
    cout << "- line \t\t x1 y1 x2 y2 [stroke]" << endl;

    return true;
  }
}