#ifndef __SHAPE_H__
#define __SHAPE_H__

#include <string>
#include <vector>
using namespace std;

class Shape {
protected:
  string name;
  static vector<string> availableColors;

private:
  void copy(const Shape &other);
  void free();

public:
  // constructor
  Shape(string name = "");

  // copy constructor
  Shape(const Shape &other);

  // destructor
  ~Shape();

  // copy assignment
  Shape &operator=(const Shape &other);

  // operator<<
  friend ostream &operator<<(ostream &os, const Shape &shape);

  string getName() const;

  virtual void translate(int dx, int dy) = 0;
  virtual void print() const = 0;
};

#endif // __SHAPE_H__