/***********************
Trevor Richardson
WidgetWorker.h
***********************/


class WidgetWorker
{
private:
	float wagePerPiece;
	float pieces;
	float pay;
public:
	WidgetWorker(); // Consuctor, requests salary information 
	float getPay(); // calculates pay
	void displayPay(); // Displays pay message
};