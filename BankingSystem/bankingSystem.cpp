/***********************
Trevor Richardson
***********************/
//bankingSystem.cpp

#ifndef _BANKINGSYSTEM_CPP
#define _BANKINGSYSTEM_CPP

#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include "bankingSystem.h"

// Get and Set member functions for Account class

void Account::SetAccountID(unsigned accountID)
{
  accountID_ = accountID;
}

unsigned Account::GetAccountID()
{
  return accountID_;
}

void Account::SetPasscode(unsigned passcode)
{
  passcode_ = passcode;
}

unsigned Account::GetPasscode()
{
  return passcode_;
}

void Account::SetFirstName(const std::string& firstName)
{
  firstName_ = firstName;
}

std::string Account::GetFirstName()
{
  return firstName_;
}

void Account::SetLastName(const std::string& lastName)
{
  lastName_ = lastName;
}

std::string Account::GetLastName()
{
  return lastName_;
}

void Account::SetBalance(double balance)
{
  balance_ = balance;
}

double Account::GetBalance()
{
  return balance_;
}

//Default constructor just initializes
//current number of accounts to 0;

BankingSystem::BankingSystem() 
  : current_num_accounts_(0)
{}

//Find an account by accountID.
//Return the array index if found, current_num_accounts_ otherwise.

size_t BankingSystem::FindAccount(size_t accountID)
{
  for ( size_t i = 0; i < current_num_accounts_; ++i )
    if ( accounts_[i].GetAccountID() == accountID )
      return i;
  return current_num_accounts_;
}

//Match the passcode at a given index with the given passcode.
//Return true for a match, false otherwise.

bool BankingSystem::MatchPasscode(unsigned passcode, size_t index)
{
  return accounts_[index].GetPasscode() == passcode;
}

//Add an account.

void BankingSystem::CreateAccount()
{
  Account account;
  unsigned accountID;
  unsigned passcode;
  std::string firstName;
  std::string lastName;
  double balance;

  //Get the account ID and make sure it doesn't already exist.

  std::cout << std::fixed << std::setprecision(2); // monetary values

  std::cout << "\nEnter the account ID: ";
  std::cin >> accountID;

  if (FindAccount(accountID) != current_num_accounts_)
  {
    std::cout << "\nAccount already exists!\n";
    return;
  }

  std::cout << "Enter the passcode: ";
  std::cin >> passcode;

  std::cout << "Enter the first name: ";
  std::cin >> firstName;

  std::cout << "Enter the last name: ";
  std::cin >> lastName;

  std::cout << "Enter the starting balance: ";
  std::cin >> balance;

  //Set this info into your Account object.

  account.SetAccountID(accountID);
  account.SetPasscode(passcode);
  account.SetFirstName(firstName);
  account.SetLastName(lastName);
  account.SetBalance(balance);

  //Add the account to your array and increment the count of accounts.

  accounts_[current_num_accounts_] = account;
  ++current_num_accounts_;
  std::cout << "\nAccount added successfully!\n";

} // end CreateAccount

//Delete an account.

void BankingSystem::DeleteAccount()
{
  size_t index;
  unsigned accountID;
  unsigned passcode;

  std::cout << "\nEnter the account ID: "; // Check to see if account exists
  std::cin >> accountID;
  
  if ( FindAccount(accountID) == current_num_accounts_ )
  {
    std::cout << "\nAccount not found!" << std::endl;
    return;
  }

  std::cout << "\nEnter the passcode: "; // Validate passcode for account
  std::cin >> passcode;

  if ( !MatchPasscode( passcode, FindAccount(accountID) ) )
  {
    std::cout << "\nInvalid passcode!" << std::endl;
    return;
  }

  //Remove the account.  First, shift everything over to the left.

  index = FindAccount(accountID);

  for ( size_t i = index; i < current_num_accounts_ - 1; ++i )
    accounts_[i] = accounts_[i + 1];

  --current_num_accounts_;
  std::cout << "\nAccount erased!\n";

} // end DeleteAccount

