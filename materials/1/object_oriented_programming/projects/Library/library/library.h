#ifndef __LIBRARY_H__
#define __LIBRARY_H__

#include "../book/book.h"
#include "../myString/string.h"

class Library {
private:
  int numBooks;
  Book *books;

public:
  Library(int numBooks = 0, Book *books = nullptr);
  ~Library();

  void addBook(Book book);
  bool removeBook(ISBN isbn);

  Book *getBooks();
  int getNumBooks();

  Book getBook(ISBN isbn);

  Book *sortedBy(String sortBy, bool ascending);
};

#endif // __LIBRARY_H__