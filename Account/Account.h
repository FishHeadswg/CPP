#ifndef ACCOUNT_H_INCLUDED
#define ACCOUNT_H_INCLUDED
/***********************
Trevor Richardson
Account.h
***********************/
#include <iostream>
using namespace std;
#include "../AcountMhcrnl/persoana.h"
#include <string>
class Account: public Persoana{
private:
  int balance; // data member that stores the balance
    string _beneficiar;
public:
    Account();
  Account( int ); // constructor initializes balance
  Account (string nume, string prenume, int balance);
  void credit( int ); // add an amount to the account balance
  void debit( int ); // subtract an amount to the account balance
  int getBalance(); // return the account balance
  int plata(void);
  /**
      Add friend function for print Account
  */
  friend ostream& operator<<(ostream& os, const Account& cont);
}; // end class Account
#endif
