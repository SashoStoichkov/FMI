#ifndef __COMMAND_H__
#define __COMMAND_H__

class Command {
private:
    char name;
public:
    Command(char name = ' ');
    char getName();
};

#endif // __COMMAND_H__