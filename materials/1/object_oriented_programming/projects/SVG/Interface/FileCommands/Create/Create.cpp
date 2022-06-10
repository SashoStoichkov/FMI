#include <iostream>
using namespace std;

#include "Create.h"

Create::Create(const string &line) : Command(line) {}

bool Create::execute() {
  if (!Command::fileOpen) {
    cout << "Create: You don't have opened file." << endl;
    return false;
  }

  if (args.size() == 0) {
    cout << "Create: You don't specify type of shape." << endl;
    return false;
  } else {
    if (args[0] == "rectangle") {
      if (args.size() != 5 && args.size() != 6) {
        cout << "Create: You don't specify all arguments." << endl;
        return false;
      } else {
        int x = stoi(args[1]);
        int y = stoi(args[2]);
        int width = stoi(args[3]);
        int height = stoi(args[4]);

        if (width < 0 || height < 0) {
          cout << "Create: Width and height must be positive." << endl;
          return false;
        } else {
          if (args.size() == 5) {
            Command::file.addShape(new Rectangle(x, y, width, height));
          } else {
            string fill = args[5];
            Command::file.addShape(new Rectangle(x, y, width, height, fill));
          }

          cout << "Create: Successfully created rectangle ("
               << Command::file.getShapes().size() << ")" << endl;

          return true;
        }
      }
    } else if (args[0] == "circle") {
      if (args.size() != 4 && args.size() != 5) {
        cout << "Create: You don't specify all arguments." << endl;
        return false;
      } else {
        int x = stoi(args[1]);
        int y = stoi(args[2]);
        int radius = stoi(args[3]);

        if (radius < 0) {
          cout << "Create: Radius must be positive." << endl;
          return false;
        } else {
          if (args.size() == 4) {
            Command::file.addShape(new Circle(x, y, radius));
          } else {
            string fill = args[4];
            Command::file.addShape(new Circle(x, y, radius, fill));
          }

          cout << "Create: Successfully created circle ("
               << Command::file.getShapes().size() << ")" << endl;

          return true;
        }
      }
    } else if (args[0] == "line") {
      if (args.size() != 5 && args.size() != 6) {
        cout << "Create: You don't specify all arguments." << endl;
        return false;
      } else {
        int x1 = stoi(args[1]);
        int y1 = stoi(args[2]);
        int x2 = stoi(args[3]);
        int y2 = stoi(args[4]);

        if (args.size() == 5) {
          Command::file.addShape(new Line(x1, y1, x2, y2));
        } else {
          string stroke = args[5];
          Command::file.addShape(new Line(x1, y1, x2, y2, stroke));
        }

        cout << "Create: Successfully created line ("
               << Command::file.getShapes().size() << ")" << endl;

        return true;
      }
    } else {
      cout << "Create: Wrong type of shape." << endl;
      return false;
    }
  }
}
