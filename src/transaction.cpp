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

    // ERROR 3
    // Vector out of bounds

    cout
        << txns.at(10)
        << endl;
}

void invalidTransactionAccess() {

    // ERROR 4
    // Invalid pointer access

    int* transaction;

    cout
        << *transaction
        << endl;
}

void doubleDeleteIssue() {

    // ERROR 5
    // Double delete

    int* ptr = new int(50);

    delete ptr;

    delete ptr;
}

void useAfterFreeIssue() {

    // ERROR 6
    // Use after free

    int* ptr = new int(100);

    delete ptr;

    cout
        << *ptr
        << endl;
}