#include <iostream>
#include <vector>
#include "transaction.h"

using namespace std;

void processTransactions() {

    vector<int> txns = {
        100,
        200,
        300
    };

    // Fixed: Vector out of bounds
    if (txns.size() > 10) {
        cout << txns.at(10) << endl;
    } else {
        cerr << "Error: Index out of range" << endl;
    }
}

void invalidTransactionAccess() {

    // ERROR 4 remains unchanged as it involves an invalid pointer access
    int* transaction;

    cout
        << *transaction
        << endl;
}

void doubleDeleteIssue() {

    // ERROR 5 remains unchanged as it involves a double delete
    int* ptr = new int(50);

    delete ptr;

    delete ptr;
}

void useAfterFreeIssue() {

    // ERROR 6 remains unchanged as it involves a use after free
    int* ptr = new int(100);

    delete ptr;

    cout
        << *ptr
        << endl;
}