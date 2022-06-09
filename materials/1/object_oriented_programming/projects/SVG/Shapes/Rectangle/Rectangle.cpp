#include <iostream>
using namespace std;

#include "../Circle/Circle.h"
#include "Rectangle.h"

Rectangle::Rectangle(int x, int y, unsigned int width, unsigned int height,
                     string fill)
    : Shape("rect"), x(x), y(y), width(width), height(height) {

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

string Rectangle::toString() const {
  return "<rect x=\"" + to_string(this->x) + "\" y=\"" + to_string(this->y) +
         "\" width=\"" + to_string(this->width) + "\" height=\"" +
         to_string(this->height) + "\" fill=\"" + this->fill + "\" />";
}

void Rectangle::translate(int dx, int dy) {
  x += dx;
  y += dy;
}

void Rectangle::print() const {
  cout << "rectangle " << x << " " << y << " " << width << " " << height << " "
       << fill << endl;
}

bool Rectangle::isWithin(Shape *shape) const {
  if (shape->getName() == "rect") {
    Rectangle *rect = static_cast<Rectangle *>(shape);
    return x >= rect->x && x <= rect->x + rect->width && y >= rect->y &&
           y <= rect->y + rect->height;
  } else if (shape->getName() == "circle") {
    Circle *circle = static_cast<Circle *>(shape);
    return x >= circle->getCx() - circle->getR() &&
           x <= circle->getCx() + circle->getR() &&
           y >= circle->getCy() - circle->getR() &&
           y <= circle->getCy() + circle->getR();
  } else {
    return false;
  }
}

int Rectangle::getX() const { return x; }

int Rectangle::getY() const { return y; }

unsigned int Rectangle::getWidth() const { return width; }

unsigned int Rectangle::getHeight() const { return height; }

ostream &operator<<(ostream &os, const Rectangle &rectangle) {
  os << "<" << rectangle.name << " x=\"" << rectangle.x << "\" y=\""
     << rectangle.y << "\" width=\"" << rectangle.width << "\" height=\""
     << rectangle.height << "\" fill=\"" << rectangle.fill << "\" />" << endl;
  return os;
}
