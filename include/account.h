#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <string>
#include <vector>

class Account {

private:

    double balance;

public:

    std::string owner;

    std::vector<std::string> history;

    Account(
        std::string owner,
        double balance
    );

    void deposit(
        double amount
    );

    void withdraw(
        double amount
    );

    void printSummary();

    double getBalance();
};

#endif