void BankingSystem::PrintAccounts()
{ // Table header
  std::cout << std::right << std::setw(10) << "\nAccount ID" << " " 
  << std::setw(10) << "Passcode" << "   " << std::left 
  << std::setw(15) << "Last Name" << " "
  << std::setw(15) << "First Name" << " " << std::right
  << std::setw(8) << "Balance" << std::endl
  << "================================================================" << std::endl;

  for ( size_t j = 0; j < current_num_accounts_; ++j)
  { // Iterates through Accounts array to print each one's information
    std::cout << std::right << std::fixed << std::setprecision(2) <<
    std::setw(10) << accounts_[ j ].GetAccountID() << " " 
    << std::setw(10) << accounts_[ j ].GetPasscode() << "   " << std::left 
    << std::setw(15) << accounts_[ j ].GetLastName() << " "
    << std::setw(15) << accounts_[ j ].GetFirstName() << " " << std::right
    << std::setw(8) << accounts_[ j ].GetBalance() << std::endl;
  }
} //end PrintAccounts

void BankingSystem::Deposit()
{
  unsigned accountID;
  unsigned passcode;
  double deposit;
  double newBalance;

  std::cout << std::fixed << std::setprecision(2); // monetary values

  std::cout << "\nEnter the account ID: ";
  std::cin >> accountID;

  if ( FindAccount(accountID) == current_num_accounts_ ) // Validate account
  {
    std::cout << "\nAccount not found!" << std::endl;
    return;
  }

  std::cout << "\nEnter the passcode: ";
  std::cin >> passcode;

  if ( !MatchPasscode(passcode, FindAccount(accountID) ) ) //Validate passcode
  {
    std::cout << "\nInvalid passcode!" << std::endl;
    return;
  }

  std::cout << "\nHow much would you like to deposit? ";
  std::cin >> deposit;

  if ( deposit <= 0 ) // Must deposit positive amount
  {
    std::cout << "\nYou must deposit at least a penny!" << std::endl;
    return;
  }
  // Calculate new balance
  newBalance = accounts_[ FindAccount(accountID) ].GetBalance() + deposit;
  // Set new balance
  accounts_[ FindAccount(accountID) ].SetBalance(newBalance); 
  // Print new balance
  std::cout << "\nSuccess! The new balance is $" << newBalance << std::endl; 

} // end Deposit

void BankingSystem::Withdraw()
{
  unsigned accountID;
  unsigned passcode;
  double withdrawal;
  double newBalance;

  std::cout << std::fixed << std::setprecision(2); // monetary values

  std::cout << "\nEnter the account ID: ";
  std::cin >> accountID;

  if ( FindAccount(accountID) == current_num_accounts_ )
  {
    std::cout << "\nAccount not found!" << std::endl;
    return;
  }

  std::cout << "\nEnter the passcode: ";
  std::cin >> passcode;

  if ( !MatchPasscode(passcode, FindAccount(accountID) ) )
  {
    std::cout << "\nInvalid passcode!" << std::endl;
    return;
  }

  std::cout << "\nHow much would you like to withdraw? ";
  std::cin >> withdrawal;

  if ( withdrawal <= 0 )
  {
    std::cout << "\nYou must withdraw at least a penny!" << std::endl;
    return;
  }
  // Check if withdrawal amount > balance
  if ( accounts_[ FindAccount(accountID) ].GetBalance() < withdrawal )
  {
    std::cout << "\nSorry, you don't have that much money to withdraw!" 
      << std::endl;
    return;
  }
   // Calculate new balance
  newBalance = accounts_[ FindAccount(accountID) ].GetBalance() - withdrawal;
  accounts_[ FindAccount(accountID) ].SetBalance(newBalance); // Set new balance
  std::cout << "\nSuccess! The new balance is $" // Pritn new balance
  << std::fixed << std::setprecision(2) 
  << newBalance << std::endl;

} // end Withdraw

#endif
