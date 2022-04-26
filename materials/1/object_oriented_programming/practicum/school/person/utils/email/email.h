#ifndef __EMAIL_H__
#define __EMAIL_H__

#include "../../../myString/string.h"
#include "../name/name.h"

class Email {
private:
  String address;

public:
  Email();
  Email(Name name);

  void setAddress(String address);

  String getAddress() const;
};

#endif // __EMAIL_H__