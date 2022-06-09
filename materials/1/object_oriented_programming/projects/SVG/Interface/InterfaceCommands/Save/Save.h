#ifndef __SAVE_H__
#define __SAVE_H__

#include "../../../Command/Command.h"

class Save : public Command {
public:
  Save(const string &line = "save");

  virtual bool execute();
};

#endif // __SAVE_H__