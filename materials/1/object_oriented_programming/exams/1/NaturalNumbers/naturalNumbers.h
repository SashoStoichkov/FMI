#ifndef __NATURAL_NUMBERS__
#define __NATURAL_NUMBERS__

class NaturalNumbers {
private:
  char *name;
  int size;
  int *numbers;

  bool isNumberInSet(int number);

public:
  NaturalNumbers(char *name = new char[10]{"Empty set"}, int size = 0,
                 int *numbers = nullptr);
  ~NaturalNumbers();

  char *getName() const;
  int getSize() const;
  int *getNumbers() const;

  NaturalNumbers &operator+(NaturalNumbers n);
  NaturalNumbers &operator+=(NaturalNumbers n);

  // bool operator[](int number);
};

#endif // __NATURAL_NUMBERS__