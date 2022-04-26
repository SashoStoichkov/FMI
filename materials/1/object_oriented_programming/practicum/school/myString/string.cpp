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

String String::append(const char *s) {
  String result(*this);
  result.str = new char[length() + strlen(s) + 1];
  strcpy(result.str, str);
  strcat(result.str, s);
  return result;
}

String String::append(const String &s) { return append(s.str); }

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

String String::substr(int start, int end) {
  String result;
  if (start < 0) {
    start = length() + start;
  }
  if (end < 0) {
    end = length() + end;
  }
  if (start < 0 || start >= length() || end < 0 || end >= length() ||
      start > end) {
    throw "Invalid substring!";
  }
  result.str = new char[end - start + 2];
  strncpy(result.str, str + start, end - start + 1);
  result.str[end - start + 1] = '\0';
  return result;
}

char &String::operator[](int index) { return str[index]; }