#include <iostream>
#include "dynamicArray.hpp"

using namespace std;

// allocate the memory
void allocateMemory(int *&array, size_t capacity) { array = new int[capacity]; }

// delete the allocated memory
void freeMemory(int *&array, size_t &size, size_t &capacity) {
  delete[] array;
  size = 0;
  capacity = 0;
}

// reallocate memory with different capacity
bool reallocateMemory(int *&array, size_t size, size_t newCapacity) {
  int *newArray = new int[newCapacity];
  if (newArray == nullptr) {
    return false;
  } else {
    for (size_t i = 0; i < size; ++i) {
      newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
    return true;
  }
}

// resize the array, if necessary
// double the size
bool resize(int *&array, size_t size, size_t &capacity) {
  if (size < capacity) {
    return true;
  } else {
    size_t newCapacity = capacity * 2;
    return reallocateMemory(array, size, newCapacity);
  }
}

// add element at the end of the array
// if the size is less than the capacity, the array should be resized
// resize the array, if necessary
bool addElement(int *&array, size_t &size, size_t &capacity, int newElem) {
  if (size > capacity) {
    resize(array, size, capacity);
  }
  array[size] = newElem;
  ++size;
  return true;
}

// add element at a specified position of the array
// resize if necessary
bool addElement(int *&array, size_t &size, size_t &capacity, int newElem,
                size_t position) {
  if (size > capacity) {
    resize(array, size, capacity);
  }
  for (size_t i = size; i > position; --i) {
    array[i] = array[i - 1];
  }
  array[position] = newElem;
  ++size;
  return true;
}

// print the elements of the array
void print(const int *array, size_t size, size_t capacity) {
  for (size_t i = 0; i < size; ++i) {
    cout << array[i] << " ";
  }
  cout << endl;
}

// remove the element at the specified position
// if the number of elements are less than 1/4 of the capacity,
// resize the array, use half of its capacity
bool removeElement(int *&array, size_t &size, size_t &capacity,
                   size_t position) {
  if (size < capacity / 4) {
    size_t newCapacity = capacity / 2;
    return reallocateMemory(array, size, newCapacity);
  } else {
    for (size_t i = position; i < size - 1; ++i) {
      array[i] = array[i + 1];
    }
    --size;
    return true;
  }
}