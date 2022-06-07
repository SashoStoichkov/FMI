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

  void translate(int dx, int dy);
  void print() const;
};

#endif // __LINE_H__