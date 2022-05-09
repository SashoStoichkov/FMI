#include <iostream>
using namespace std;

#include "./interface/interface.h"

int main() {
  Interface interface("admin");
  interface.run();

  return 0;
}