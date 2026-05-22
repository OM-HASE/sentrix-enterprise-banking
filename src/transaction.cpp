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
    int* transaction = nullptr;

    if (transaction != nullptr) {
        cout << *transaction << endl;
    } else {
        cerr << "Error: Null pointer dereference" << endl;
    }
}

void doubleDeleteIssue() {

    // Fixed: Double delete
    int* ptr = new int(50);

    delete ptr;

    // Avoid duplicate delete call
}

void useAfterFreeIssue() {

    // Fixed: Use after free
    int* ptr = new int(100);

    delete ptr;

    // Avoid accessing freed memory
    ptr = nullptr;
}