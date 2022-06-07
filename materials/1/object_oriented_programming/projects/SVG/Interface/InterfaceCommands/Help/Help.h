#ifndef __HELP_H__
#define __HELP_H__

#include "../../../Command/Command.h"

class Help : public Command {
public:
  Help(const string &line = "help");

  virtual bool execute();
};

#endif // __HELP_H__