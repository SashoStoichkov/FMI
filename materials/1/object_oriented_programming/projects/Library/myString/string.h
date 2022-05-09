#ifndef __STRING_H__
#define __STRING_H__

#include <iostream>
using namespace std;

class String {
private:
  char *str;

  void copy(const String &other);
  void free();

public:
  // constructor
  String(const char *s = "");

  // copy constructor
  String(const String &other);

  // move constructor
  String(String &&other);

  // destructor
  ~String();

  // copy assignment
  String &operator=(const String &other);

  // move assignment
  String &operator=(String &&other);

  // other methods
  void append(const char *s);
  void append(const String &s);

  void print() const;
  int length() const;

  void popBack();
  void pushBack(const char c);

  char &operator[](const int index);

  bool operator==(const String &other) const;

  bool operator!=(const String &other) const;

  friend istream &operator>>(istream &is, String &s);

  friend ostream &operator<<(ostream &os, const String &s);
};

#endif // __STRING_H__