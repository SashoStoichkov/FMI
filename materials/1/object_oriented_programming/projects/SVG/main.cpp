#include <iostream>
using namespace std;

#include "./Interface/Interface.h"
#include "./File/File.h"

int main() {
  // Interface().run();

  File file("SVGs/figures.svg");
  file.load();
  file.print();

  return 0;
}