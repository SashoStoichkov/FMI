#include <cstring>
#include <iostream>
using namespace std;

#include "naturalNumbers.h"

bool NaturalNumbers::isNumberInSet(int number) {
  for (int i = 0; i < this->size; i++) {
    if (this->numbers[i] == number) {
      return true;
    }
  }

  return false;
}

// bool NaturalNumbers::operator[](int number) {
//   for (int i = 0; i < size; i++) {
//     if (numbers[i] == number) {
//       return true;
//     }
//   }

//   return false;
// }

NaturalNumbers::NaturalNumbers(char *name, int size, int *numbers) {
  int nameSize = strlen(name) + 1;
  this->name = new char[nameSize];
  strcpy(this->name, name);
  this->name[nameSize] = '\0';

  int setSize = size;
  this->size = size;

  this->numbers = new int[size]{-1};
  for (int i = 0; i < size; i++) {
    if (!this->isNumberInSet(numbers[i])) {
      this->numbers[i] = numbers[i];
    } else {
      cout << "Identical element is found!" << endl;
      setSize--;
    }
  }

  this->size = setSize;

  // print info for debugging
  // cout << this->name << " - " << this->size << " - {";
  // for (int i = 0; i < this->size; i++) {
  //   cout << this->numbers[i];
  // }
  // cout << "}" << endl;
}

NaturalNumbers::~NaturalNumbers() {
  delete[] name;
  size = 0;
  delete[] numbers;
}

char *NaturalNumbers::getName() const { return this->name; }

int NaturalNumbers::getSize() const { return this->size; }

int *NaturalNumbers::getNumbers() const { return this->numbers; }

// NaturalNumbers &NaturalNumbers::operator+(NaturalNumbers n) {
//   int newNameSize = strlen("Union of '") + strlen(this->name) + strlen("' and
//   '") +
//                  strlen(n.getName()) + strlen("'") + 1;

//   char *newName = new char[newNameSize];
//   strcat(newName, "Union of '");
//   strcat(newName, this->name);
//   strcat(newName, "' and '");
//   strcat(newName, n.getName());
//   strcat(newName, "'\0");

//   int newSize = this->size + n.getSize();
//   int setSize = newSize;

//   int *newNumbers = new int[newSize];
//   for (int i = 0; i < this->size; i++) {
//     newNumbers[i] = this->numbers[i];
//   }

//   for (int i = this->size + 1; i < newSize; i++) {
//     if (!this->isNumberInSet(n.getNumbers()[i])) {
//       newNumbers[i] = n.getNumbers()[i];
//     } else {
//       cout << "Identical element is found!" << endl;
//       setSize--;
//     }
//   }

//   newSize = setSize;

//  закоментирано е, защото този return не работи
//   return NaturalNumbers(newName, newSize, newNumbers);
// }

NaturalNumbers &NaturalNumbers::operator+=(NaturalNumbers n) {
  int newNameSize = strlen("Union of '") + strlen(this->name) +
                    strlen("' and '") + strlen(n.getName()) + strlen("'") + 1;

  delete[] this->name;
  this->name = new char[newNameSize];

  char *newName = new char[newNameSize];
  strcat(newName, "Union of '");
  strcat(newName, this->name);
  strcat(newName, "' and '");
  strcat(newName, n.getName());
  strcat(newName, "'\0");

  strcpy(this->name, newName);

  int newSize = this->size + n.getSize();
  int setSize = newSize;

  int *newNumbers = new int[this->size];
  for (int i = 0; i < this->size; i++) {
    newNumbers[i] = this->numbers[i];
  }

  delete[] this->numbers;
  this->numbers = new int[newSize];

  for (int i = 0; i < this->size; i++) {
    this->numbers[i] = newNumbers[i];
  }

  delete[] newNumbers;

  for (int i = this->size + 1; i < newSize; i++) {
    if (!this->isNumberInSet(n.getNumbers()[i])) {
      this->numbers[i] = n.getNumbers()[i];
    } else {
      cout << "Identical element is found!" << endl;
      setSize--;
    }
  }

  this->size = setSize;

  return *this;
}