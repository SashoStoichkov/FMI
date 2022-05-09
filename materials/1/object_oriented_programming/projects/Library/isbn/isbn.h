#ifndef __ISBN_H__
#define __ISBN_H__

#include "../myString/string.h"

class ISBN {
private:
  String isbn;

  // check if the isbn is valid
  bool isValid(String isbn);

public:
  ISBN(String isbn = "");

  bool operator==(const ISBN &isbn) const;
};

#endif // __ISBN_H__