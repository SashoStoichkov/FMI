#ifndef __TIME_H__
#define __TIME_H__

class Time {
private:
  unsigned int hour;
  unsigned int minutes;

public:
  // constructor
  Time(unsigned int hour = 0, unsigned int minutes = 0);

  // copy constructor
  Time(const Time &other);

  // copy assignment
  Time &operator=(const Time &other);

  // getters
  unsigned int getHour() const;
  unsigned int getMinutes() const;
};

#endif // __TIME_H__