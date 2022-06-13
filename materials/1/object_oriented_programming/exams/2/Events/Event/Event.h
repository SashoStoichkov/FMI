#ifndef __EVENT_H__
#define __EVENT_H__

#include "../Time/Time.h"

class Event {
private:
  Time startTime;
  Time endTime;
  unsigned int maxDuration; // in hours

public:
  // constructor
  Event(Time startTime = Time(), Time endTime = Time(),
        unsigned int maxDuration = 0);

  // copy constructor
  Event(const Event &other);

  // copy assignment
  Event &operator=(const Event &other);

  // getters
  Time getStartTime() const;
  Time getEndTime() const;
  unsigned int getMaxDuration() const;
};

#endif // __EVENT_H__