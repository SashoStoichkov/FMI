#include <ctime>
#include <fstream>
#include <iostream>
using namespace std;

#include "interface.h"

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

    String author, title, contentFileName, shortDescription;
    int rating;

    cout << "Library(add)> Enter Author: ";
    cin >> author;

    cout << "Library(add)> Enter Title: ";
    cin >> title;

    cout << "Library(add)> Enter Content File Name (without '.txt'): ";
    cin >> contentFileName;

    cout << "Library(add)> Enter Short Description: ";
    cin >> shortDescription;

    cout << "Library(add)> Enter Rating: ";
    cin >> rating;

    // ignores the newline character
    getchar();

    Book book(author, title, contentFileName, shortDescription, rating, isbn);

    String content;
    cout << "Library(add)> Enter Content: ";
    cin >> content;

    String fileDestination = "books-db/";
    // fileDestination.append(isbnStr);
    // fileDestination.append("-");
    fileDestination.append(contentFileName);
    fileDestination.append(".txt");

    ofstream file(fileDestination.getStr());
    file << content;
    file.close();

    time_t now = time(0);
    String dt = String(ctime(&now));

    ofstream logFile("books-db/log.txt", ios::app);
    logFile << endl
            << dt << "- Added book: " << isbnStr << " in file "
            << contentFileName << ".txt";
    logFile.close();
  }
}

void Interface::run() {
  // print welcome message
  cout << "Welcome to the library!" << endl;

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
      break;
    case 2: // sort books
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