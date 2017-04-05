#ifndef STATE_H
#define STATE_H
#include "iostream"
#include "machine.h"

using namespace std;

class Machine;

class IState
{
public:
    virtual void on(Machine *m) = 0;
    virtual void off(Machine *m) = 0;
    virtual ~IState() = 0;
protected:
    virtual void info() = 0;
};

class ON: public IState
{
public:
    ON();
    ~ON();
    void on(Machine *m) override;
    void off(Machine *m) override;
protected:
    void info() override;
};

class OFF: public IState
{
public:
    OFF();
    ~OFF();
    void on(Machine *m) override;
    void off(Machine *m) override;
protected:
    void info() override;
};

#endif // STATE_H
