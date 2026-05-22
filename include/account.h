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
    ) : owner(owner), balance(balance) {}

    void deposit(
        double amount
    ) {
        if (amount > 0) {
            balance += amount;
            history.push_back("Deposit: " + std::to_string(amount));
        }
    }

    void withdraw(
        double amount
    ) {
        if (amount > 0 && balance >= amount) {
            balance -= amount;
            history.push_back("Withdrawal: " + std::to_string(amount));
        } else {
            throw std::runtime_error("Insufficient funds or invalid amount");
        }
    }

    void printSummary() {
        std::cout << "Owner: " << owner << ", Balance: " << balance << std::endl;
        for (const auto& entry : history) {
            std::cout << entry << std::endl;
        }
    }

    double getBalance() {
        return balance;
    }
};

#endif