/***********************
Trevor Richardson
Basic stat calculator
***********************/
#include <iostream>  // allows program to perform input and output
using namespace std; // forgive me

int main()
{
  int number1;  // first integer read from user
  int number2;  // second integer read from user
  int number3;  // third integer read from user
  int smallest;  // smallest integer read from user
  int largest;  // largest integer read from user
  int sum; // sum of integers
  int average; // average of integers
  double decimalAverage; // decimal average of integers
  int product; // product of intgers

  cout << "Input three integers: "; // prompt

  cin >> number1 >> number2 >> number3; // Reads number1, number2, number3

  largest = number1;  // assume first integer is largest

  if (number2 > largest)
	  largest = number2;

  if (number3 > largest)
	  largest = number3;

  smallest = number1;  // assume first integer is smallest

  if (number2 < smallest)
	  smallest = number2;

  if (number3< smallest)
	  smallest = number3;

  /* Prints the sum, average, product, largest and smallest */

  sum = number1 + number2 + number3; // Finds sum of 3 inputted integers
  average = sum / 3; // Finds integer average. Assumes only 3 integers
  decimalAverage = sum / 3.0; //Finds double average
  product = number1 * number2 * number3; // Finds product

  cout 
    << "Sum:       " << sum << '\n'
    << "Average:   " << average << " (" << decimalAverage << ")" << '\n'
    << "Product:   " << product << '\n'
    << "Smallest:  " << smallest << '\n'
    << "Largest:   " << largest << endl;

  std::cin.get();
}  // end main