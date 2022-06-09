#ifndef __INTERFACE_H__
#define __INTERFACE_H__

#include "./InterfaceCommands/InterfaceCommands.h"

class Interface {
private:
  vector<Command *> availableCommands = {new Help(), new Open(), new Save(),
                                         new SaveAs(), new Close()};

public:
  void run();
};

#endif // __INTERFACE_H__