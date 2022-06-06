#include <iostream>
using namespace std;

#include "Interface.h"

bool Command::fileOpen = false;
string Command::prompt = "> ";

void Interface::run() {
  string input;

  while (true) {
    bool executed = false;

    cout << Command::prompt;
    getline(cin, input);

    size_t pos = 0;
    size_t pos2 = 0;

    // get command name
    pos = input.find_first_not_of(" \t");
    pos2 = input.find_first_of(" \t", pos);

    string cmd = input.substr(pos, pos2 - pos);

    if (cmd == "exit") {
      if (Command::fileOpen) {
        cout << "You have an open file with unsaved changes, please select "
                "close or save first."
             << endl;
      } else {
        cout << "Exiting program ..." << endl;
        break;
      }

      executed = true;
    }

    for (auto command : availableCommands) {
      if (command->getName() == cmd) {
        command->parse(input);
        command->execute();

        executed = true;
      }
    }

    if (!executed) {
      cout << "Unknown command: " << cmd << endl;
    }
  }
}
