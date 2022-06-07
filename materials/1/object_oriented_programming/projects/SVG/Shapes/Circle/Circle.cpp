#include <cmath>
#include <iostream>
using namespace std;

#include "../Rectangle/Rectangle.h"
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

bool Circle::isWithin(Shape *shape) const {
  if (shape->getName() == "circle") {
    Circle *circle = static_cast<Circle *>(shape);
    return (r + circle->r) >
           sqrt(pow(cx - circle->cx, 2) + pow(cy - circle->cy, 2));
  } else if (shape->getName() == "rect") {
    Rectangle *rectangle = static_cast<Rectangle *>(shape);
    return (cx - r) > rectangle->getX() &&
           (cx + r) < (rectangle->getX() + rectangle->getWidth()) &&
           (cy - r) > rectangle->getY() &&
           (cy + r) < (rectangle->getY() + rectangle->getHeight());
  } else {
    return false;
  }
}

int Circle::getCx() const { return cx; }

int Circle::getCy() const { return cy; }

unsigned int Circle::getR() const { return r; }

ostream &operator<<(ostream &os, const Circle &circle) {
  os << "<" << circle.name << " cx=\"" << circle.cx << "\" cy=\"" << circle.cy
     << "\" r=\"" << circle.r << "\" fill=\"" << circle.fill << "\" />" << endl;
  return os;
}
