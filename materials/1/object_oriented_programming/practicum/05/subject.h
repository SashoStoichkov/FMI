#include "../../utils/string/string.h"

#ifndef __SUBJECT_H__
#define __SUBJECT_H__

class Subject {
private:
  String name;
  String description;

public:
  Subject(String name = "", String description = "");
  ~Subject();

  Subject &operator=(const Subject &subject);

  String getName();
  String getDescription();
};

#endif // __SUBJECT_H__