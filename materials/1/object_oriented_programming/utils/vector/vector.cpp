#include <iostream>
using namespace std;

#include "vector.h"

template <typename T>
void Vector<T>::copy(const Vector<T> &other) {
  size = other.size;
  capacity = other.capacity;
  data = new T[capacity];

  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
}

template <typename T>
void Vector<T>::free() { delete[] data; }

template <typename T>
Vector<T>::Vector(int capacity, int size, T *data) {
  this->size = size;
  this->capacity = capacity;
  this->data = new T[capacity];

  for (int i = 0; i < size; i++) {
    this->data[i] = data[i];
  }
}

template <typename T>
Vector<T>::Vector(const Vector<T> &other) { copy(other); }

template <typename T>
Vector<T>::Vector(Vector<T> &&other) {
  // move other's attributes to this
  size = move(other.size);
  capacity = move(other.capacity);
  data = move(other.data);

  // free other
  other.free();
}

template <typename T>
Vector<T>::~Vector() { free(); }

template <typename T>
Vector<T> &Vector<T>::operator=(const Vector<T> &other) {
  if (this != &other) {
    free();
    copy(other);
  }
  return *this;
}

template <typename T>
Vector<T> &Vector<T>::operator=(Vector<T> &&other) {
  if (this != &other) {
    free();
    // move other's attributes to this
    size = move(other.size);
    capacity = move(other.capacity);
    data = move(other.data);

    // free other
    other.free();
  }
  return *this;
}

template <typename T>
int Vector<T>::getSize() const { return size; }

template <typename T>
int Vector<T>::getCapacity() const { return capacity; }

template <typename T>
bool Vector<T>::isEmpty() const { return size == 0; }

template <typename T>
T Vector<T>::get(int index) const {
  if (index < 0 || index >= size) {
    throw "Index out of bounds";
  }

  return data[index];
}

template <typename T>
T Vector<T>::getFirst() const {
  if (isEmpty()) {
    throw "Vector<T> is empty";
  }

  return data[0];
}

template <typename T>
T Vector<T>::getLast() const {
  if (isEmpty()) {
    throw "Vector<T> is empty";
  }

  return data[size - 1];
}

template <typename T>
void Vector<T>::assign(int size, T value) {
  this->size = size;

  for (int i = 0; i < size; i++) {
    data[i] = value;
  }
}

template <typename T>
void Vector<T>::pushBack(T value) {
  if (size == capacity) {
    int newCapacity = capacity == 0 ? 1 : capacity * 2;
    T *newData = new T[newCapacity];

    for (int i = 0; i < size; i++) {
      newData[i] = data[i];
    }

    free();

    data = newData;
    capacity = newCapacity;
  }

  data[size++] = value;
}

template <typename T>
void Vector<T>::popBack() {
  if (isEmpty()) {
    throw "Vector<T> is empty";
  }

  size--;
}

template <typename T>
void Vector<T>::remove(int index) {
  if (index < 0 || index >= size) {
    throw "Index out of bounds";
  }

  for (int i = index; i < size - 1; i++) {
    data[i] = data[i + 1];
  }

  size--;
}