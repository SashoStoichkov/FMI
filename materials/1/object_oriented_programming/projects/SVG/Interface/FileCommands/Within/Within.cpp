#include <iostream>
using namespace std;

#include "Within.h"

Within::Within(const string &line) : Command(line) {}

bool Within::execute() {
  if (!Command::fileOpen) {
    cout << "Within: You don't have opened file." << endl;
    return false;
  }

  if (args.size() == 0) {
    cout << "Within: You don't specify type of shape." << endl;
    return false;
  } else {
    if (args[0] == "rectangle") {
      if (args.size() != 5 && args.size() != 6) {
        cout << "Within: You don't specify all arguments." << endl;
        return false;
      } else {
        int x = stoi(args[1]);
        int y = stoi(args[2]);
        int width = stoi(args[3]);
        int height = stoi(args[4]);

        if (width < 0 || height < 0) {
          cout << "Within: Width and height must be positive." << endl;
          return false;
        } else {
          if (args.size() == 5) {
            Command::file.withinShape(new Rectangle(x, y, width, height));
          } else {
            string fill = args[5];
            Command::file.withinShape(new Rectangle(x, y, width, height, fill));
          }

          cout << "Within: Successfully created rectangle ("
               << Command::file.getShapes().size() << ")" << endl;

          return true;
        }
      }
    } else if (args[0] == "circle") {
      if (args.size() != 4 && args.size() != 5) {
        cout << "Within: You don't specify all arguments." << endl;
        return false;
      } else {
        int x = stoi(args[1]);
        int y = stoi(args[2]);
        int radius = stoi(args[3]);

        if (radius < 0) {
          cout << "Within: Radius must be positive." << endl;
          return false;
        } else {
          if (args.size() == 4) {
            Command::file.withinShape(new Circle(x, y, radius));
          } else {
            string fill = args[4];
            Command::file.withinShape(new Circle(x, y, radius, fill));
          }

          cout << "Within: Successfully created circle ("
               << Command::file.getShapes().size() << ")" << endl;

          return true;
        }
      }
    } else {
      cout << "Within: Wrong type of shape " << args[0]
           << " is not rectangle or circle." << endl;
      return false;
    }
  }
}