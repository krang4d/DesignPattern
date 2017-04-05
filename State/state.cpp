#include "state.h"

IState::~IState()
{
    cout << "   Base::dtor()\n";
}

ON::ON()
{
    cout << "   ON::ctor()\n";
}
ON::~ON()
{
    cout << "   ON::dtor()\n";
}


void ON::off(Machine *m)
{
  cout << "   going from ON to OFF\n";
  m->setCurrent(new OFF());
  delete this;
}

void ON::on(Machine *m)
{
    this->info();
}

void ON::info()
{
    cout << "   ON::info() --> already ON\n";
}

OFF::OFF()
{
    cout << "   OFF::ctor()\n";
}

OFF::~OFF()
{
    cout << "   OFF::dtor()\n";
}

void OFF::off(Machine *m)
{
    this->info();
}

void OFF::on(Machine *m)
{
    cout << "   going from OFF to ON\n";
    m->setCurrent(new ON());
    delete this;
}

void OFF::info()
{
    cout << "   OFF::info() --> already OFF\n";
}

