#ifndef __CREATE_H__
#define __CREATE_H__

#include "../../../Command/Command.h"

class Create : public Command {
public:
  Create(const string &line = "create");

  virtual bool execute();
};

#endif // __CREATE_H__