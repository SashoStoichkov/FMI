#ifndef __CARTRAVEL_H__
#define __CARTRAVEL_H__

class CarTravel {
private:
  unsigned int *regNumb;
  double distance;
  unsigned int duration;

public:
  // constructor
  CarTravel(unsigned int *regNumb = nullptr, double distance = 0.0,
            unsigned int duration = 0);

  // destructor
  ~CarTravel();

  // copy constructor
  CarTravel(const CarTravel &other);

  // copy assignment
  CarTravel &operator=(const CarTravel &other);

  // getters
  unsigned int *getregNumb() const;
  double getDistance() const;
  unsigned int getDuration() const;
};

#endif // __CARTRAVEL_H__