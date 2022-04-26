#ifndef __PERSON_H__
#define __PERSON_H__

#include "../school/school.h"

class Name {
private:
  String firstName;
  String lastName;
};

class BirthDate {
private:
  int day;
  int month;
  int year;
};

class Phone {
private:
  String number;
};

class Email {
private:
  String address;
};

class Student {
private:
  Name name;

  ClassName className;
  Grade *grades;

  BirthDate birthDate;
  Phone phoneNumber;
  Email emailAddress;
};

class Teacher {
private:
  Name name;

  Subject subject;
  int yearsOfExperience;

  Phone phoneNumber;
  Email emailAddress;
};

class Headmaster {
private:
  Name name;
};

#endif // __PERSON_H__