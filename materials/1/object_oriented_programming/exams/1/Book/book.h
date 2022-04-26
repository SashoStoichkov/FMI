#ifndef __BOOK__
#define __BOOK__

class Book {
private:
  char title[100];
  char author[100];
  unsigned int count;

public:
  Book(const char title[100] = "", const char author[100] = "",
       const unsigned int count = 0);

  void setTitle(const char *title);
  void setAuthor(const char *author);
  void setCount(const unsigned int count);

  const char *getTitle() const;
  const char *getAuthor() const;
  unsigned int getCount() const;
};

#endif // __BOOK__