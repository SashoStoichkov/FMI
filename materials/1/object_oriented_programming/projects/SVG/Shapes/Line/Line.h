#ifndef __LINE_H__
#define __LINE_H__

#include "../Shape/Shape.h"

class Line : public Shape {
private:
  int x1;
  int y1;
  int x2;
  int y2;
  string stroke;

public:
  // constructor
  Line(int x1 = 0, int y1 = 0, int x2 = 0, int y2 = 0, string stroke = "");

  // operator<<
  friend ostream &operator<<(ostream &os, const Line &line);

  // getters
  int getX1() const;
  int getY1() const;
  int getX2() const;
  int getY2() const;
  string getStroke() const;

  string toString() const;
  void translate(int dx, int dy);
  void print() const;
  bool isWithin(Shape *shape) const;
};

#endif // __LINE_H__