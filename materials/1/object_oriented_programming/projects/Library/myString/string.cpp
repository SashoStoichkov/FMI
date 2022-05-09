#include <cstring>
#include <iostream>
using namespace std;

#include "string.h"

void String::copy(const String &other) {
  str = new char[other.length() + 1];
  strcpy(str, other.str);
}

void String::free() { delete[] str; }

String::String(const char *s) {
  str = new char[strlen(s) + 1];
  strcpy(str, s);
}

String::String(const String &other) { copy(other); }

String::String(String &&other) {
  // move other's attributes to this
  str = move(other.str);

  // free other
  other.free();
}

String::~String() { free(); }

String &String::operator=(const String &other) {
  if (this != &other) {
    free();
    copy(other);
  }
  return *this;
}

String &String::operator=(String &&other) {
  if (this != &other) {
    free();
    // move other's attributes to this
    str = move(other.str);

    // free other
    other.free();
  }
  return *this;
}

void String::append(const char *s) {
  char *tmp = new char[strlen(str) + strlen(s) + 1];
  strcpy(tmp, str);
  strcat(tmp, s);
  free();
  str = tmp;
}

void String::append(const String &s) { append(s.str); }

void String::print() const { cout << str << endl; }

int String::length() const { return strlen(str); }

void String::popBack() {
  char *tmp = new char[strlen(str) - 1];
  strcpy(tmp, str);
  free();
  str = tmp;
}

void String::pushBack(const char c) {
  char *tmp = new char[strlen(str) + 2];
  strcpy(tmp, str);
  tmp[strlen(str) + 1] = '\0';
  tmp[strlen(str)] = c;
  free();
  str = tmp;
}

bool String::operator==(const String &other) const {
  return strcmp(str, other.str) == 0;
}

bool String::operator!=(const String &other) const {
  return strcmp(str, other.str) != 0;
}

char &String::operator[](const int index) { return str[index]; }

ostream &operator<<(ostream &os, const String &s) { return os << s.str; }

istream &operator>>(istream &is, String &s) { return is >> s.str; }