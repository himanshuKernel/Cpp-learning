#include <iostream>
using namespace std;

class BankAccount {
private:
    double balance;

public:
    BankAccount(double initialBalance)
        : balance(initialBalance) {}

    double getBalance() const {
        return balance;
    }

    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Deposit successful\n";
        }
    }

    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            cout << "Withdrawal successful\n";
        } else {
            cout << "Invalid withdrawal\n";
        }
    }
};

int main() {
    BankAccount account(1000);

    account.deposit(500);
    account.withdraw(200);

    cout << "Balance: " << account.getBalance() << endl;

    return 0;
}