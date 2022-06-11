#ifndef __TRANSLATE_H__
#define __TRANSLATE_H__

#include "../../../Command/Command.h"

class Translate : public Command {
public:
  Translate(const string &line = "translate");

  virtual bool execute();
};

#endif // __TRANSLATE_H__