#ifndef __CIRCLE_H__
#define __CIRCLE_H__

#include "../Shape/Shape.h"

class Circle : public Shape {
private:
  int cx;
  int cy;
  unsigned int r;
  string fill;

public:
  // constructor
  Circle(int cx = 0, int cy = 0, unsigned int r = 0, string fill = "");

  // operator<<
  friend ostream &operator<<(ostream &os, const Circle &circle);

  string toString() const;
  void translate(int dx, int dy);
  void print() const;
  bool isWithin(Shape *shape) const;

  int getCx() const;
  int getCy() const;
  unsigned int getR() const;
};

#endif // __CIRCLE_H__