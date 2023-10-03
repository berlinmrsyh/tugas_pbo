#include <iostream>
#include <iomanip>
#include "Account.h"
using namespace std;
 
Account::Account(int no, double b) : accountNumber(no), balance(b) { }
 
int Account::getAccountNumber() const {
   return accountNumber;
}
 
double Account::getBalance() const {
   return balance;
}
 
void Account::setBalance(double b) {
   balance = b;
}
 
void Account::credit(double amount) {
   balance += amount;
}
 
void Account::debit(double amount) {
   if (amount <= balance) {
      balance -= amount;
   } else {
      cout << "Amount withdrawn exceeds the current balance!" << endl;
   }
}
 
void Account::print() const {
   cout << fixed << setprecision(2);
   cout << "A/C no: " << accountNumber << " Balance=$" << balance << endl;
}