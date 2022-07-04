#ifndef __VECTOR_H__
#define __VECTOR_H__

template <typename T> class Vector {
private:
  // attributes
  int size;
  int capacity;
  T *data;

  void copy(const Vector &other);
  void free();

public:
  // constructor
  Vector(int capacity = 0, int size = 0, T *data = nullptr);

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

  T get(int index) const;
  T getFirst() const;
  T getLast() const;

  void assign(int size, T value);

  void pushBack(T value);
  void popBack();

  void remove(int index);
};

#endif // __VECTOR_H__