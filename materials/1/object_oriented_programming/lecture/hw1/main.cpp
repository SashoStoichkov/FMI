#include <iostream>
using namespace std;

#include "command.h"
#include "interface.h"

void printAllCommands(Command *commands, int num_of_commands) {
  for (int i = 0; i < num_of_commands; i++) {
    cout << commands[i].getName() << endl;
  }
}

int main() {
  Interface interface;

  for (int i = 0; i < 15; i++) {
    Command command(char('a' + i));
    interface.addCommand(command);
  }

  printAllCommands(interface.getCommands(), interface.getNumOfCommands());
  // interface.executeAllCommands();

  return 0;
}