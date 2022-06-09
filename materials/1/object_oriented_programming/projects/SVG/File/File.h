#ifndef __FILE_H__
#define __FILE_H__

#include <string>
#include <vector>
using namespace std;

#include "../Shapes/Shapes.h"

class File {
private:
  string path;
  vector<Shape *> shapes;

  void copy(const File &other);
  void free();

public:
  // constructor
  File(string path = "");

  // copy constructor
  File(const File &other);

  // destructor
  ~File();

  // copy assignment
  File &operator=(const File &other);

  string getPath() const;
  vector<Shape *> getShapes() const;

  // add shape
  void addShape(Shape *shape);

  // remove shape
  void removeShape(int index);

  // translate shape
  void translateShape(int index, int dx, int dy);

  // print shapes within shape
  void withinShape(Shape *shape) const;

  // print all shapes
  void print() const;

  void load();
  void save(string path = "");
};

#endif // __FILE_H__