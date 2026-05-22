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

    if (n >= 1000) return; // Prevent infinite recursion
    recursiveCrash(n + 1);
}

void queueUnderflow() {
    // ERROR 12
    // Queue underflow

    queue<int> q;
    if (!q.empty()) {
        cout << q.front() << endl;
    } else {
        cerr << "Queue is empty" << endl;
    }
}

void stackUnderflow() {
    // ERROR 13
    // Stack underflow

    stack<int> st;
    if (!st.empty()) {
        cout << st.top() << endl;
    } else {
        cerr << "Stack is empty" << endl;
    }
}

void invalidMapAccess() {
    // ERROR 14
    // Invalid map dereference

    map<int, string> users;
    users[1] = "Alice";
    if (users.find(1) != users.end()) {
        cout << users[1] << endl;
    } else {
        cerr << "User not found" << endl;
    }
}

void invalidThreadUsage() {
    // ERROR 15
    // Invalid thread access

    thread t([]() {
        cout << "Thread running" << endl;
    });
    t.join();
}

int main() {
    cout << "Starting SentriX Enterprise Banking" << endl;

    Account account("Alice", 1000);
    account.deposit(500);
    account.withdraw(200);

    cout << account.getBalance() << endl;

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
    cout << "System Finished" << endl;

    return 0;
}