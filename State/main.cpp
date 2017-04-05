#include <iostream>
#include "state.h"
#include "machine.h"

using namespace std;

int main()
{
  void(Machine:: *ptrs[])() =
  {
    &Machine::on, &Machine::off
  };
  Machine fsm;
  int num;
  while (1)
  {
    cout << "Enter 0/1: ";
    cin >> num;
    (fsm.*ptrs[num])();
  }
}
