/***********************
Trevor Richardson
***********************/
//CommissionWorker.h

class CommissionWorker
{
private:
	float weeklySales;
	float pay;
public:
	CommissionWorker(); // Consuctor, requests salary information 
	float getPay(); // calculates pay
	void displayPay(); // Displays pay message
};