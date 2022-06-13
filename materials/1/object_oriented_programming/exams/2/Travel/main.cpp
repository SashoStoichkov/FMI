#include <iostream>
using namespace std;

#include "./CombinedTrip/CombinedTrip.h"

int main() {

  unsigned int regNumb[4] = {0};
  char *dest[2] = {"Sofia", "Varna"};

  CombinedTrip c("asd", 10, regNumb, 10.0, 11, 2, dest, 10);

  cout << c.getDuration() << endl;
  c.print();

  return 0;
}