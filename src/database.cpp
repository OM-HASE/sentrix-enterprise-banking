#include <iostream>
#include <fstream>
#include <cstring>
#include "database.h"

using namespace std;

void connectDatabase() {

    ifstream file(
        "data/customers.txt"
    );

    // ERROR 8
    // File open failure

    string line;

    getline(file, line);

    cout
        << line
        << endl;
}

void loadCustomers() {

    // ERROR 9
    // Memory leak

    int* data = new int[100000];

    data[0] = 100;

    cout
        << data[0]
        << endl;
}

void unsafeFileParser() {

    // ERROR 10
    // Buffer overflow

    char buffer[10];

    strcpy(
        buffer,
        "THIS_IS_A_LONG_CUSTOMER_RECORD"
    );

    cout
        << buffer
        << endl;
}