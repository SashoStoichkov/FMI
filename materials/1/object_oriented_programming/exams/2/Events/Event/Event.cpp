#include <iostream>
using namespace std;

#include "Event.h"

Event::Event(Time startTime, Time endTime, unsigned int maxDuration)
    : startTime(startTime), endTime(endTime), maxDuration(maxDuration) {}

Event::Event(const Event &other) {
  if (this != &other) {
    this->startTime = other.getStartTime();
    this->endTime = other.getEndTime();
    this->maxDuration = other.getMaxDuration();
  }
}

Event &Event::operator=(const Event &other) {
  if (this != &other) {
    this->startTime = other.getStartTime();
    this->endTime = other.getEndTime();
    this->maxDuration = other.getMaxDuration();
  }
  return *this;
}

Time Event::getStartTime() const { return this->startTime; }

Time Event::getEndTime() const { return this->endTime; }

unsigned int Event::getMaxDuration() const { return this->maxDuration; }
