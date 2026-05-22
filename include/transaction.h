#ifndef TRANSACTION_H
#define TRANSACTION_H

#include <vector>
#include <stdexcept>

void processTransactions() {
    // Implementation of processTransactions
}

void invalidTransactionAccess() {
    try {
        std::vector<int> transactions = {1, 2, 3};
        int value = transactions.at(10); // This will throw an exception
    } catch (const std::out_of_range& e) {
        // Handle the out of range error safely
        std::cerr << "Error: " << e.what() << std::endl;
    }
}

void doubleDeleteIssue() {
    int* ptr = new int(10);
    delete ptr;
    delete ptr; // This will cause a double free
}

void useAfterFreeIssue() {
    int* ptr = new int(10);
    delete ptr;
    *ptr = 20; // This will cause a use after free
}

#endif