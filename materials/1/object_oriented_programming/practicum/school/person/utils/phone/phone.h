#ifndef __PHONE_H__
#define __PHONE_H__

#include "../../../myString/string.h"

class Phone {
private:
  String number;

public:
  Phone(String number = "+359XXXXXXXXX");

  void setNumber(String number);

  String getNumber() const;
};

#endif // __PHONE_H__