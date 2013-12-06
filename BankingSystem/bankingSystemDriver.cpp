/***********************
Trevor Richardson
***********************/
//bankingSystemDriver.cpp

#include <iostream>
#include "bankingSystem.h"

//Prints a menu of options to the user.

void PrintMenu()
{
  std::cout << "\n(1) Add Account\n";
  std::cout << "(2) Delete Account\n";
  std::cout << "(3) Print Accounts\n";
  std::cout << "(4) Deposit\n";
  std::cout << "(5) Withdrawal\n";
  std::cout << "(6) Exit\n";
  std::cout << "\nEnter selection: ";
}

int main()
{

  BankingSystem b; // Construct BankingSystem object
  int selection = 0; // Menu selection

  std::cout << "\n*** Welcome to the Banking System ***\n";

  while (selection != 6) // Loops until sentinel value
  {
    PrintMenu();
    std::cin >> selection; // Input selection
    switch ( selection ) // Switch for each menu option
    {
      case 1: 
      {
        b.CreateAccount();
        break;
      }
      case 2:
      {
        b.DeleteAccount();
        break;
      }
      case 3:
      {
        b.PrintAccounts();
        break;
      }
      case 4:
      {
        b.Deposit();
        break;
      }
      case 5:
      {
        b.Withdraw();
        break;
      }
      case 6: // Sentinel value
        break;
      default:
        std::cout << "Invalid selection!" << std::endl;

    } //end switch
  } //end while
  return 0;

} //end main