#include <iostream>

using namespace std;

#include "../myString/string.h"
#include "book.h"

Book::Book(String author, String title, String contentFileName,
           String shortDescription, int rating, ISBN isbn)
    : author(author), title(title), contentFileName(contentFileName),
      shortDescription(shortDescription), rating(rating), isbn(isbn) {}

bool Book::operator==(const Book &book) const {
  return this->isbn == book.isbn;
}