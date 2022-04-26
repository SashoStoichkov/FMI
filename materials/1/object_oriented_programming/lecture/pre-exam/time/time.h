#ifndef __TIME_H__
#define __TIME_H__

class Time {
private:
  int hours;
  int minutes;
  int seconds;

  void secondsToTime(int seconds);

public:
  Time(int hours = 0, int minutes = 0, int seconds = 0);

  void setHours(int hours);
  void setMinutes(int minutes);
  void setSeconds(int seconds);

  void increaseByASecond();

  bool isPartyTime();
};

#endif // __TIME_H__