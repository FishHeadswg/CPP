/***********************
Trevor Richardson
***********************/
//HourlyWorker.h

class HourlyWorker
{
private:
	float hours;
	float hourlySalary;
	float pay;
public:
	HourlyWorker(); // Consuctor, requests salary information 
	float getPay(); // calculates pay
	void displayPay(); // Displays pay message
};