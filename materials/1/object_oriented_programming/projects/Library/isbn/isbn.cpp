#include <cstring>
#include <iostream>

using namespace std;

#include "../myString/string.h"
#include "isbn.h"

bool ISBN::isValid(String isbn) {
  int sum = 0;

  for (int i = 0; i < isbn.length(); i++) {
    if (isbn[i] == '-') {
      continue;
    } else {
      sum += (isbn[i] - '0') * (i + 1);
    }
  }

  return sum % 11 == 0;
}

ISBN::ISBN(String isbn) {
  this->isbn = isbn;

  // check if the isbn is valid
  if (!this->isValid(this->isbn)) {
    throw "Invalid ISBN";
  }
}

bool ISBN::operator==(const ISBN &isbn) const {
  return this->isbn == isbn.isbn;
}