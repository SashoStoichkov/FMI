#ifndef __PARAMDEFN_H__
#define __PARAMDEFN_H__

#include "../SimpleDefn/SimpleDefn.h"

class ParamDefn : public SimpleDefn {
public:
  // constructor
  ParamDefn(char *name, char *value);

  void printValue() const;
};

#endif // __PARAMDEFN_H__