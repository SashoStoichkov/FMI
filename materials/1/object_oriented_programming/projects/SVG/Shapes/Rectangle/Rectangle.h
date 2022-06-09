#ifndef __RECTANGLE_H__
#define __RECTANGLE_H__

#include "../Shape/Shape.h"

class Rectangle : public Shape {
private:
  int x;
  int y;
  unsigned int width;
  unsigned int height;
  string fill;

public:
  // constructor
  Rectangle(int x = 0, int y = 0, unsigned int width = 0,
            unsigned int height = 0, string fill = "");

  // operator<<
  friend ostream &operator<<(ostream &os, const Rectangle &rectangle);

  string toString() const;
  void translate(int dx, int dy);
  void print() const;
  bool isWithin(Shape *shape) const;

  int getX() const;
  int getY() const;
  unsigned int getWidth() const;
  unsigned int getHeight() const;
};

#endif // __RECTANGLE_H__