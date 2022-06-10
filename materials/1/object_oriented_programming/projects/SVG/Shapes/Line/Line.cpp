#include <iostream>
using namespace std;

#include "Line.h"

#include "../Circle/Circle.h"
#include "../Rectangle/Rectangle.h"

Line::Line(int x1, int y1, int x2, int y2, string stroke)
    : Shape("line"), x1(x1), y1(y1), x2(x2), y2(y2) {

  for (auto &color : Shape::availableColors) {
    if (color == stroke) {
      this->stroke = color;
      return;
    }
  }

  cout << "Generating random color." << endl;
  srand(time(NULL));
  this->stroke = Shape::availableColors[rand() % Shape::availableColors.size()];
}

int Line::getX1() const { return this->x1; }

int Line::getY1() const { return this->y1; }

int Line::getX2() const { return this->x2; }

int Line::getY2() const { return this->y2; }

string Line::getStroke() const { return this->stroke; }

string Line::toString() const {
  return "<line x1=\"" + to_string(this->x1) + "\" y1=\"" +
         to_string(this->y1) + "\" x2=\"" + to_string(this->x2) + "\" y2=\"" +
         to_string(this->y2) + "\" stroke=\"" + this->stroke + "\" />";
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

bool Line::isWithin(Shape *shape) const {
  if (shape->getName() == "circle") {
    Circle *circle = static_cast<Circle *>(shape);
    return (abs(x1 - circle->getCx()) <= circle->getR() &&
            abs(y1 - circle->getCy()) <= circle->getR() &&
            abs(x2 - circle->getCx()) <= circle->getR() &&
            abs(y2 - circle->getCy()) <= circle->getR());
  } else if (shape->getName() == "rect") {
    Rectangle *rectangle = static_cast<Rectangle *>(shape);
    return (x1 >= rectangle->getX() &&
            x1 <= rectangle->getX() + rectangle->getWidth() &&
            y1 >= rectangle->getY() &&
            y1 <= rectangle->getY() + rectangle->getHeight() &&
            x2 >= rectangle->getX() &&
            x2 <= rectangle->getX() + rectangle->getWidth() &&
            y2 >= rectangle->getY() &&
            y2 <= rectangle->getY() + rectangle->getHeight());
  } else {
    return false;
  }
}

ostream &operator<<(ostream &os, const Line &line) {
  os << "<" << line.name << " x1=\"" << line.x1 << "\" y1=\"" << line.y1
     << "\" x2=\"" << line.x2 << "\" y2=\"" << line.y2 << "\" stroke=\""
     << line.stroke << "\" />" << endl;
  return os;
}
