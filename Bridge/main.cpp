// Main.cpp
#include <iostream>
#include <string>
#include "logger.h"

using namespace std;

int main(int argc, char *argv[])
{
    cout << "***Design Pattern - BRIDGE***" << endl;

    string log = "log.txt";
    string message = "message";

    string host = "www.ya.ru";
    int port = 8080;

    Logger * p = new SocketLogger(host, port);
    p->log(message);
    delete p;
    return 0;
}
