//*****************************************************************************
//
//Expression Review
//Programmer: Galbeyte Salad
//Completed : September 10, 2017
//Status    : Complete
//
//This program reads 2 integers from keyboard and calculates 
//the sum, product, quiotient, remainder, and average. The program then 
// displays the data in a table format
//*****************************************************************************

#include <iostream>			// input/output declerations
#include <iomanip>			// i/o manipulator declaration
using namespace std;

int main()
{
	int number1, number2;	// Initializing number1 and number2 (will use these in my code)
	
	cout << "Please enter your first integer: ";     //Show message to get first integer 
	cin >> number1;		// input number #1
	cin.sync();			// Captures the spacing 
	cin.clear();  		// Clears the error flag on cin (skips to the next new line)
	
	cout << endl;		//
	
	cout << "Please enter your second integer: ";   //Show message to get first integer
	cin >> number2;		// input number #2
	cin.sync();			// Capture the Spacing
	cin.clear();		// Clears the error flag on cin (skips to the next new line)
	
	cout << endl;
	
	// Add the inputed variables and display the sum
	cout << left << setw(25) << "Sum " << right << setw(10) << "is " << number1 + number2 << endl;
	cout << endl;
	
	// Use the multipliction operation and display what product
	cout << left << setw(25) << "Product " << right << setw(10) << "is " << number1 * number2 << endl;
	cout << endl;
	
	// Use the division operation to divide the first vaiable from the second. Display Quotient
	cout << left << setw(25) << "Integer quotioent " << right << setw(10) << "is " << number1 / number2 << endl;
	cout << endl;
	
	// Use the remainder operation and display what was done
	cout << left << setw(25) << "Integer remainder " << right << setw(10) << "is " << number1 % number2 << endl;
	cout << endl;
	
	// Divide integers to get the remainder in decimals
	cout << left << setw(25) << "Floating-point quotient " << right << setw(10) << "is " << setprecision(6) << static_cast<double>(number1)/ static_cast<double>(number2) << endl;
	cout << endl;
	
	// Take the average and display
	cout << left << setw(25) << "Average " << right << setw(10) << "is " << (static_cast<float>(number1)+ static_cast<float>(number2))/2.0 << endl;
	
	return 0;
}
