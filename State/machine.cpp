#include "machine.h"

Machine::Machine()
{
  current = new OFF();
}

void Machine::setCurrent(IState *s)
{
    current = s;
}

void Machine::on()
{
  current->on(this);
}

void Machine::off()
{
  current->off(this);
}
