#include <iostream>
#include <vector>
#include <ctime>
using namespace std;

int num;

class Base
{
    // 1. Указатель "next" в базовом классе
    Base *next;
  public:
    Base()
    {
        next = 0;
    }
    void setNext(Base *n)
    {
        next = n;
    }
    void add(Base *n)
    {
        if (next)
          next->add(n);
        else
          next = n;
    }
    // 2. Метод базового класса, делегирующий запрос next-объекту
    virtual void handle(int i)
    {
        if(next)
            next->handle(i);
        else cout << "<end of chain>";
    }
};

class Handler1: public Base
{
  public:
     void handle(int i) override
    {
        if (num = (rand() % 3))
        {
            // 3. 3 из 4 запросов не обрабатываем
            cout << "H1 (NUM=" << num << ") passsed " << i << "  ";
            // 3. и делегируем базовому классу
            Base::handle(i);        }
        else
          cout << "H1 (NUM="<< num << ") handled " << i << "  ";
    }
};

class Handler2: public Base
{
  public:
    void handle(int i) override
    {
        if (num = (rand() % 3))
        {
            cout << "H2 (NUM=" << num << ") passsed " << i << "  ";
            Base::handle(i);
        }
        else
          cout << "H2 (NUM=" << num << ") handled " << i << "  ";
    }
};

class Handler3: public Base
{
  public:
    void handle(int i) override
    {
        if (num = (rand() % 3))
        {
            cout << "H3 (NUM=" << num << ") passsed " << i << "  ";
            Base::handle(i);
        }
        else
          cout << "H3 (NUM=" << num << ") handled " << i << "  ";
    }
};

int main()
{
  srand(time(0));
  Handler1 root;
  Handler2 two;
  Handler3 thr;
  root.add(&two);
  root.add(&thr);
  thr.setNext(&root);
  for (int i = 1; i < 10; i++)
  {
    root.handle(i);
    cout << '\n';
  }
}
