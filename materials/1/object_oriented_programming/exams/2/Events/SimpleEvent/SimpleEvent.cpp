#include <iostream>
using namespace std;

#include "SimpleEvent.h"

SimpleEvent::SimpleEvent(Time startTime, Time endTime, unsigned int maxDuration)
    : Event(startTime, endTime, maxDuration) {}

SimpleEvent::SimpleEvent(const SimpleEvent &other) {
  if (this != &other) {
    this->operator=(SimpleEvent(other));
  }
}

SimpleEvent &SimpleEvent::operator=(const SimpleEvent &other) {
  if (this != &other) {
    this->operator=(other);
  }
  return *this;
}
