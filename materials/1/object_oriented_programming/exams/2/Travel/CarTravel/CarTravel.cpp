#include <iostream>
using namespace std;

#include "CarTravel.h"

CarTravel::CarTravel(unsigned int *regNumb, double distance,
                     unsigned int duration)
    : regNumb(new unsigned int[4]), distance(distance), duration(duration) {
  for (int i = 0; i < 4; i++) {
    this->regNumb[i] = regNumb[i];
  }
}

CarTravel::~CarTravel() { delete[] regNumb; }

CarTravel::CarTravel(const CarTravel &other) {
  if (this != &other) {
    for (int i = 0; i < 4; i++) {
      this->regNumb[i] = other.getregNumb()[i];
    }

    this->distance = other.getDistance();
    this->duration = other.getDuration();
  }
}

CarTravel &CarTravel::operator=(const CarTravel &other) {
  if (this != &other) {
    for (int i = 0; i < 4; i++) {
      this->regNumb[i] = other.getregNumb()[i];
    }

    this->distance = other.getDistance();
    this->duration = other.getDuration();
  }

  return *this;
}

unsigned int *CarTravel::getregNumb() const { return this->regNumb; }
double CarTravel::getDistance() const { return this->distance; }
unsigned int CarTravel::getDuration() const { return this->duration; }