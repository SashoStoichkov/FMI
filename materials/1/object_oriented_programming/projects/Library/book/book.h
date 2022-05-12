#ifndef __BOOK_H__
#define __BOOK_H__

#include "../isbn/isbn.h"
#include "../myString/string.h"

class Book {
private:
  String author;
  String title;
  String contentFileName;
  String shortDescription;
  int rating;
  ISBN isbn;

public:
  Book(String author = "", String title = "", String contentFileName = "",
       String shortDescription = "", int rating = 0, ISBN isbn = ISBN("007462542X"));

  bool operator==(const Book &book) const;

  // print info
  void print();
  void printShort();
  void printContent();

  // getters
  String getAuthor();
  String getTitle();
  String getContentFileName();
  String getShortDescription();
  int getRating();
  ISBN getISBN();

  // getAtrribute
  String getAttribute(String attribute);
};

#endif // __BOOK_H__