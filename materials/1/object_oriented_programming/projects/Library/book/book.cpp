#include <cstring>
#include <iostream>

using namespace std;

#include "../myString/string.h"
#include "book.h"

Book::Book(String author, String title, String contentFileName,
           String shortDescription, int rating, String isbn) {
  this->author = author;
  this->title = title;
  this->contentFileName = contentFileName;
  this->shortDescription = shortDescription;
  this->rating = rating;

  try {
    this->isbn = ISBN(isbn);
  } catch (const char *msg) {
    cout << msg << endl;
    exit(1);
  }
}

bool Book::operator==(const Book &book) const {
  return this->isbn == book.isbn;
}