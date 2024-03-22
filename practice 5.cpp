#include <iostream>
#include <string>
using namespace std;


class BankAccount
{
private:
    int accountNumber;
    double balance;
    double percentRate;

public:
    BankAccount(int accountNumber, double initializeBalance) {
        this->accountNumber = accountNumber;
        this->balance = initializeBalance;
        this->percentRate = 0;
    };

    void deposit(double amount) {
        if (amount > 0) {
            this->balance += amount;
            cout << "Внесено " << amount << " рублей на баланс: " << this->accountNumber << endl;
        }
        else {
            cout << "Неизвесное значение депозита" << endl;
        };
    };

    bool withdraw(double amount) {
        if (amount > 0 && amount <= this->balance) {
            this->balance -= amount;
            cout << "Выведено " << amount << " с аккаунта " << this->accountNumber << endl;
            return true;
        }
        else {
            cout << "Нельзя вывести данное значения со счёта" << endl;
            return false;
        };
    };

    double getBalance() {
        return this->balance;
    };

    double getPercent() {
        return this->balance * this->percentRate * 1 / 12;
    };

    void setPercentRate(double newRate) {
        this->percentRate = newRate;
    };

    int getAccountNumber() {
        return this->accountNumber;
    };

    bool transfer(BankAccount& from, BankAccount& to, double amount) {
        if (from.withdraw(amount)) {
            to.deposit(amount);
            cout << "Переведено " << amount << " с аккаунта " << from.getAccountNumber() << " на счёт аккаунта " << to.getAccountNumber() << endl;
        }
        else {
            return false;
        }
    }
};


int main() {
    setlocale(LC_ALL, "ru");

    int accountNumber1, accountNumber2;
    double balance1, balance2;

    cout << "Введите номер первого счета: ";
    cin >> accountNumber1;
    cout << "Введите баланс первого счета: ";
    cin >> balance1;

    cout << "Введите номер второго счета: ";
    cin >> accountNumber2;
    cout << "Введите баланс второго счета: ";
    cin >> balance2;

    BankAccount account1(accountNumber1, balance1);
    BankAccount account2(accountNumber2, balance2);

    account1.deposit(249.9);
    account2.withdraw(937.6);

    account1.setPercentRate(0.05);
    cout << "Проценты, полученные на счете 1: " << account1.getPercent() << endl;

    account1.transfer(account1, account2, 300.0);

    return 0;
}

