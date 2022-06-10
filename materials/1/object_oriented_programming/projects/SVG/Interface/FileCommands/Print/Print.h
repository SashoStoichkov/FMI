#ifndef __PRINT_H__
#define __PRINT_H__

#include "../../../Command/Command.h"

class Print : public Command {
public:
  Print(const string &line = "print");

  virtual bool execute();
};

#endif // __PRINT_H__