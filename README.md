# Bank-Management-System-in-Cpp
Simple Bank Management System in C++

### Description

A console-based bank management system programmed in C++. It allows users to create a bank account, login, and deposit/withdraw funds to and from their account. They also have the additional ability to close their account if they desire to do so, deleting their account data.

### Features
* Account creation, deletion, and login
* Users can deposit and withdraw funds from account as well as close their account
* Bank managers can view all account data located within users.txt

### Installing
* Copy bank.cpp to your system and compile the file:
g++ bank.cpp -o bank

* Then, run the program:
./bank

### Usage
* To create an account, enter 2 into terminal and provide a username and password. You can then use this login info to login. Even when exiting the program, your login information will be saved so you can log back in at anytime!
* Once successfully logged in, you have a couple of account options. Enter 1 to withdraw funds, 2 to deposit funds, 3 to close your account, and 4 to logout.
* To login as a manager, you must manually add your login information to a text file. You must name the file managers.txt for this to work. Then, use the login data within managers.txt to login as a bank manager. There are two manager options: 1. Get list of user and account details and 2. Logout.