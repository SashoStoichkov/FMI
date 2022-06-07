#include <iostream>
using namespace std;

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

void Rectangle::translate(int dx, int dy) {
  x += dx;
  y += dy;
}

void Rectangle::print() const {
  cout << "rectangle " << x << " " << y << " " << width << " " << height << " "
       << fill << endl;
}

ostream &operator<<(ostream &os, const Rectangle &rectangle) {
  os << "<" << rectangle.name << " x=\"" << rectangle.x << "\" y=\""
     << rectangle.y << "\" width=\"" << rectangle.width << "\" height=\""
     << rectangle.height << "\" fill=\"" << rectangle.fill << "\" />" << endl;
  return os;
}
