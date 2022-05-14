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

  for (int i = 0; i < this->numBooks; i++) {
    if (this->books[i].getISBN() == isbn) {
      Book *newBooks = new Book[this->numBooks - 1];

      for (int j = 0; j < i; j++) {
        newBooks[j] = this->books[j];
      }

      for (int j = i; j < this->numBooks - 1; j++) {
        newBooks[j] = this->books[j + 1];
      }

      delete[] this->books;
      this->books = newBooks;
      this->numBooks--;

      String filename = "books-db/";
      filename.append(getBook("i", isbn.getStr()).getContentFileName());
      filename.append(".txt");

      if (remove(filename.getStr()) != 0) {
        cout << "Error deleting file" << endl;
        return false;
      }

      return true;
    }
  }

  cout << "Book not found!" << endl;
  return false;
}

Book *Library::getBooks() { return this->books; }

int Library::getNumBooks() { return this->numBooks; }

Book Library::getBook(String searchBy, String searchFor) {
  Book book;

  if (searchBy == "d") {
    // search by description substring
    for (int i = 0; i < this->numBooks; i++) {
      if (this->books[i].getDescription().toLower().contains(
              searchFor.toLower())) {
        book = this->books[i];
        break;
      }
    }
  } else {
    for (int i = 0; i < this->numBooks; i++) {
      if (this->books[i].getAttribute(searchBy).toLower() ==
          searchFor.toLower()) {
        book = this->books[i];
        break;
      }
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