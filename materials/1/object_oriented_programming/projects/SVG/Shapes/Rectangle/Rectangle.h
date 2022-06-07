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

  void translate(int dx, int dy);
  void print() const;
};

#endif // __RECTANGLE_H__