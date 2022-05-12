#include <iostream>
using namespace std;

#include "library.h"

Library::Library(int numBooks, Book *books) {
  this->numBooks = numBooks;
  this->books = new Book[numBooks];

  for (int i = 0; i < numBooks; i++) {
    this->books[i] = books[i];
  }
}

Library::~Library() { delete[] this->books; }

void Library::addBook(Book book) {
  Book *newBooks = new Book[this->numBooks + 1];

  for (int i = 0; i < this->numBooks; i++) {
    newBooks[i] = this->books[i];
  }

  newBooks[this->numBooks] = book;

  delete[] this->books;
  this->books = newBooks;
  this->numBooks++;
}

bool Library::removeBook(ISBN isbn) {
  if (this->numBooks == 0) {
    cout << "No books in library!" << endl;
    return false;
  }

  String filename = "books-db/";
  filename.append(getBook(isbn).getContentFileName());
  filename.append(".txt");

  if (remove(filename.getStr()) != 0) {
    cout << "Error deleting file" << endl;
    return false;
  }

  Book *newBooks = new Book[this->numBooks - 1];

  int j = 0;
  for (int i = 0; i < this->numBooks; i++) {
    if (!(this->books[i].getISBN() == isbn)) {
      newBooks[j] = this->books[i];
      j++;
    }
  }

  if (j == this->numBooks - 1) {
    delete[] this->books;
    this->books = newBooks;
    this->numBooks--;
    return true;
  } else {
    delete[] newBooks;
    cout << "Book not found!" << endl;
    return false;
  }
}

Book *Library::getBooks() { return this->books; }

int Library::getNumBooks() { return this->numBooks; }

Book Library::getBook(ISBN isbn) {
  Book book;

  for (int i = 0; i < this->numBooks; i++) {
    if (this->books[i].getISBN() == isbn) {
      book = this->books[i];
    }
  }

  return book;
}

Book *Library::sortedBy(String sortBy, bool ascending) {
  Book *sortedBooks = new Book[this->numBooks];

  for (int i = 0; i < this->numBooks; i++) {
    sortedBooks[i] = this->books[i];
  }

  for (int i = 0; i < this->numBooks; i++) {
    for (int j = 0; j < this->numBooks - 1; j++) {
      if (ascending) {
        if (sortedBooks[j].getAttribute(sortBy) >
            sortedBooks[j + 1].getAttribute(sortBy)) {
          Book temp = sortedBooks[j];
          sortedBooks[j] = sortedBooks[j + 1];
          sortedBooks[j + 1] = temp;
        }
      } else {
        if (sortedBooks[j].getAttribute(sortBy) <
            sortedBooks[j + 1].getAttribute(sortBy)) {
          Book temp = sortedBooks[j];
          sortedBooks[j] = sortedBooks[j + 1];
          sortedBooks[j + 1] = temp;
        }
      }
    }
  }

  return sortedBooks;
}