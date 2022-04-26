#include <iostream>
using namespace std;

#include "time.h"

int main() {

  Time time = Time(23, 0, 0);

  // time.increaseByASecond();

  cout << time.isPartyTime() << endl;

  return 0;
}