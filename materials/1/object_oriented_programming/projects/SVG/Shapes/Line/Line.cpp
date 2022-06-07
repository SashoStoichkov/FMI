#include <iostream>
using namespace std;

#include "Line.h"

Line::Line(int x1, int y1, int x2, int y2, string stroke)
    : Shape("line"), x1(x1), y1(y1), x2(x2), y2(y2) {

  for (auto &color : Shape::availableColors) {
    if (color == stroke) {
      this->stroke = color;
      break;
    }
  }

  if (this->stroke.empty()) {
    cout << "Color " << stroke << " is not available. Generating random color."
         << endl;

    srand(time(NULL));

    this->stroke =
        Shape::availableColors[rand() % Shape::availableColors.size()];
  }
}

void Line::translate(int dx, int dy) {
  x1 += dx;
  y1 += dy;
  x2 += dx;
  y2 += dy;
}

void Line::print() const {
  cout << "line " << x1 << " " << y1 << " " << x2 << " " << y2 << " " << stroke
       << endl;
}

ostream &operator<<(ostream &os, const Line &line) {
  os << "<" << line.name << " x1=\"" << line.x1 << "\" y1=\"" << line.y1
     << "\" x2=\"" << line.x2 << "\" y2=\"" << line.y2 << "\" stroke=\""
     << line.stroke << "\" />" << endl;
  return os;
}
