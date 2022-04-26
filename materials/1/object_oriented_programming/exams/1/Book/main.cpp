#include <fstream>
#include <iostream>
using namespace std;

#include "book.h"

int main() {

  Book b1("Title 1", "Author 1", 1000);
  Book b2("Title 2", "Author 2", 10);
  Book b3("Title 3", "Author 3", 1001);

  Book *books = new Book[3];
  books[0].setAuthor(b1.getAuthor());
  books[0].setTitle(b1.getTitle());
  books[0].setCount(b1.getCount());

  books[1].setAuthor(b2.getAuthor());
  books[1].setTitle(b2.getTitle());
  books[1].setCount(b2.getCount());

  books[2].setAuthor(b3.getAuthor());
  books[2].setTitle(b3.getTitle());
  books[2].setCount(b3.getCount());

  ofstream file("popular.txt");

  for (int i = 0; i < 3; i++) {
    if (books[i].getCount() >= 1000) {
      file << books[i].getTitle() << "," << books[i].getAuthor() << ","
           << books[i].getCount() << endl;
    }
  }

  file.close();

  return 0;
}