#ifndef __SAVEAS_H__
#define __SAVEAS_H__

#include "../../../Command/Command.h"

class SaveAs : public Command {
public:
  SaveAs(const string &line = "saveas");

  virtual bool execute();
};

#endif // __SAVEAS_H__