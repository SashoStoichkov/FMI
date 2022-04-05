#include "command.h"

Command::Command(char name) : name(name) {}

char Command::getName() { return name; }
