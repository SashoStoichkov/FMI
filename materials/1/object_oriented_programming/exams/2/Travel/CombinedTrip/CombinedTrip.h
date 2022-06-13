#ifndef __COMBINEDTRIP_H__
#define __COMBINEDTRIP_H__

#include "../AirTravel/AirTravel.h"
#include "../CarTravel/CarTravel.h"

class CombinedTrip : public AirTravel, public CarTravel {
private:
  unsigned int numberOfDestinations;
  char **destinations;
  unsigned int freeTime;

public:
  CombinedTrip(char *flightNumber = nullptr, unsigned int flightDuration = 0,
               unsigned int *carRegNumb = nullptr, double carDistance = 0.0,
               unsigned int carDuration = 0,
               unsigned int numberOfDestinations = 0,
               char **destinations = nullptr, unsigned int freeTime = 0);

  ~CombinedTrip();

  unsigned int getNumberOfDestinations() const;
  char **getDestinations() const;
  unsigned int getFreeTime() const;

  unsigned int getDuration() const;
  void print() const;
};

#endif // __COMBINEDTRIP_H__