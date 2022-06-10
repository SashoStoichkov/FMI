#ifndef __ERASE_H__
#define __ERASE_H__

#include "../../../Command/Command.h"

class Erase : public Command {
public:
  Erase(const string &line = "erase");

  virtual bool execute();
};

#endif // __ERASE_H__