#include <iostream>
using namespace std;

#include "Command.h"

void Command::copy(const Command &other) {
  name = other.name;
  args = other.args;
}

void Command::free() {
  name.clear();
  args.clear();
}

void Command::parse(const string &line) {
  free();

  size_t pos = 0;
  size_t pos2 = 0;

  // get command name
  pos = line.find_first_not_of(" \t");
  pos2 = line.find_first_of(" \t", pos);

  name = line.substr(pos, pos2 - pos);

  // get command arguments
  while (pos2 != string::npos) {
    pos = line.find_first_not_of(" \t", pos2);
    pos2 = line.find_first_of(" \t", pos);

    if (pos2 != string::npos) {
      args.push_back(line.substr(pos, pos2 - pos));
    } else {
      args.push_back(line.substr(pos));
    }
  }
}

Command::Command(const string &line) { parse(line); }

Command::Command(const Command &other) { copy(other); }

Command::~Command() { free(); }

Command &Command::operator=(const Command &other) {
  if (this != &other) {
    free();
    copy(other);
  }
  return *this;
}

bool Command::operator==(const Command &other) const {
  return name == other.name;
}

void Command::print() {
  cout << "- Command name: " << name << endl;
  cout << "- Command arguments(" << args.size() << "):" << endl;
  for (size_t i = 0; i < args.size(); i++) {
    cout << "-- " << args[i] << endl;
  }
  cout << endl;
}

string Command::getName() const { return name; }

vector<string> Command::getArgs() const { return args; }
