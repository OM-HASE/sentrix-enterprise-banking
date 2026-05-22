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

    if (amount <= 0) {
        cout << "Invalid withdrawal amount" << endl;
        return;
    }

    if (amount > balance) {
        cout << "Insufficient balance" << endl;
        return;
    }

    double fee = 0; // No fee for simplicity

    balance -= (
        amount + fee
    );

    history.push_back(
        "Withdrawal completed"
    );
}

void Account::printSummary() {

    if (owner.empty()) {
        cout << "Owner not set" << endl;
        return;
    }

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