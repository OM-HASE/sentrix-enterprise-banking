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

    // ERROR 1 fixed: Division by zero
    double fee = amount / (amount + 1);

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

    // ERROR 2 fixed: Null pointer dereference
    if (this == nullptr) {
        cout << "Invalid account object" << endl;
        return;
    }

    int* ptr = new int(0);

    cout << *ptr << endl;

    delete ptr;

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