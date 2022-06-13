#include <cstring>
#include <iostream>
using namespace std;

#include "AirTravel.h"

AirTravel::AirTravel(char *flightNumber, unsigned int duration)
    : flightNumber(new char[strlen(flightNumber) + 1]), duration(duration) {
  strcpy(this->flightNumber, flightNumber);
}

AirTravel::~AirTravel() { delete[] flightNumber; }

AirTravel::AirTravel(const AirTravel &other) {
  if (this != &other) {
    delete[] this->flightNumber;

    this->flightNumber = new char[strlen(other.getFlightNumber()) + 1];
    strcpy(this->flightNumber, other.getFlightNumber());
    this->duration = other.getDuration();
  }
}

AirTravel &AirTravel::operator=(const AirTravel &other) {
  if (this != &other) {
    delete[] this->flightNumber;

    this->flightNumber = new char[strlen(other.getFlightNumber()) + 1];
    strcpy(this->flightNumber, other.getFlightNumber());
    this->duration = other.getDuration();
  }

  return *this;
}

char *AirTravel::getFlightNumber() const { return this->flightNumber; }
unsigned int AirTravel::getDuration() const { return this->duration; }