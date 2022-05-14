#ifndef __ISBN_H__
#define __ISBN_H__

#include "../myString/string.h"

class ISBNNotValidException : public std::exception {
public:
  ISBNNotValidException() : std::exception() {}
};

class ISBN {
private:
  String isbn;

  // check if the isbn is valid
  // https://www.isbn-check.com/ for checking isbn validity for tests and demo
  bool isValid(String isbn);

public:
  // 007462542X
  // 0004625420
  ISBN(String isbn = "0000000000");

  String getStr();

  bool operator==(const ISBN &isbn) const;
};

#endif // __ISBN_H__