#ifndef __EVENTWITHFIXEDINTERMISSION_H__
#define __EVENTWITHFIXEDINTERMISSION_H__

#include "../Event/Event.h"
#include "../Intermission/Intermission.h"

class EventWithFixedIntermission : public Event {
private:
  Time startIntermission;
  Intermission intermission;

public:
  // constructor
  EventWithFixedIntermission(Time startTime = Time(), Time endTime = Time(),
                             unsigned int maxDuration = 0,
                             Time startIntermission = Time());
};

#endif // __EVENTWITHFIXEDINTERMISSION_H__