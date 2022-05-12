#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "../book/book.h"
#include "../library/library.h"
#include "../myString/string.h"

class Interface {
private:
  String adminPassword;
  Library library;

  String commands[8] = {"/add",  "/remove", "/sort", "/search",
                        "/book", "/usage",  "/help", "/exit"};

  int getCommandIndex(String command);

  bool enterAdminPassword();

  void printAllCommands();
  void printUsage(String command);

  // add book
  void addBook();

  // remove book
  void removeBook();

  // sort books
  void sortBooks();

  // search books
  void searchBooks(String searchBy, String searchFor);

  // print book
  void printBook(ISBN isbn);

public:
  Interface(String adminPassword = "");

  void run();
};

#endif // __INTERFACE_H__