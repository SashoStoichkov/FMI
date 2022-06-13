#ifndef __INTERMISSION_H__
#define __INTERMISSION_H__

class Intermission {
private:
  unsigned int duration;

public:
  // constructor
  Intermission(unsigned int duration = 0);

  // copy constructor
  Intermission(const Intermission &other);

  // copy assignment
  Intermission &operator=(const Intermission &other);

  // getter
  unsigned int getDuration() const;
};

#endif // __INTERMISSION_H__