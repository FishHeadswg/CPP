/***********************
Trevor Richardson
Account.cpp
***********************/
#include <iostream>
using namespace std; // Forgive me

#include "Account.h"

// Account constructor initializes data member balance
Account::Account( int initialBalance )
{
  balance = 0; // assume that the balance begins at 0
  /* if initialBalance is greater than 0, 
  set this value as the balance of the Account; otherwise, balance remains 0 */
  if ( initialBalance > 0 )
    balance = initialBalance;

  // if initialBalance is negative, print error message
  if ( initialBalance < 0 )
    cout << "Error: Initial balance cannot be negative.\n" << endl;
} // end Account constructor

// credit (add) an amount to the account balance
void Account::credit( int amount )
{
  balance += amount; // add amount to balance
} // end function credit

/* defines member function debit. */
void Account::debit( int amount)
{
	if ( amount > balance)
		cout << "Debit amount exceeded account balance of $" << balance << "\n" << endl;
	if (amount < 0)
		cout << "You cannot withdraw negative amounts\n" << endl;
	if (amount <= balance && amount >= 0)
		balance -= amount;
}
// return the account balance
int Account::getBalance()
{
  return balance; // gives the value of balance to the calling function
} // end function getBalance