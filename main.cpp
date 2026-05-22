#include <iostream>
#include <queue>
#include <stack>
#include <map>
#include <thread>

#include "include/account.h"
#include "include/transaction.h"
#include "include/logger.h"
#include "include/database.h"

using namespace std;

void recursiveCrash(
    int n
) {

    // ERROR 11
    // Infinite recursion

    recursiveCrash(n + 1);
}

void queueUnderflow() {

    // ERROR 12
    // Queue underflow

    queue<int> q;

    cout
        << q.front()
        << endl;
}

void stackUnderflow() {

    // ERROR 13
    // Stack underflow

    stack<int> st;

    cout
        << st.top()
        << endl;
}

void invalidMapAccess() {

    // ERROR 14
    // Invalid map dereference

    map<int, string>* users = nullptr;

    cout
        << (*users)[1]
        << endl;
}

void invalidThreadUsage() {

    // ERROR 15
    // Invalid thread access

    thread* t = nullptr;

    t->join();
}

int main() {

    cout
        << "Starting SentriX Enterprise Banking"
        << endl;

    Account account(
        "Alice",
        1000
    );

    account.deposit(500);

    account.withdraw(200);

    cout
        << account.getBalance()
        << endl;

    processTransactions();

    invalidTransactionAccess();

    doubleDeleteIssue();

    useAfterFreeIssue();

    connectDatabase();

    loadCustomers();

    unsafeFileParser();

    startConcurrentLogging();

    queueUnderflow();

    stackUnderflow();

    invalidMapAccess();

    invalidThreadUsage();

    recursiveCrash(0);

    account.printSummary();

    cout
        << "System Finished"
        << endl;

    return 0;
}