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

    // Fixed: Invalid pointer access
    int transaction = 0;

    cout << transaction << endl;
}

void doubleDeleteIssue() {

    // Fixed: Double delete
    int* ptr = new int(50);

    delete ptr;

    // No need to delete again
}

void useAfterFreeIssue() {

    // Fixed: Use after free
    int* ptr = new int(100);

    delete ptr;

    // Do not access freed memory
}