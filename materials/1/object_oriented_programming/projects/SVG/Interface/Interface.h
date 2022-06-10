#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "./FileCommands/FileCommands.h"
#include "./InterfaceCommands/InterfaceCommands.h"

class Interface {
private:
  vector<Command *> availableCommands = {new Help(),   new Open(),  new Save(),
                                         new SaveAs(), new Close(), new Print(),
                                         new Create(), new Erase()};

public:
  void run();
};

#endif // __INTERFACE_H__