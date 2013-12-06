/***********************
Trevor Richardson
custerCredit.cpp
***********************/

#include <iostream>
#include <iomanip> // parameterized stream manipulators

int main()
{
   int account; // account number
	 double balance; 
	 double charges; 
	 double credits; 
	 double creditLimit;

   std::cout << "Enter account number (-1 to end): ";
	 std::cin >> account; // Reads account number

     // set floating-point number format
	 std::cout << std::fixed << std::setprecision( 2 ); // monetary ammounts

     // exit if the input is -1 otherwise, proceed with the program
	 while ( account != -1)
     {
		 std::cout << "Enter beginning balance: $";
		 std::cin >> balance;

		 std::cout << "Enter total charges: $";
		 std::cin >> charges;
 
		 std::cout << "Enter total credits: $";
		 std::cin >> credits;

		 std::cout << "Enter credit limit: $";
		 std::cin >> creditLimit;

     // calculate and display new balance
		 balance = balance - credits + charges;
     /* Display the new balance */
		 std::cout << "New balance is $" << balance;

     // display a warning if the user has exceed the credit limit
		 if ( balance > creditLimit )
			 std::cout << "\nAccount: " << account
			 << "\nCredit Limit: $" << creditLimit
			 << "\nBalance: $" << balance
			 << "\nCredit Limit Exceeded.";

      std::cout << "\n\nEnter Account Number (-1 to end): ";
      /* input the next account number */
		  std::cin >> account;
     } // end while
} // end main