/***********************
Trevor Richardson
***********************/
//bankingSystem.h

#ifndef _BANKINGSYSTEM_H
#define _BANKINGSYSTEM_H

#include <iostream>
#include <string>
#include <cstdlib>

class Account
{

public:

  void SetAccountID(unsigned accountID);
  unsigned GetAccountID();

  void SetPasscode(unsigned passcode);
  unsigned GetPasscode();

  void SetFirstName(const std::string& firstName);
  std::string GetFirstName();

  void SetLastName(const std::string& lastName);
  std::string GetLastName();

  void SetBalance(double balance);
  double GetBalance();

private:

  unsigned accountID_;
  unsigned passcode_;
  std::string firstName_;
  std::string lastName_;
  double balance_;

};

//Assume a max of 100 accounts.

const size_t MAX_NUM_ACCOUNTS = 100;

//Class BankingSystem uses an array of Account.
//You can create, delete, print, deposit, and withdraw.

class BankingSystem
{

public:

  BankingSystem();

  void CreateAccount();
  void DeleteAccount();
  void PrintAccounts();
  void Deposit();
  void Withdraw();

private:

  Account accounts_[MAX_NUM_ACCOUNTS];
  size_t current_num_accounts_;

  size_t FindAccount(unsigned accountID);
  bool MatchPasscode(unsigned passcode, size_t index);

};

#endif
