#include <iostream>
using namespace std;

#include "./Interface/Interface.h"
#include "./File/File.h"

int main() {
  // Interface().run();

  File file("SVGs/figures.svg");
  file.load();
  // file.print();

  file.getShapes()[0]->translate(10, 10);

  file.save("SVGs/figures_new_one.svg");

  file.getShapes()[0]->translate(-10, -10);
  for (int i = 0; i < file.getShapes().size(); i++) {
    file.getShapes()[i]->translate(10, 10);
  }

  file.save("SVGs/figures_new.svg");

  return 0;
}