#include <cstring>
#include <iostream>
#include <ostream>
using namespace std;

#include "CombinedTrip.h"

CombinedTrip::CombinedTrip(char *flightNumber, unsigned int flightDuration,
                           unsigned int *carRegNumb, double carDistance,
                           unsigned int carDuration,
                           unsigned int numberOfDestinations,
                           char **destinations, unsigned int freeTime)
    : AirTravel(flightNumber, flightDuration),
      CarTravel(carRegNumb, carDistance, carDuration),
      numberOfDestinations(numberOfDestinations),
      destinations(new char *[numberOfDestinations]), freeTime(freeTime) {
  for (int i = 0; i < numberOfDestinations; i++) {
    this->destinations[i] = new char[strlen(destinations[i] + 1)];
    strcpy(this->destinations[i], destinations[i]);
  }
}

CombinedTrip::~CombinedTrip() {
  for (int i = 0; i < numberOfDestinations; i++) {
    delete[] destinations[i];
  }

  delete[] destinations;
}

unsigned int CombinedTrip::getNumberOfDestinations() const {
  return numberOfDestinations;
}

char **CombinedTrip::getDestinations() const { return destinations; }

unsigned int CombinedTrip::getFreeTime() const { return freeTime; }

unsigned int CombinedTrip::getDuration() const {
  return AirTravel::getDuration() + CarTravel::getDuration() + getFreeTime();
}

void CombinedTrip::print() const {
  cout << "### Trip info: ###" << endl << endl;

  cout << "<< AirTravel info >>" << endl;
  cout << "Flight Number: " << AirTravel::getFlightNumber() << endl;
  cout << "Flight Duration: " << AirTravel::getDuration() << " minutes" << endl
       << endl;

  cout << "<< CarTravel info >>" << endl;
  cout << "Car RegNumber: " << CarTravel::getregNumb() << endl;
  cout << "Car Distance: " << CarTravel::getDistance() << " km" << endl;
  cout << "Car Duration: " << CarTravel::getDuration() << " minutes" << endl
       << endl;

  cout << "<< CombinedTrip info >>" << endl;
  cout << "Destinations (" << getNumberOfDestinations() << "): " << endl;
  for (int i = 0; i < getNumberOfDestinations(); i++) {
    cout << " - Destination No. " << i + 1 << ": " << getDestinations()[i]
         << endl;
  }
  cout << "Free time: " << getFreeTime() << " minutes" << endl;
}
