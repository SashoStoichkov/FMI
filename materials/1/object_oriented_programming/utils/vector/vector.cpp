#include <iostream>
using namespace std;

#include "vector.h"

void Vector::copy(const Vector &other) {
  size = other.size;
  capacity = other.capacity;
  data = new int[capacity];

  for (int i = 0; i < size; i++) {
    data[i] = other.data[i];
  }
}

void Vector::free() { delete[] data; }

Vector::Vector(int capacity, int size, int *data) {
  this->size = size;
  this->capacity = capacity;
  this->data = new int[capacity];

  for (int i = 0; i < size; i++) {
    this->data[i] = data[i];
  }
}

Vector::Vector(const Vector &other) { copy(other); }

Vector::Vector(Vector &&other) {
  // move other's attributes to this
  size = move(other.size);
  capacity = move(other.capacity);
  data = move(other.data);

  // free other
  other.free();
}

Vector::~Vector() { free(); }

Vector &Vector::operator=(const Vector &other) {
  if (this != &other) {
    free();
    copy(other);
  }
  return *this;
}

Vector &Vector::operator=(Vector &&other) {
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

int Vector::getSize() const { return size; }

int Vector::getCapacity() const { return capacity; }

bool Vector::isEmpty() const { return size == 0; }

int Vector::get(int index) const {
  if (index < 0 || index >= size) {
    throw "Index out of bounds";
  }

  return data[index];
}

int Vector::getFirst() const {
  if (isEmpty()) {
    throw "Vector is empty";
  }

  return data[0];
}

int Vector::getLast() const {
  if (isEmpty()) {
    throw "Vector is empty";
  }

  return data[size - 1];
}

void Vector::assign(int size, int value) {
  this->size = size;
  for (int i = 0; i < size; i++) {
    data[i] = value;
  }
}

void Vector::pushBack(int value) {
  if (size == capacity) {
    int newCapacity = capacity == 0 ? 1 : capacity * 2;
    int *newData = new int[newCapacity];

    for (int i = 0; i < size; i++) {
      newData[i] = data[i];
    }

    free();

    data = newData;
    capacity = newCapacity;
  }

  data[size++] = value;
}

void Vector::popBack() {
  if (isEmpty()) {
    throw "Vector is empty";
  }

  size--;
}

void Vector::remove(int index) {
  if (index < 0 || index >= size) {
    throw "Index out of bounds";
  }

  for (int i = index; i < size - 1; i++) {
    data[i] = data[i + 1];
  }

  size--;
}