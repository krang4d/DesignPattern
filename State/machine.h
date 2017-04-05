#ifndef MACHINE_H
#define MACHINE_H

#include "iostream"
#include "state.h"

using namespace std;

class IState;

class Machine
{
public:
    Machine();
    void setCurrent(IState *s);
    void on();
    void off();
protected:
    IState *current;
};

#endif // MACHINE_H
