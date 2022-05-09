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
       String shortDescription = "", int rating = 0, String isbn = "");

  bool operator==(const Book &book) const;

  void inputContent();

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

  // filters
  Book getByAuthor(String author);
  Book getByTitle(String title);
  Book getByShortDescription(String shortDescription);
  Book getByRating(int rating);
  Book getByISBN(ISBN isbn);
};

#endif // __BOOK_H__