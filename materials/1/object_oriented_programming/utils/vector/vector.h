#ifndef __VECTOR_H__
#define __VECTOR_H__

class Vector {
private:
  // attributes
  int size;
  int capacity;
  int *data;

  void copy(const Vector &other);
  void free();

public:
  // constructor
  Vector(int capacity = 0, int size = 0, int *data = nullptr);

  // copy constructor
  Vector(const Vector &other);

  // move constructor
  Vector(Vector &&other);

  // destructor
  ~Vector();

  // copy assignment
  Vector &operator=(const Vector &other);

  // move assignment
  Vector &operator=(Vector &&other);

  // other methods
  int getSize() const;
  int getCapacity() const;

  bool isEmpty() const;

  int get(int index) const;
  int getFirst() const;
  int getLast() const;

  void assign(int size, int value);

  void pushBack(int value);
  void popBack();

  void remove(int index);
};

#endif // __VECTOR_H__