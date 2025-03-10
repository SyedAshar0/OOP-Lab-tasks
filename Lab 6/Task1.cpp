#include <iostream>
#include <string>
using namespace std;
class BankAccount {
protected:
    string accountNumber;
    double balance;
    bool isFrozen; 

public:
    BankAccount(string accNum, double bal) : accountNumber(accNum), balance(bal), isFrozen(false) {}

    virtual void deposit(double amount) = 0;
    virtual void withdraw(double amount) = 0;
    void displayBalance() {
        cout << "Account " << accountNumber << " Balance:Rs" << balance << endl;
    }
    void freeze() {
         isFrozen = true;
        }
    void unfreeze(){
         isFrozen = false;
        }
    bool getFrozenStatus(){
        return isFrozen;
 }
};
class SavingsAccount : public BankAccount {
private:
    double interestRate;

public:
    SavingsAccount(string accNum, double bal, double rate) : BankAccount(accNum, bal), interestRate(rate) {}

    void deposit(double amount) override {
        if (isFrozen) {
            cout << "cant process Transaction because Account is frozen"<<endl;
            return;
        }
        balance += amount;
    }

    void withdraw(double amount) override {
        if (isFrozen) {
            cout << "cant process Transaction because Account is frozen"<<endl;
            return;
        }
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient funds"<<endl;
        }
    }

    void applyInterest() {
        balance += balance * interestRate;
    }
};

// Derived class for Checking Account
class CheckingAccount : public BankAccount {
private:
    double overdraftLimit;

public:
    CheckingAccount(string accNum, double bal, double limit) : BankAccount(accNum, bal), overdraftLimit(limit) {}

    void deposit(double amount) override {
        if (isFrozen) {
            cout << "cant process Transaction because Account is frozen"<<endl;
            return;
        }
        balance += amount;
    }

    void withdraw(double amount) override {
        if (isFrozen) {
            cout << "cant process Transaction because Account is frozen"<<endl;
            return;
        }
        if (balance - amount >= -overdraftLimit) {
            balance -= amount;
            if (balance < 0) {
                cout << "!Overdraft!"<<endl;
            }
        } else {
            cout << "Overdraft limit exceeded!\n";
        }
    }
};

// Derived class for Business Account
class BusinessAccount : public BankAccount {
private:
    double taxRate;

public:
    BusinessAccount(string accNum, double bal, double tax) : BankAccount(accNum, bal), taxRate(tax) {}

    void deposit(double amount) override {
        if (isFrozen) {
            cout << "cant process Transaction because Account is frozen"<<endl;
              return;
        }
        double tax = amount * taxRate;
        balance += (amount - tax);
    }

    void withdraw(double amount) override {
        if (isFrozen) {
            cout << "cant process Transaction because Account is frozen"<<endl;
            return;
        }
        if (balance >= amount) {
            balance -= amount;
        } else {
            cout << "Insufficient funds.\n";
        }
    }
};
class Employee {
protected:
    string name;
    int ID;

public:
    Employee(string n, int id) : name(n), ID(id) {}
    virtual void showInfo() {
        cout << "Employee: " << name << " | ID: " << ID << endl;
    }
};
class Customer {
private:
    BankAccount* account;

public:
    Customer(BankAccount* acc) : account(acc) {}

    void deposit(double amount) {
        account->deposit(amount);
    }

    void withdraw(double amount) {
        account->withdraw(amount);
    }

    void checkBalance() {
        account->displayBalance();
    }
};
class Teller : public Employee {
public:
    Teller(string n, int id) : Employee(n, id) {}

    void deposit(BankAccount* account, double amount) {
        account->deposit(amount);
    }

    void withdraw(BankAccount* account, double amount) {
        account->withdraw(amount);
    }

    void freezeAccount(BankAccount* account) {
        account->freeze();
        cout << "Account frozen by Teller.\n";
    }
};

class Manager : public Employee {
public:
    Manager(string n, int id) : Employee(n, id) {}

    void deposit(BankAccount* account, double amount) {
        account->deposit(amount);
    }

    void withdraw(BankAccount* account, double amount) {
        account->withdraw(amount);
    }

    void freezeAccount(BankAccount* account) {
        account->freeze();
        cout << "Account frozen by Manager.\n";
    }

    void unfreezeAccount(BankAccount* account) {
        account->unfreeze();
        cout << "Account unfrozen by Manager.\n";
    }
};

int main() {
    SavingsAccount savings("A256", 1500, 0.025);
    CheckingAccount checking("A540", 5700., 20.0);
    BusinessAccount business("B789", 780.0, 0.0579);
    Customer customer1(&savings);
    Teller teller1("Syed", 0101);
    Manager manager1("Ashar", 680);
    cout << "<-----Customer Transactions----->"<<endl;;
    customer1.deposit(200);
    customer1.withdraw(50);
    customer1.checkBalance();
    cout << "<-----Teller Transactions----->"<<endl;
    teller1.deposit(&checking, 300);
    teller1.withdraw(&checking, 600);
    teller1.freezeAccount(&checking);
    checking.withdraw(50);
    cout << "<----- Manager Transactions----->"<<endl;
    manager1.unfreezeAccount(&checking);
    checking.withdraw(50);
    business.deposit(500);
    return 0;
}
