#include <iostream>
#include "dynamicArray.hpp"

using namespace std;

int main() {
  // dynamically allocated array which can be resized
  int *array{nullptr};

  // capacity of the array
  size_t capacity = 3;

  // exact number of elements in the array
  size_t size = 0;

  allocateMemory(array, capacity);

  addElement(array, size, capacity, 1);
  addElement(array, size, capacity, 2);
  addElement(array, size, capacity, 3);

  cout << "The capacity of the array is " << capacity << endl;
  cout << "The real count of the elements in the array is " << size << endl;
  print(array, size, capacity);

  addElement(array, size, capacity, 4);

  cout << "\nThe capacity of the array is " << capacity << endl;
  cout << "The real count of the elements in the array is " << size << endl;
  print(array, size, capacity);

  removeElement(array, size, capacity, 0);
  removeElement(array, size, capacity, 0);
  removeElement(array, size, capacity, 0);

  cout << "\nThe capacity of the array is " << capacity << endl;
  cout << "The real count of the elements in the array is " << size << endl;

  print(array, size, capacity);

  freeMemory(array, size, capacity);
}