#include <iostream>
using namespace std;

#include "Time.h"

Time::Time(unsigned int hour, unsigned int minutes) {
  if ((hour < 0 || hour > 23) || (minutes < 0 || minutes > 59)) {
    cout << "Invalid time" << endl;
    return;
  } else {
    this->hour = hour;
    this->minutes = minutes;
  }
}

Time::Time(const Time &other) {
  if (this != &other) {
    this->hour = other.getHour();
    this->minutes = other.getMinutes();
  }
}

Time &Time::operator=(const Time &other) {
  if (this != &other) {
    this->hour = other.getHour();
    this->minutes = other.getMinutes();
  }
  return *this;
}

unsigned int Time::getHour() const { return this->hour; }
unsigned int Time::getMinutes() const { return this->minutes; }
