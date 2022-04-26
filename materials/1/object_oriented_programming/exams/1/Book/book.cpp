#include <cstring>
#include <iostream>
using namespace std;

#include "book.h"

Book::Book(const char title[100], const char author[100],
           const unsigned int count) {
  strcpy(this->title, title);
  strcpy(this->author, author);
  this->count = count;
}

void Book::setTitle(const char *title) { strcpy(this->title, title); }

void Book::setAuthor(const char *author) { strcpy(this->author, author); }

void Book::setCount(const unsigned int count) { this->count = count; }

const char *Book::getTitle() const { return title; }

const char *Book::getAuthor() const { return author; }

unsigned int Book::getCount() const { return count; }
