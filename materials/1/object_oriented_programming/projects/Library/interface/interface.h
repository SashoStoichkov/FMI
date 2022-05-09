#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "../book/book.h"
#include "../myString/string.h"

class Interface {
private:
  String adminPassword;

  String commands[8] = {"/add",  "/remove", "/sort",     "/search",
                        "/book", "/usage",  "/commands", "/exit"};

  int getCommandIndex(String command);

  void printAllCommands();
  void printUsage(String command);

  // add book
  void addBook(String author, String title, String contentFileName,
               String shortDescription, int rating, ISBN isbn, String content);

  // remove book
  void removeBook(ISBN isbn);

  // sort books
  void sortBooks(String sortBy);

  // search books
  void searchBooks(String searchBy, String searchFor);

  // print book
  void printBook(ISBN isbn);

public:
  Interface(String adminPassword = "");

  void run();
};

#endif // __INTERFACE_H__