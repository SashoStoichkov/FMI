#ifndef __SIMPLEEVENT_H__
#define __SIMPLEEVENT_H__

#include "../Event/Event.h"

class SimpleEvent : public Event {
public:
  // constructor
  SimpleEvent(Time startTime = Time(), Time endTime = Time(),
              unsigned int maxDuration = 0);

  // copy constructor
  SimpleEvent(const SimpleEvent &other);

  // copy assignment
  SimpleEvent &operator=(const SimpleEvent &other);
};

#endif // __SIMPLEEVENT_H__