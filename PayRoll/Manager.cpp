/***********************
Trevor Richardson
***********************/
// Manager.cpp

#include <iostream>
#include "Manager.h"

Manager::Manager() // constructor
{
	std::cout << "Manager selected." << std::endl;
	std::cout << "Enter weekly salary: ";
	std::cin >> weeklySalary; // Input weekly salary
  pay = weeklySalary;
}
float Manager::getPay()
{
	return pay;
}
void Manager::displayPay() // Displays pay message
{
	std::cout << "Manager's pay is $" << getPay();
	std::cout << std::endl << std::endl;
}