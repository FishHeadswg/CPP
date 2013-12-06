/***********************
Trevor Richardson
***********************/
// HourlyWorker.cpp
//Source code for Hourly Worker class

#include <iostream>
#include "HourlyWorker.h"

HourlyWorker::HourlyWorker() // constructor
{
	std::cout << "Hourly Worker selected." << std::endl;
	std::cout << "Enter the hourly salary: ";
	std::cin >> hourlySalary;
	std::cout << "Enter hours worked: ";
	std::cin >> hours;
}
float HourlyWorker::getPay() // calculates pay
{
	if (hours > 0 && hours <= 40) // No overtime
		pay = hourlySalary * hours;
	else if (hours > 40) // Overtime 
		pay = (hourlySalary * 40) + // base pay
    (hourlySalary * static_cast<float>(1.5)) * (hours - 40); // overtime
	else
		pay = hourlySalary * hours; // Deducting hours
	return pay;
}
void HourlyWorker::displayPay() // Displays pay message
{
	std::cout << "Hourly Worker's pay is $" << getPay() << "\n" << std::endl;
}