#ifndef __CLOSE_H__
#define __CLOSE_H__

#include "../../Command/Command.h"

class Close : public Command {
public:
  Close(const string &line = "close");

  virtual bool execute();
};

#endif // __CLOSE_H__