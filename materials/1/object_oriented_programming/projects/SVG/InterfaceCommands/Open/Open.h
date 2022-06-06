#ifndef __OPEN_H__
#define __OPEN_H__

#include "../../Command/Command.h"

class Open : public Command {
public:
  Open(const string &line = "open");

  virtual bool execute();
};

#endif // __OPEN_H__