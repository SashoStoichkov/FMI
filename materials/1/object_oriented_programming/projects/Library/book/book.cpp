#include <fstream>
#include <iostream>
using namespace std;

#include "../myString/string.h"
#include "book.h"

Book::Book(String author, String title, String contentFileName,
           String description, int rating, ISBN isbn)
    : author(author), title(title), contentFileName(contentFileName),
      description(description), rating(rating), isbn(isbn) {}

bool Book::operator==(const Book &book) const {
  return this->isbn == book.isbn;
}

void Book::print() {
  cout << "Book information:" << endl;
  cout << "Title: " << this->title << endl;
  cout << "Author: " << this->author << endl;
  cout << "ISBN: " << this->isbn.getStr() << endl;
  cout << "Short description: " << this->description << endl;
  cout << "Rating: " << this->rating << endl;
}

void Book::printShort() {
  cout << "- " << this->title << ", " << this->author << ", "
       << this->isbn.getStr() << endl;
}

void Book::printContent() {
  // read content file and print it
  String fileDestination = "books-db/";
  fileDestination.append(this->contentFileName);
  fileDestination.append(".txt");

  ifstream file(fileDestination.getStr());

  if (!file.is_open()) {
    cout << "Error opening file" << endl;
    return;
  } else {
    cout << file.rdbuf();
    cout << endl;
  }

  file.close();
}

String Book::getAuthor() { return this->author; }

String Book::getTitle() { return this->title; }

String Book::getContentFileName() { return this->contentFileName; }

String Book::getDescription() { return this->description; }

int Book::getRating() { return this->rating; }

ISBN Book::getISBN() { return this->isbn; }

String Book::getAttribute(String attribute) {
  if (attribute == "a") {
    return this->author;
  } else if (attribute == "t") {
    return this->title;
  } else if (attribute == "r") {
    char rating[2];
    rating[0] = this->rating + '0';
    rating[1] = '\0';

    return String(rating);
  } else if (attribute == "i") {
    return this->isbn.getStr();
  } else if (attribute == "d") {
    return this->description;
  } else {
    return "";
  }
}