/***********************
Trevor Richardson
***********************/
// AcmePayroll.cpp
// Calculates pay for different types of workers, each with their own class.

#include <iostream>
#include <iomanip>
#include "Manager.h"
#include "HourlyWorker.h"
#include "CommissionWorker.h"
#include "WidgetWorker.h"

int main()
{
	int payCode = 0;
	while (payCode != -1) // sentinel value
	{
		std::cout << "Enter paycode (-1 to end): ";
		std::cin >> payCode; // Input paycode of worker
		std::cout << std::fixed << std::setprecision( 2 ); // Display monetary values
		switch ( payCode ) // switch for each paycode
		{
			case 1: // Manager paycode
			{
				Manager manager; // Construct manager object
				manager.displayPay(); // Display manager's pay
				break;
			} //end case 1
			case 2: // Hourly Worker paycode
			{
				HourlyWorker hourlyworker;
				hourlyworker.displayPay(); // Display hourly worker's pay
				break;
			} // end case 2
			case 3: // Commission Worker paycode
			{
				CommissionWorker commissionworker;
				commissionworker.displayPay(); // Display Commission Worker's pay
				break;
			} // end case 3
			case 4: // Widget Worker paycode
			{
				WidgetWorker widgetworker;
				widgetworker.displayPay(); // Display Widget Worker's pay
				break;
			} // end case 4
			case -1: // Sentinel value break
				break;
			default: // Invalid paycode entered
				std::cout << "\nValid paycodes are:" 
					"\n1 (Manager)"
					"\n2 (Hourly Worker)"
					"\n3 (Commission Worker)"
					"\n4 (Widget Worker)"
					"\n" << std::endl;
				break;
		} // end switch
	} // end while
} // end main