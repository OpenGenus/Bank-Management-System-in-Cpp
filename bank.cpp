#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
using namespace std;

class BankAccount {
public:
    BankAccount(const string &number, const string &holder): accNumber(number), accHolder(holder), open(true), balance(0) {}
    
    void Withdraw(double amount) {
        if (open && amount <= balance && amount > 0) {
            balance -= amount;
            cout << "Successfully withdrew $" << amount << " from your account." << endl;
            cout << "Your new balance is: " << balance << endl;
        } else {
            cout << "Invalid amount provided or account is deactivated. Contact support for further assistance. " << endl;
        }
    }

    void Deposit(double amount) {
        if (open && amount > 0) {
            balance += amount;
            cout << "Successfully deposited $" << amount << " to your account." << endl;
            cout << "Your new balance is: " << balance << endl;
        } else {
            cout << "Invalid amount provided or account is deactivated. Contact support for further assistance. " << endl;
        }
    }

    void CloseAccount() {
        open = false;
        cout << "Your account, " << accNumber << "has been closed." << endl;
    }

private:
    string accNumber;
    string accHolder;
    bool open;
    double balance;

};

class UserManager {

public:
    UserManager() {
        loadUsersFromFile();
    }

    bool login() {
        string username, password;
        cout << "Enter username: ";
        cin >> username;

        if (users.find(username) != users.end()) {
            cout << "Enter password: ";
            cin >> password;

            if (users[username] == password) {
                return true;
            }
        }
        cout << "Incorrect username or password. Try again." << endl;
        return false;
    }

    void createUser(const string &username, const string &password) {
        users[username] = password;
        saveUsersToFile();
        cout << "User created successfully." << endl;
    }

private:
    unordered_map<string, string> users; // username -> password
    bool loadUsersFromFile() {
    ifstream userFile("users.txt");
    if (!userFile) {
        return false;
    }

    string line;
    while (getline(userFile, line)) {
        istringstream iss(line);
        string username, password;
        if (iss >> username >> password) {
            users[username] = password;
        }
    }

    userFile.close();
    return true;
}

    void saveUsersToFile() {
        ofstream userFile("users.txt");
        for (const auto &user : users) {
            userFile << user.first << " " << user.second << endl;
        }
        userFile.close();
    }
};
int main() {
    UserManager userManager;
    BankAccount acc("", "");
    int choice;
    int bankingOption;
    double withdrawAmt;
    double depositAmt;
    bool loggedIn = false;

    while (true) {
        if (!loggedIn) {
            cout << "1. Login\n2. Create Account\n3. Exit\n";
            cin >> choice;

            if (choice == 1) {
                if (userManager.login()) {
                    loggedIn = true;
                }
            } else if (choice == 2) {
                string username, password;
                cout << "Enter new username: ";
                cin >> username;
                cout << "Enter password: ";
                cin >> password;
                userManager.createUser(username, password);
            } else if (choice == 3) {
                break; // Exit the program
            }
        } else {
            cout << "1. Withdraw\n2. Deposit\n3. Close Account\n4. Logout\n";
            cin >> bankingOption;
            if (bankingOption == 1) {
                cout << "Please enter withdrawal amount: ";
                cin >> withdrawAmt;
                acc.Withdraw(withdrawAmt);
            }
            else if (bankingOption == 2) {
                cout << "Please enter deposit amount: ";
                cin >> depositAmt;
                acc.Deposit(depositAmt);
            }
            else if (bankingOption == 3) {
                acc.CloseAccount();
                loggedIn = false;
            }
            else if (bankingOption == 4) {
                loggedIn = false;
            }
        }
    }

    return 0;
}