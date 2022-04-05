#include <cstring>
#include <iostream>

using namespace std;

#include "string.h"

void String::copy(const String &s) {
  str = new char[strlen(s.str) + 1];
  strcpy(str, s.str);
}

void String::free() { delete[] str; }

String::String(const char *s) {
  str = new char[strlen(s) + 1];
  strcpy(str, s);
}

String::String(const String &s) { copy(s); }

String::~String() { free(); }

String &String::operator=(const String &s) {
  if (this != &s) {
    free();
    copy(s);
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

void String::pop_back() {
  char *tmp = new char[strlen(str) - 1];
  strcpy(tmp, str);
  free();
  str = tmp;
}
