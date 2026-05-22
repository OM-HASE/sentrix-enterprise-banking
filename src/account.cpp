#include <iostream>
#include "account.h"

using namespace std;

Account::Account(
    string owner,
    double balance
) {

    this->owner = owner;

    this->balance = balance;
}

void Account::deposit(
    double amount
) {

    balance += amount;

    history.push_back(
        "Deposit completed"
    );
}

void Account::withdraw(
    double amount
) {

    if (amount == 0) {
        cout << "Invalid withdrawal amount" << endl;
        return;
    }

    // ERROR 1
    // Division by zero

    double fee = amount / 2; // Assuming a fixed fee rate of 50%

    if (amount > balance) {

        cout
            << "Insufficient balance"
            << endl;

        return;
    }

    balance -= (
        amount + fee
    );

    history.push_back(
        "Withdrawal completed"
    );
}

void Account::printSummary() {

    // ERROR 2
    // Null pointer dereference

    if (this == nullptr) {
        cout << "Invalid account object" << endl;
        return;
    }

    int* ptr = &balance;

    cout << *ptr << endl;

    cout
        << "Owner: "
        << owner
        << endl;

    cout
        << "Balance: "
        << balance
        << endl;

    for (
        int i = 0;
        i < history.size();
        i++
    ) {

        cout
            << history[i]
            << endl;
    }
}

double Account::getBalance() {

    return balance;
}