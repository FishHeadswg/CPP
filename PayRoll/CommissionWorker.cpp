/***********************
Trevor Richardson
***********************/
// CommissionWorker.cpp

#include <iostream>
#include "CommissionWorker.h"

CommissionWorker::CommissionWorker() // constructor
{
	std::cout << "Commission Worker selected." << std::endl;
	std::cout << "Enter gross weekly sales: ";
	std::cin >> weeklySales;
}
float CommissionWorker::getPay() // calculates pay
{
	float commission = 0.092; // commission rate
	float weeklySalary = 250; // base weekly salary
	pay = weeklySalary + (weeklySales * commission); // base pay + commission on sales
	return pay;
}
void CommissionWorker::displayPay() // Displays pay message
{
	std::cout << "Commission Worker's pay is $" << getPay();
	std::cout << std::endl << std::endl;
}