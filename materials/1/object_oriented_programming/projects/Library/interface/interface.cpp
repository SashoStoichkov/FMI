#include <iostream>
using namespace std;

#include "interface.h"

Interface::Interface(String adminPassword) : adminPassword(adminPassword) {}

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

void Interface::run() {
  // print welcome message
  cout << "Welcome to the library!" << endl;

  bool run = true;

  while (run) {
    String command;
    cout << ">> ";
    cin >> command;

    switch (getCommandIndex(command)) {
    case 0: // add book
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