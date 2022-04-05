#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "command.h"

class Interface {
private:
  int num_of_commands;
  Command *commands;

public:
  Interface(int num_of_commands = 0, Command *commands = nullptr);
  ~Interface();
  void addCommand(Command command);
  void executeAllCommands();

  int getNumOfCommands() const;
  Command *getCommands() const;
};

#endif // __INTERFACE_H__