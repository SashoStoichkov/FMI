#ifndef __SIMPLEDEFN_H__
#define __SIMPLEDEFN_H__

#include <cstring>

class SimpleDefn {
protected:
  char *name;
  char *value;

  void copy(const SimpleDefn &other);
  void free();

public:
  // constructor
  SimpleDefn(char *name = "", char *value = "");

  // copy constructor
  SimpleDefn(const SimpleDefn &other);

  // move constructor
  SimpleDefn(SimpleDefn &&other);

  // destructor
  ~SimpleDefn();

  // copy assignment
  SimpleDefn &operator=(const SimpleDefn &other);

  // move assignment
  SimpleDefn &operator=(SimpleDefn &&other);

  char *getName() const;
  char *getValue() const;

  virtual void printValue() const = 0;
};

#endif // __SIMPLEDEFN_H__