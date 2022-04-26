#ifndef __BIRTHDATE_H__
#define __BIRTHDATE_H__

#include "../../../myString/string.h"

class BirthDate {
private:
  int day;
  int month;
  int year;

  String date;

  bool checkDay(int day);
  bool checkMonth(int month);
  bool checkYear(int year);
  bool checkDate(int day, int month, int year);

  String toString(int day, int month, int year);

public:
  BirthDate(int day = 1, int month = 1, int year = 1970);

  void setDay(int day);
  void setMonth(int month);
  void setYear(int year);

  int getDay() const;
  int getMonth() const;
  int getYear() const;
  String getDate() const;
};

#endif // __BIRTHDATE_H__