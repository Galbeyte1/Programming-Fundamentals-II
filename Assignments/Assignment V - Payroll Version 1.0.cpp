//*****************************************************************************/
//
//Program   : Payroll Version 1.0 
//Programmer: Galbeyte Salad
//Completed : 11/19/2017
//Status    : COMPLETE
//
//****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct MasterInfo{
	// Array to keep...
	int employeeID[4];			// ID numbers	
	string employeeName[4];		// Names
	float payRate[4];			// Payrate in hours
	int employeeType[4];			// Employee Type (0 for union, 1 for Mgmt)
};

struct TimeSheet{
	// Array to keep...
	float employeeHours[4];		// Number of hours worked per week
	// Array to hold...
	float employeeGrossPay[4];		// Gross Pay 
	float employeeTax[4];			// Taxation of Gross pay at 15%
	float employeeNetPay[4];		// Net Pay = Gross Pay - Tax
};
// Prototypes Functions that validate for...		// The following 4 prototypes take place holding variables as parameters	
int validateEmployeeID(int empID);					// Employee ID							
int validateEmployeeType(int empType);				// Employee Type (0 or 1)

float validatePayRate(float pRate);					// Employee Pay Rate
float validateEmployeeHours(float empHours);		// Employee Hours

// Protoype for calculating overtime rates
float overtimePay(int type, float hours, float payRate, float grossPay);

int main(){
	MasterInfo employee;
	TimeSheet employee1;
	
	//	Dummy Variables used to transfer data from cin to validation function then into correct place of array
	int empID;					
	int empType;
	float pRate;
	float empHours;
	
	// Tax rate variable
	float TAX = 0.15;
	for (int n = 0; n < 4; n++){
		
		//	Get Employee information from User
		cout << "Enter information for Employee " << (n + 1) << endl;
		
		// Employee ID number
		cout << endl;
		cout << "Employee ID:		";
		cin >> empID;
		employee.employeeID[n] = validateEmployeeID(empID);
		cin.clear();		// Skip the '\n' character left in inut  buffer
		
		// Employee Name
		cout << "Employee name:		";
		//getline(cin, employee.employeeName[n]);
		cin >> employee.employeeName[n];
		cin.clear();
		
		// Employee Pay Rate in hours
		cout << "Pay rate:		$";
		cin >> pRate;
		employee.payRate[n] = validatePayRate(pRate);
		//cin.clear();
		
		// Employee Type
		cout << "Type:			";
		cin >> empType;
		employee.employeeType[n] = validateEmployeeType(empType);
		//cin.clear();	
	}
	cout << "Enter timecard information for each employee:	" << endl;
	for (int n = 0; n < 4; n++){
		
		//	Capture employee Master Information
		cout << endl;
		//	Employee  number of Hours worked
		cout << "Hours worked for " << employee.employeeName[n] << " :	";
		cin >> empHours;
		employee1.employeeHours[n] = validateEmployeeHours(empHours);
		cin.ignore();	 
	}
	for (int n = 0; n < 4; n++){
		
		// Using intermediate variables as place holders in order to pass values through validation function
		int type = employee.employeeType[n];				// Variable to hold specific type value in place n of array
		float payRate = employee.payRate[n];				// Variable to hold specific pay rate value in place n of array
		float hours = employee1.employeeHours[n];			// Variable to hold specific hours value in place n of array
		float grossPay;										// Initializing  return value for gross pay
		
		employee1.employeeGrossPay[n] = overtimePay(type, hours, payRate, grossPay);					// Determine if overtime pay required by passing through validation function
		employee1.employeeTax[n] = (employee1.employeeGrossPay[n] * TAX);								// Calculate tax for each employee
		employee1.employeeNetPay[n] = employee1.employeeGrossPay[n] - employee1.employeeTax[n];			// Calculate net pay for each employee
	}
	//	Display all the data
	cout << endl;
	cout << "Payroll Report" << endl;
	cout << endl;
	cout << fixed << showpoint << setprecision(2) << endl;		// Setting output to 2 decimal places
	cout << left<< setw(3) << "ID" << setw(35) << "Employee" << left << setw(20) << "Gross Pay" << left << setw(15) << "Tax"  << left << setw(15) << "Net Pay" << left << endl;
	cout << endl;
	// Using a for loop to print the contents of a specific row in an array on a single line. As loop iterates, the next rows are printed below the previous rows
	for (int n = 0; n < 4; n++){
		
		// Display information
		
		cout << fixed << showpoint << setprecision(2) << endl;
		cout << left << setw(3) << employee.employeeID[n] << setw(20) << employee.employeeName[n] << right << setw(15) << "$" << employee1.employeeGrossPay[n] << right << setw(15) << "$" << employee1.employeeTax[n] << right << setw(15) << "$" << employee1.employeeNetPay[n] << endl;
		
	}
	return 0;	// End of main function
}
// Below this point I will keep my functions

//************************************************************
// Function: validateEmployeeID
//
// This function will validate whether the client entered
// 		an employee ID greater than Zero. If the client 
//		enters an incorrect value the program will ask again
//		until the client enters a correct value.
//************************************************************
int validateEmployeeID(int empID){
	
	while (empID > 99 || empID < 0){
		cout << "Invlaid Input. Enter an Employee ID less than 100 and greater than 0:	";
		cin >> empID;
		
	}
	
	return empID;							// Return Employee ID
}

//************************************************************
// Function: validateEmployeeType
//
// This function will validate whether the client entered
// 		an employee type of either 0 or 1. If the client 
//		enters an incorrect choice the program will ask again
//		until the client enters a correct choice.
//		If employee Type is 0 (union) tax for overtime is +50%
//************************************************************
int validateEmployeeType(int empType){
	
	while (empType != 0 && empType != 1){
		cout << "Invalid Input. Enter 0 - Union Member 1 - Managment:	";
		cin >> empType;
	}
	
	return empType;
}

//************************************************************
// Function: validatePayRate
//
// This function will validate whether the client entered
// 		a pay rate of greater than zero. If the client 
//		enters a value out of range the program will ask again
//		until the client enters a correct value. The function
//		will then return a pay rate value.
//************************************************************
float validatePayRate(float pRate){
	
	while (pRate < 0){
		cout << "Invalid input. Pay rate must be greater than 0:		";
		cin >> pRate;
	}
	
	return pRate;							// Return Pay Rate
}

//************************************************************
// Function: validateEmployeeHours
//
// This function will validate whether the client entered
// 		hours greater than or equal to zero. If the client 
//		enters a value out of range the program will ask again
//		until the client enters a correct value. The function
//		will then return hours value.
//************************************************************
float validateEmployeeHours(float empHours){
	
	while (empHours < 0){
		cout << "Invalid Input. Enter Hours:	";
		cin >> empHours;
	}
	
	return empHours;							// Return Employee Hours
}
// This function validates and calculates overtime
float overtimePay(int type, float hours, float payRate, float grossPay){
	
	float overtime;
	
	if (type != 1 && hours > 40){				// If employee is union member and worked more than 40 hours
		
		overtime = 1.5;							// There is an overtime rate of 150%				
	}
	else{										// If not union employee is managment 
		
		overtime = 0;							// There is no overtime rate
	}
	
	grossPay = (payRate*hours) + (overtime*payRate)*(hours - 40);		// Gross pay compensating for overtime hours worked
	
	return grossPay;							// Return Gross Pay
	
}
//No Code Below this point
