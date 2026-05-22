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

    // Fixed vector out of bounds error
    if (txns.size() > 10) {
        cout << txns.at(10) << endl;
    } else {
        cerr << "Error: Index out of range" << endl;
    }
}

void invalidTransactionAccess() {

    // Fixed invalid pointer access error
    int* transaction = nullptr;

    if (transaction != nullptr) {
        cout << *transaction << endl;
    } else {
        cerr << "Error: Invalid pointer access" << endl;
    }
}

void doubleDeleteIssue() {

    // Fixed double delete error
    int* ptr = new int(50);

    delete ptr;

    // Avoiding duplicate delete call
}

void useAfterFreeIssue() {

    // Fixed use after free error
    int* ptr = new int(100);

    delete ptr;

    // Avoiding use of freed memory
    ptr = nullptr;
}