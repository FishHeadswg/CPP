/***********************
Trevor Richardson
***********************/
// Manager.h

class Manager
{
private:
	float weeklySalary;
	float pay;
public:
	Manager(); // Consuctor, requests salary information 
	float getPay(); // calculates pay
	void displayPay(); // Displays pay message
};