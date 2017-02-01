#include <iostream>
#include <vector>
#include <thread>

#define NUM_OF_THREAD 10000

using namespace std;

class OnlyOne
{
public:
        static const OnlyOne& GetInstance()
        {
                static OnlyOne theSingleInstance;
                return theSingleInstance;
        }
        static int instanse;
private:
        OnlyOne(){}
        OnlyOne(const OnlyOne&);
        OnlyOne& operator=(const OnlyOne&);
};

int OnlyOne::instanse;

void threadFunction(const OnlyOne &one)
{
    one.instanse+=1;
}

int main()
{
    cout << "***Design Pattern - SINGLETON***" << endl;
    //const OnlyOne p = OnlyOne::GetInstance();
    thread one(threadFunction, ref(OnlyOne::GetInstance()));
    thread two(threadFunction, ref(OnlyOne::GetInstance()));
    one.join();
    two.join();


    vector<thread> thr(NUM_OF_THREAD);

    vector<thread>::iterator thread_iterator;
    for(int i=0; i<NUM_OF_THREAD; i++){
        thr.at(i) = thread(threadFunction, ref(OnlyOne::GetInstance()));
    }
    for(int i=0; i<NUM_OF_THREAD; i++){
        thr.at(i).join();
    }
    //thr[0](htreadFunction, std::ref(i));

    cout << OnlyOne::GetInstance().instanse << endl;
    return 0;
}

