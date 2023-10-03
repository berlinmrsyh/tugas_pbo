#include <iostream>
#include "Account.h"
 
using namespace std;
 
int main() {
    Account a1(8111, 99.99);
    a1.print();   
    a1.credit(20);
    a1.debit(10);
    a1.print();   
 
    Account a2(8222);  
    a2.print();       
    a2.setBalance(100);
    a2.credit(20);
    a2.debit(200);  
    a2.print();    
    return 0;
}