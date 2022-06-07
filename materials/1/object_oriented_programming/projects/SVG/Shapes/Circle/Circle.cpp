#include <iostream>
using namespace std;

#include "Circle.h"

Circle::Circle(int cx, int cy, unsigned int r, string fill)
    : Shape("circle"), cx(cx), cy(cy), r(r) {

  for (auto &color : Shape::availableColors) {
    if (color == fill) {
      this->fill = color;
      break;
    }
  }

  if (this->fill.empty()) {
    cout << "Color " << fill << " is not available. Generating random color."
         << endl;

    srand(time(NULL));

    this->fill = Shape::availableColors[rand() % Shape::availableColors.size()];
  }
}

void Circle::translate(int dx, int dy) {
  cx += dx;
  cy += dy;
}

void Circle::print() const {
  cout << "circle " << cx << " " << cy << " " << r << " " << fill << endl;
}

ostream &operator<<(ostream &os, const Circle &circle) {
  os << "<" << circle.name << " cx=\"" << circle.cx << "\" cy=\"" << circle.cy
     << "\" r=\"" << circle.r << "\" fill=\"" << circle.fill << "\" />" << endl;
  return os;
}
