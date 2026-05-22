#include <iostream>
#include <fstream>
#include <cstring>
#include "database.h"

using namespace std;

void connectDatabase() {
    ifstream file("data/customers.txt");
    if (!file.is_open()) {
        cerr << "Failed to open file" << endl;
        return;
    }

    string line;
    getline(file, line);

    cout << line << endl;
}

void loadCustomers() {
    int* data = new (std::nothrow) int[100000];
    if (!data) {
        cerr << "Memory allocation failed" << endl;
        return;
    }

    data[0] = 100;

    cout << data[0] << endl;

    delete[] data;
}

void safeFileParser() {
    char buffer[10];
    const char* record = "THIS_IS_A_LONG_CUSTOMER_RECORD";
    size_t len = strlen(record);
    if (len >= sizeof(buffer)) {
        cerr << "Buffer overflow detected" << endl;
        return;
    }

    strcpy(buffer, record);

    cout << buffer << endl;
}