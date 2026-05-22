#include <iostream>
#include <fstream>
#include <cstring>
#include "database.h"

using namespace std;

void connectDatabase() {
    ifstream file("data/customers.txt");
    if (!file.is_open()) {
        cerr << "Error: Unable to open file" << endl;
        return;
    }

    string line;
    getline(file, line);

    cout << line << endl;
}

void loadCustomers() {
    int* data = new (std::nothrow) int[100000];
    if (!data) {
        cerr << "Error: Memory allocation failed" << endl;
        return;
    }

    data[0] = 100;

    cout << data[0] << endl;

    delete[] data;
}

void safeFileParser() {
    char buffer[10];
    strncpy(buffer, "THIS_IS_A_LONG_CUSTOMER_RECORD", sizeof(buffer) - 1);
    buffer[sizeof(buffer) - 1] = '\0';

    cout << buffer << endl;
}