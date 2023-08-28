#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <sstream>
#include <vector>
#include <random> 
#include <set> 
using namespace std;

class Database {
public:
    Database() {
        loadUsersFromFile();
        loadManagersFromFile();
    }

    void saveUsersToFile() { // Save username and password to users.txt
        ofstream userFile("users.txt");
        for (const auto &user : users) {
            userFile << user.first << " " << user.second << endl;
        }
        userFile.close();
    }

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

    bool loadManagersFromFile() {
        ifstream managerFile("managers.txt");
        if (!managerFile) {
            return false;
        }

        string line;
        while (getline(managerFile, line)) {
            istringstream iss(line);
            string username, password;
            if (iss >> username >> password) {
                managers[username] = password;
            }
        }
        managerFile.close();
        return true;
    }

private:
    unordered_map<string, string> users;
    unordered_map<string, string> managers;
};

class Transaction {
public:
    string type; // Type of transaction
    double amount; // Amount transacted

    Transaction(const string &t, double a) : type(t), amount(a) {}
};


class UserManager {
public:
    UserManager(Database &db) : database(db) {} // Initializes UserManager with a reference to the database to allow for data access

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
        database.saveUsersToFile();
        cout << "User created successfully." << endl;
    }

    void deleteUser(const string &username) {
        users.erase(username);
    }

private:
    Database &database;
    unordered_map<string, string> users;
};

class BankAccount {
public:
    BankAccount(const string &username, Database &db) : username(username), open(true), balance(0), database(db) {}

    void Withdraw(double amount) {
        if (open && amount <= balance && amount > 0) {
            balance -= amount;
            transactions.emplace_back("Withdrawal", amount);
            cout << "Successfully withdrew $" << amount << " from your account." << endl;
            cout << "Your new balance is: " << balance << endl;
        } else {
            cout << "Invalid amount provided or account is deactivated. Contact support for further assistance. " << endl;
        }
    }

    void Deposit(double amount) {
        if (open && amount > 0) {
            balance += amount;
            transactions.emplace_back("Deposit", amount);
            cout << "Successfully deposited $" << amount << " to your account." << endl;
            cout << "Your new balance is: " << balance << endl;
        } else {
            cout << "Invalid amount provided or account is deactivated. Contact support for further assistance. " << endl;
        }
    }

    void PrintAccountSummary() {
        cout << "Account Holder: " << username << endl;
        cout << "Balance: $" << balance << endl;
        cout << "Transactions:" << endl;
        for (const Transaction &transaction : transactions) {
            cout << transaction.type << ", Amount: $" << transaction.amount << endl;
        }
        cout << " " << endl;
    }      

    void CloseAccount(UserManager &userManager) {
        open = false;
        userManager.deleteUser(username);
        database.saveUsersToFile();
        cout << "Your account has been closed." << endl;
    } 
    
    void setUsername(const string &newUsername) {
        username = newUsername;
    }

private:
    string username;
    bool open;
    double balance;
    vector<Transaction> transactions;
    Database &database;
};

class BankManager {
public:
    BankManager() {
        loadManagersFromFile();
    }
    bool login() {
        string username, password;
        cout << "Enter username: ";
        cin >> username;
        if (managers.find(username) != managers.end()) {
            cout << "Enter password: ";
            cin >> password;

            if (managers[username] == password) {
                return true;
            }
        }
        cout << "Incorrect login. Please try again. " << endl;
        return false;
    }

    bool loadManagersFromFile() {
        ifstream managerFile("managers.txt");
        if (!managerFile) {
            return false;
        }

        string line;
        while (getline(managerFile, line)) {
            istringstream iss(line);
            string username, password;
            if (iss >> username >> password) {
                managers[username] = password;
            }
        }
        managerFile.close();
        return true;
    }   

private:
    unordered_map<string, string> managers; 
};

int main() {
    Database database;
    UserManager userManager(database);
    BankManager manager;
    string username;
    BankAccount acc("", database);
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
    bool managerLoggedIn = false;
    while (true) {
        if (!loggedIn) {
            cout << "1. Login\n2. Create Account\n3. Manager Login\n4. Exit\n";
    while (true) {
        if (!loggedIn) {
            cout << "1. Login\n2. Create Account\n3. Exit\n";
            cin >> choice;

            if (choice == 1) {
                if (userManager.login()) {
                    loggedIn = true;
                    username = username;
                    acc.setUsername(username);// Initialize the BankAccount object
                }   
            } else if (choice == 2) {
                string newUsername, password;
                cout << "Enter new username: ";
                cin >> newUsername;
                cout << "Enter password: ";
                cin >> password;
                userManager.createUser(newUsername, password);
                username = newUsername;
                acc.setUsername(username);
            } else if (choice == 3) {
                if (manager.login()) {
                    loggedIn = true;
                    managerLoggedIn = true;
                    cout << "Manager Options\n";
                    cout << "1. Get List of Users and Account Details\n2. Logout\n";
                    cin >> bankingOption;
                    if (bankingOption == 1) {
                        ifstream userFile("users.txt");
                        if (userFile.is_open()) {
                            string line;
                            while (getline(userFile, line)) {
                                cout << line << endl;
                            }
                            userFile.close();
                        }
                    }
                    if (bankingOption == 2) {
                        managerLoggedIn = false;
                        loggedIn = false;
                    }
                }
            } else if (choice == 4) {
                break; // Exit the program
            }
        } else {
            if (managerLoggedIn) {
                cout << "Manager Options\n";
                cout << "1. Get List of Users and Account Details\n2. Logout\n";
                cin >> bankingOption;
                if (bankingOption == 1) {
                    ifstream userFile("users.txt");
                    if (userFile.is_open()) {
                        string line;
                        while (getline(userFile, line)) {
                            cout << line << endl;
                        }
                        userFile.close();
                    }
                }
                if (bankingOption == 2) {
                    loggedIn = false;
                }
            } else {
                cout << "User Options:\n";
                cout << "1. Withdraw\n2. Deposit\n3. Get Account Summary\n4. Close Account\n5. Logout\n";
                cin >> bankingOption;
                if (bankingOption == 1) {
                    cout << "Please enter withdrawal amount: ";
                    cin >> withdrawAmt;
                    acc.Withdraw(withdrawAmt);
                } else if (bankingOption == 2) {
                    cout << "Please enter deposit amount: ";
                    cin >> depositAmt;
                    acc.Deposit(depositAmt);
                } else if (bankingOption == 3) {
                    acc.PrintAccountSummary();
                } else if (bankingOption == 4) {
                    acc.CloseAccount(userManager);
                    loggedIn = false;
                } else if (bankingOption == 5) {
                    loggedIn = false;
                    }
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