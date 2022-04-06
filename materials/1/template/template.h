#ifndef __TEMPLATE_H__
#define __TEMPLATE_H__

class Template {
private:
  // attributes
  // ...

  void copy(const Template &other);
  void free();

public:
  // constructor
  Template(/* attributes */);

  // copy constructor
  Template(const Template &other);

  // move constructor
  Template(Template &&other);

  // destructor
  ~Template();

  // copy assignment
  Template &operator=(const Template &other);

  // move assignment
  Template &operator=(Template &&other);

  // other methods
  // ...
};

#endif // __TEMPLATE_H__