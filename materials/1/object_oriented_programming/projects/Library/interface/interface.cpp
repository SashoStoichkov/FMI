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

void Interface::printAllCommands() {
  cout << "Available commands:" << endl;
  for (int i = 0; i < Interface::NUM_COMMANDS; i++) {
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

    // check if book already exists
    Book check = library.getBook("i", isbnStr);

    if (check.getISBN().getStr() != "0000000000") {
      cout << "Book already exists!" << endl;
      return;
    }

    // ISBN is valid and not in library
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

    String author, title, contentFileName, description;

    cout << "Library(add)> Enter Author: ";
    cin >> author;

    cout << "Library(add)> Enter Title: ";
    cin >> title;

    cout << "Library(add)> Enter Content File Name (without '.txt'): ";
    cin >> contentFileName;

    cout << "Library(add)> Enter Short Description: ";
    cin >> description;

    Book book(author, title, contentFileName, description, rating, isbn);

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

void Interface::searchBook() {
  cout << "Choose searching category (title (t), author (a), ISBN (i) or "
          "description (d)): ";

  String searchBy;
  cin >> searchBy;

  if (searchBy == "t" || searchBy == "a" || searchBy == "i" ||
      searchBy == "d") {
    cout << "Enter search term: ";

    String searchFor;
    cin >> searchFor;

    Book book = library.getBook(searchBy, searchFor);

    if (book.getAuthor() != "") {
      cout << "Book found:" << endl;
      book.print();
    } else {
      cout << "Book not found" << endl;
      return;
    }
  } else {
    cout << "Invalid category" << endl;
    return;
  }
}

void Interface::printBook() {
  cout << "Enter ISBN: ";

  String isbnStr;
  cin >> isbnStr;

  Book book = library.getBook("i", isbnStr);

  if (book.getISBN().getStr() != "0000000000") {
    cout << "Book found:" << endl;
    book.printContent();
  } else {
    cout << "Book not found" << endl;
    return;
  }
}

bool Interface::runCommand(String command) {
  bool run = true;

  if (command == "/add") {
    addBook();
  } else if (command == "/remove") {
    removeBook();
  } else if (command == "/sort") {
    sortBooks();
  } else if (command == "/search") {
    searchBook();
  } else if (command == "/book") {
    printBook();
  } else if (command == "/exit") {
    run = false;
  } else {
    cout << "Invalid command!" << endl;
  }

  return run;
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

    if (command == "/help") {
      printAllCommands();
    } else {
      run = runCommand(command);
    }
  }

  cout << "Bye!" << endl;
}