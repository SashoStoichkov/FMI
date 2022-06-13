#include <iostream>
using namespace std;

#include "Intermission.h"

Intermission::Intermission(unsigned int duration) : duration(duration) {}

unsigned int Intermission::getDuration() const { return this->duration; }

Intermission::Intermission(const Intermission &other) {
  this->duration = other.getDuration();
}

Intermission &Intermission::operator=(const Intermission &other) {
  if (this != &other) {
    this->duration = other.getDuration();
  }
  return *this;
}