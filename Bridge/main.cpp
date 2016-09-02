// Main.cpp
#include <iostream>
#include <string>
#include "logger.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "***Design Pattern - BRIDGE***" << endl;

    string log = "log.txt";

    string host = "www.ya.ru";
    int port = 8080;

    string message = "message";

    Logger *p0 = new ConsoleLogger();
    p0->log(message);
    delete p0;

    Logger *p1 = new FileLogger(log);
    p1->log(message);
    delete p1;

    Logger *p2 = new SocketLogger(host, port);
    p1->log(message);
    delete p2;
    return 0;
}
