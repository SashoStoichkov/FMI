#ifndef __AIRTRAVEL_H__
#define __AIRTRAVEL_H__

class AirTravel {
private:
  char *flightNumber;
  unsigned int duration;

public:
  // constructor
  AirTravel(char *flightNumber = nullptr, unsigned int duration = 0);

  // destructor
  ~AirTravel();

  // copy constructor
  AirTravel(const AirTravel &other);

  // copy assignment
  AirTravel &operator=(const AirTravel &other);

  // getters
  char *getFlightNumber() const;
  unsigned int getDuration() const;
};

#endif // __AIRTRAVEL_H__