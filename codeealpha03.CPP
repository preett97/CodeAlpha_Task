#include <iostream>
#include <vector>
using namespace std;

class Transaction {
public:
    string type;
    double amount;
    string date;


    Transaction(string t, double a, string d) {
        type = t;
        amount = a;
        date = d;
    }

    void displayTransaction() {
        cout << type << " of Rs. " << amount << " on " << date << endl;
    }
};

class Account {
private:
    string accountNumber;
    double balance;
    vector<Transaction> transactions;

public:
    Account(string accNo, double initialBalance) {
        accountNumber = accNo;
        balance = initialBalance;
    }

    string getAccountNumber() {
        return accountNumber;
    }

    double getBalance() {
        return balance;
    }

    void deposit(double amount, string date) {
        balance += amount;
        transactions.push_back(Transaction("Deposit", amount, date));
        cout << "Deposit successful. New Balance: Rs. " << balance << endl;
    }

    bool withdraw(double amount, string date) {
        if (amount > balance) {
            cout << "Insufficient balance!" << endl;
            return false;
        }
        balance -= amount;
        transactions.push_back(Transaction("Withdraw", amount, date));
        cout << "Withdrawal successful. New Balance: Rs. " << balance << endl;
        return true;
    }

    bool transfer(Account &toAccount, double amount, string date) {
        if (withdraw(amount, date)) {
            toAccount.deposit(amount, date);
            transactions.push_back(Transaction("Transfer to " + toAccount.getAccountNumber(), amount, date));
            return true;
        }
        return false;
    }

    void showTransactionHistory() {
        cout << "\nTransaction History for Account " << accountNumber << ":\n";
        for (int i = 0; i < transactions.size(); ++i) {
            transactions[i].displayTransaction();
        }
    }
};

class Customer {
private:
    string name;
    string customerID;
    Account account;

public:
    Customer(string n, string id, string accNo, double initialBalance)
        : account(accNo, initialBalance) {
        name = n;
        customerID = id;
    }

    string getCustomerID() {
        return customerID;
    }

    void showCustomerInfo() {
        cout << "Customer Name: " << name << endl;
        cout << "Customer ID: " << customerID << endl;
        cout << "Account Number: " << account.getAccountNumber() << endl;
        cout << "Account Balance: Rs. " << account.getBalance() << endl;
    }

    Account& getAccount() {
        return account;
    }
};

Customer* findCustomerByID(vector<Customer>& customers, const string& id) {
    for (int i = 0; i < customers.size(); ++i) {
        if (customers[i].getCustomerID() == id) {
            return &customers[i];
        }
    }
    return NULL;  // Use NULL instead of nullptr in C++98
}

int main() {
    vector<Customer> customers;
    customers.push_back(Customer("Ali Khan", "C123", "A001", 10000));
    customers.push_back(Customer("Sara Malik", "C124", "A002", 8000));
    customers.push_back(Customer("Preet Sarfraz", "C125", "A003", 12000));

    string selectedID;
    cout << "Enter Customer ID to login (e.g., C123): ";
    cin >> selectedID;

    Customer* currentCustomer = findCustomerByID(customers, selectedID);
    if (!currentCustomer) {
        cout << "Customer ID not found! Exiting...\n";
        return 1;
    }

    int choice;
    double amount;
    string date = "10-05-2025";

    do {
        cout << "\n===== BANKING SYSTEM =====\n";
        cout << "1. Deposit\n";
        cout << "2. Withdraw\n";
        cout << "3. Transfer\n";
        cout << "4. View Account Info\n";
        cout << "5. View Transaction History\n";
        cout << "0. Exit\n";
        cout << "Select an option: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter amount to deposit: Rs. ";
                cin >> amount;
                currentCustomer->getAccount().deposit(amount, date);
                break;

            case 2:
                cout << "Enter amount to withdraw: Rs. ";
                cin >> amount;
                currentCustomer->getAccount().withdraw(amount, date);
                break;

            case 3:
            {
                string toID;  // Declare 'toID' at the beginning of the block
                cout << "Enter recipient Customer ID: ";
                cin >> toID;
                
                Customer* toCustomer;
                toCustomer = findCustomerByID(customers, toID);
                
                if (!toCustomer) {
                    cout << "Recipient not found!\n";
                    break;
                }

                cout << "Enter amount to transfer: Rs. ";
                cin >> amount;
                currentCustomer->getAccount().transfer(toCustomer->getAccount(), amount, date);
                break;
            }

            case 4:
                currentCustomer->showCustomerInfo();
                break;

            case 5:
                currentCustomer->getAccount().showTransactionHistory();
                break;

            case 0:
                cout << "Exiting program...\n";
                break;

            default:
                cout << "Invalid choice. Try again.\n";
        }
    } while (choice != 0);

    return 0;
}

