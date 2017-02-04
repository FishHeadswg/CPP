/***********************
Trevor Richardson
Account.cpp
***********************/
#include <iostream>
using namespace std; // Forgive me

#include "Account.h"

// Account constructor initializes data member balance
Account::Account( int initialBalance ):Persoana()
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
//Account::Account(int balance): Persoana(){
//    balance =0;
//}
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
int Account::plata(){
    int sumaPlata;
    cout<<"Introduceti suma de plata: ";
    cin>>sumaPlata;
    cout<<"Introduceti numele beneficiarului: ";
    cin>>_beneficiar;
    balance-=sumaPlata;
    cout<<"Plata: "<<_beneficiar<<" Suma: "<<sumaPlata<<" CONT: "<<balance<<endl;
    return balance;
}
ostream& operator<<(ostream& os,const Account& cont){
    os<<cont._nume<<" "<<cont._prenume<<" CONT: "<<cont.balance<<endl;
    return os;
}
