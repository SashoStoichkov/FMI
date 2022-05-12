#include <cstring>
#include <iostream>

using namespace std;

#include "../myString/string.h"
#include "isbn.h"

// Source: https://www.geeksforgeeks.org/program-check-isbn/
bool ISBN::isValid(String isbn) {
  if (isbn.length() != 10) {
    return false;
  } else {
    int sum = 0;

    for (int i = 0; i < 9; i++) {
      char digit = isbn[i];

      if (digit < '0' || digit > '9') {
        return false;
      } else {
        sum += (digit - '0') * (10 - i);
      }
    }

    char last = isbn[9];
    if (last != 'X' && (last < '0' || last > '9')) {
      return false;
    } else {
      sum += ((last == 'X') ? 10 : (last - '0'));
    }

    return sum % 11 == 0;
  }
}

ISBN::ISBN(String isbn) {
  if (this->isValid(isbn)) {
    this->isbn = isbn;
  } else {
    throw ISBNNotValidException();
  }
}

String ISBN::getISBN() { return this->isbn; }

bool ISBN::operator==(const ISBN &isbn) const {
  return this->isbn == isbn.isbn;
}