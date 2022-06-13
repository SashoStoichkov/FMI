#include <iostream>
using namespace std;

#include "EventWithFixedIntermission.h"

EventWithFixedIntermission::EventWithFixedIntermission(Time startTime,
                                                       Time endTime,
                                                       unsigned int maxDuration,
                                                       Time startIntermission)
    : Event(startTime, endTime, maxDuration), intermission(Intermission(20)),
      startIntermission(startIntermission) {}