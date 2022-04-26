#include <iostream>
using namespace std;

#include "time.h"

Time::Time(int hours, int minutes, int seconds) {
  this->hours = hours;
  this->minutes = minutes;
  this->seconds = seconds;
}

void Time::setHours(int hours) {
  if (hours < 0 || hours > 23) {
    // throw exception
    this->hours = 0;
  } else {
    this->hours = hours;
  }
}
void Time::setMinutes(int minutes) {
  if (minutes < 0 || minutes > 60) {
    // throw exception
    this->minutes = 0;
  } else {
    this->minutes = minutes;
  }
}
void Time::setSeconds(int seconds) {
  if (seconds < 0 || seconds > 60) {
    // throw exception
    this->seconds = 0;
  } else {
    this->seconds = seconds;
  }
}

void Time::secondsToTime(int seconds) {
  setHours(seconds / 3600);
  seconds /= 3600;

  setMinutes(seconds / 60);
  seconds /= 60;

  setSeconds(seconds);
}

void Time::increaseByASecond() {
  int newTimeInSeconds = (hours * 3600) + (minutes * 60) + seconds + 1;
  secondsToTime(newTimeInSeconds);
}

bool Time::isPartyTime() {
  if (hours >= 22 || hours <= 1) {
    if (hours == 22) {
      return minutes >= 30;
    }

    return true;
  }

  return false;
}