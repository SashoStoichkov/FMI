#include "command.h"
#include <iostream>
using namespace std;

#include "interface.h"

Interface::Interface(int num_of_commands, Command *commands)
    : num_of_commands(num_of_commands), commands(new Command[num_of_commands]) {
  for (int i = 0; i < num_of_commands; i++) {
    this->commands[i] = commands[i];
  }
}

Interface::~Interface() { delete[] commands; }

void Interface::addCommand(Command command) {
  Command *temp = new Command[num_of_commands + 1];

  for (int i = 0; i < num_of_commands; i++) {
    temp[i] = commands[i];
  }
  temp[num_of_commands] = command;

  delete[] commands;
  commands = temp;
  num_of_commands++;
}

void Interface::executeAllCommands() {
  for (int i = 0; i < num_of_commands; i++) {
    cout << commands[i].getName() << endl;
  }
}

int Interface::getNumOfCommands() const { return num_of_commands; }

Command *Interface::getCommands() const { return commands; }
