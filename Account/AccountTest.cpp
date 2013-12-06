/***********************
Trevor Richardson
AccountTest.cpp
***********************/
#include <iostream>
using namespace std; // Forgive me

#include "Account.h"

int main()
{
  Account account1( 50 ); // create Account object
  Account account2( 0 ); // create Account object

  // display initial balance of each object
  cout << "account1 balance: $" << account1.getBalance() << endl;
  cout << "account2 balance: $" << account2.getBalance() << endl;

  int withdrawalAmount; // stores withdrawal amount read from user

  cout << "\nEnter withdrawal amount for account1: "; // prompt
  cin >> withdrawalAmount; // obtain user input
  cout << "\nsubtracting $" << withdrawalAmount 
    << " from account1 balance\n\n";
  /* withdraw money from account1 */
  account1.debit( withdrawalAmount );

  // Display updated balances
  cout << "account1 balance: $" << account1.getBalance() << endl; 
  cout << "account2 balance: $" << account2.getBalance() << endl;
  
  cout << "\nEnter withdrawal amount for account2: "; // prompt
  cin >> withdrawalAmount; // obtain user input
  cout << "\nsubtracting $" << withdrawalAmount << " from account2 balance\n\n";
  /* withdraw money from account2 */
  account2.debit( withdrawalAmount );

  // display balances
  cout << "account1 balance: $" << account1.getBalance() << endl;
  cout << "account2 balance: $" << account2.getBalance() << endl;
} // end main