#ifndef __WITHIN_H__
#define __WITHIN_H__

#include "../../../Command/Command.h"

class Within : public Command {
public:
  Within(const string &line = "within");

  virtual bool execute();
};

#endif // __WITHIN_H__