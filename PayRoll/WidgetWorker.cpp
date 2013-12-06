/***********************
Trevor Richardson
***********************/
// WidgetWorker.cpp

#include <iostream>
#include "WidgetWorker.h"

WidgetWorker::WidgetWorker() // constructor
{
	std::cout << "Widget Worker selected." << std::endl;
	std::cout << "Enter number of pieces: ";
	std::cin >> pieces;
	std::cout << "Enter wage per piece: ";
	std::cin >> wagePerPiece;
  pay = pieces * wagePerPiece;
}
float WidgetWorker::getPay()
{
	return pay;
}
void WidgetWorker::displayPay() // Displays pay message
{
	std::cout << "Widget Worker's pay is $" << getPay();
	std::cout << std::endl << std::endl;
}