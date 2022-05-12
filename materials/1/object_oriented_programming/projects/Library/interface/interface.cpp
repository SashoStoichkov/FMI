#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

#include "interface.h"

void log(String action, String isbn) {
  time_t now = time(0);
  String dt = String(ctime(&now));

  ofstream logFile("books-db/log.txt", ios::app);

  if (action == "add") {
    logFile << endl << dt << "- Added book: " << isbn;
  } else if (action == "remove") {
    logFile << endl << dt << "- Removed book: " << isbn;
  }

  logFile.close();
}

Interface::Interface(String adminPassword) : adminPassword(adminPassword) {}

bool Interface::enterAdminPassword() {
  String password;
  cout << "Enter admin password: ";

  // TODO: mask input with *
  cin >> password;

  return password == adminPassword;
}

int Interface::getCommandIndex(String command) {
  for (int i = 0; i < 8; i++) {
    if (commands[i] == command) {
      return i;
    }
  }
  return -1;
}

void Interface::printAllCommands() {
  cout << "Available commands:" << endl;
  for (int i = 0; i < 8; i++) {
    cout << commands[i] << endl;
  }
}

void Interface::addBook() {
  if (!enterAdminPassword()) {
    cout << "Access denied!" << endl;
    return;
  } else {
    cout << "Enter book information:" << endl;

    String isbnStr;

    cout << "Library(add)> Enter ISBN: ";
    cin >> isbnStr;

    try {
      ISBN isbn(isbnStr);
    } catch (const ISBNNotValidException &e) {
      cout << "Invalid ISBN" << endl;
      return;
    }

    // ISBN is valid
    ISBN isbn(isbnStr);

    int rating;
    cout << "Library(add)> Enter Rating (0-5): ";
    cin >> rating;

    // ignores the newline character
    getchar();

    if (rating < 0 || rating > 5) {
      cout << "Invalid rating" << endl;
      return;
    }

    String author, title, contentFileName, shortDescription;

    cout << "Library(add)> Enter Author: ";
    cin >> author;

    cout << "Library(add)> Enter Title: ";
    cin >> title;

    cout << "Library(add)> Enter Content File Name (without '.txt'): ";
    cin >> contentFileName;

    cout << "Library(add)> Enter Short Description: ";
    cin >> shortDescription;

    Book book(author, title, contentFileName, shortDescription, rating, isbn);

    String content;
    cout << "Library(add)> Enter Content: ";
    cin >> content;

    String fileDestination = "books-db/";
    fileDestination.append(contentFileName);
    fileDestination.append(".txt");

    ofstream file(fileDestination.getStr());
    file << content;
    file.close();

    library.addBook(book);

    log("add", isbnStr);
    cout << "Book added successfully!" << endl;
  }
}

void Interface::removeBook() {
  if (!enterAdminPassword()) {
    cout << "Access denied!" << endl;
    return;
  } else {
    String isbnStr;
    cout << "Library(remove)> Enter ISBN: ";
    cin >> isbnStr;

    try {
      ISBN isbn(isbnStr);
    } catch (const ISBNNotValidException &e) {
      cout << "Invalid ISBN" << endl;
      return;
    }

    ISBN isbn(isbnStr);

    if (library.removeBook(isbn)) {
      log("remove", isbnStr);
      cout << "Book removed successfully!" << endl;
    }
  }
}

void Interface::sortBooks() {
  cout << "Choose sorting category (title (t), author (a) or rating (r)): ";

  String sortBy;
  cin >> sortBy;

  if (sortBy == "t" || sortBy == "a" || sortBy == "r") {
    cout << "Choose sorting order (ascending (a) or descending (d)): ";

    String order;
    cin >> order;

    if (order == "a" || order == "d") {
      cout << "Sorting..." << endl;

      Book *books = library.sortedBy(sortBy, order == "a" ? true : false);

      cout << "Sorted books:" << endl;
      for (int i = 0; i < library.getNumBooks(); i++) {
        books[i].printShort();
      }

    } else {
      cout << "Invalid order" << endl;
      return;
    }
  } else {
    cout << "Invalid category" << endl;
    return;
  }
}

void Interface::run() {
  // print welcome message
  cout << "Welcome to the library!" << endl;
  cout << "Type '/help' for available commands." << endl;

  bool run = true;

  while (run) {
    cout << "Library> ";

    String command;
    cin >> command;

    switch (getCommandIndex(command)) {
    case 0: // add book
      addBook();
      break;
    case 1: // remove book
      removeBook();
      break;
    case 2: // sort books
      sortBooks();
      break;
    case 3: // search books
      break;
    case 4: // print book
      break;
    case 5: // usage
      break;
    case 6: // commands
      printAllCommands();
      break;
    case 7: // exit
      run = false;
      break;
    }
  }
}