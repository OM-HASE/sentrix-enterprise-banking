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

    // ERROR 1
    // Division by zero

    double fee = amount / 0;

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

    int* ptr = nullptr;

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