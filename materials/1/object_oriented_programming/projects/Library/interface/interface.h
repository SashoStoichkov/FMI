#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "../book/book.h"
#include "../library/library.h"
#include "../myString/string.h"

class Interface {
private:
  String adminPassword;
  Library library;

  static const int NUM_COMMANDS = 7;

  String commands[NUM_COMMANDS] = {"/add",  "/remove", "/sort", "/search",
                                   "/book", "/help",   "/exit"};

  bool enterAdminPassword();

  void printAllCommands();

  // add book
  void addBook();

  // remove book
  void removeBook();

  // sort books
  void sortBooks();

  // search book
  void searchBook();

  // print book
  void printBook();

  bool runCommand(String command);

public:
  Interface(String adminPassword = "");

  void run();
};

#endif // __INTERFACE_H__