/***********************
Trevor Richardson
Account.h
***********************/
class Account
{
  private:
  int balance; // data member that stores the balance

  public:
  Account( int ); // constructor initializes balance
  void credit( int ); // add an amount to the account balance
  void debit( int ); // subtract an amount to the account balance
  int getBalance(); // return the account balance
}; // end class Account