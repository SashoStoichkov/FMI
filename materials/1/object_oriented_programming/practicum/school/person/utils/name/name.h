#ifndef __NAME_H__
#define __NAME_H__

#include "../../../myString/string.h"

class Name {
private:
  String firstName;
  String lastName;

public:
  Name(String firstName = "", String lastName = "");

  void setFirstName(String firstName);
  void setLastName(String lastName);

  String getFirstName() const;
  String getLastName() const;
};

#endif // __NAME_H__