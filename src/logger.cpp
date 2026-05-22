#include <iostream>
#include <fstream>
#include <thread>
#include "logger.h"

using namespace std;

ofstream logfile(
    "banking.log"
);

void logMessage(
    string message
) {

    logfile
        << message
        << endl;
}

void startConcurrentLogging() {

    static int counter = 0;

    auto worker = []() {

        for (
            int i = 0;
            i < 100000;
            i++
        ) {

            // ERROR 7
            // Race condition

            counter++;
        }
    };

    thread t1(worker);

    thread t2(worker);

    t1.join();

    t2.join();

    cout
        << counter
        << endl;
}