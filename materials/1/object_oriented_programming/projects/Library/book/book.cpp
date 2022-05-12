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

void Book::printShort() {
  cout << this->title << ", " << this->author << ", " << this->isbn.getISBN()
       << endl;
}

String Book::getAuthor() { return this->author; }

String Book::getTitle() { return this->title; }

String Book::getContentFileName() { return this->contentFileName; }

String Book::getShortDescription() { return this->shortDescription; }

int Book::getRating() { return this->rating; }

ISBN Book::getISBN() { return this->isbn; }

String Book::getAttribute(String attribute) {
  if (attribute == "a") {
    return this->author;
  } else if (attribute == "t") {
    return this->title;
  } else if (attribute == "r") {
    char rating[2];
    rating[0] = this->rating / 10 + '0';
    rating[1] = '\0';

    return String(rating);
  } else {
    return "";
  }
}