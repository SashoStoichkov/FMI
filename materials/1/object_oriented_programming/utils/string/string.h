#ifndef __STRING_H__
#define __STRING_H__

class String {
private:
  char *str;
  void copy(const String &s);
  void free();

public:
  String(const char *s = "");
  String(const String &s);
  ~String();

  String &operator=(const String &s);

  void append(const char *s);
  void append(const String &s);

  void print() const;
  int length() const;

  void pop_back();
};

#endif // __STRING_H__