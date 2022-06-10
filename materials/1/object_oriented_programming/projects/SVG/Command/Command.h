#ifndef __COMMAND_H__
#define __COMMAND_H__

#include "../File/File.h"

#include <string>
#include <vector>
using namespace std;

class Command {
protected:
  string name;
  vector<string> args;

private:
  void copy(const Command &other);
  void free();

public:
  // constructor
  Command(const string &line = "");

  // copy constructor
  Command(const Command &other);

  // destructor
  ~Command();

  // copy assignment
  Command &operator=(const Command &other);

  // operator==
  bool operator==(const Command &other) const;

  void print();

  string getName() const;
  vector<string> getArgs() const;

  void parse(const string &line);

  virtual bool execute() = 0;

  static File file;
  static bool fileOpen;
  static string prompt;
};

#endif // __COMMAND_H__