/*****************************************************************************/
//
//Checkbook Balancing Program
//Programmer: Galbeyte Salad
//Completed : September 23, 2017
//Status    : Complete
//
//Take in a variable from keyboard, take in command from menu, execute operation
// displays the data in a table format
//*****************************************************************************//

#include <iostream>			// input/output declerations
#include <iomanip>			// i/o manipulator declaration
using namespace std;

int main()
{
	// initialize variables
	char type = ' ';					
	float balance = 0;					
	float transaction = 0;				
	float serviceCharge = 0;			
	float totalServiceCharges = 0;
	
	
	//Get the User's balance
	
	cout << "Enter the beginning balance:	$";
	cin >> balance;
	cin.clear();
	

	//Display the choices
	//This while loop allows for user to keep making changes to balance until user ends program
	do	{
	cout << "Commands: \n";
	cout << "\nC - process a check\n";
	cout << "\nD - process a deposit\n";
	cout << "\nE - end the program\n";
	
	//Capture choice decision from keyboard
	cout << "\nEnter transaction type:  ";
	cin >> type;	//Store
	cin.clear();
	
	if(type == 'C' || type == 'c')
	{
			cout << endl;
			cout << "Enter transaction amount:	$";		//Capture Transaction amount from keyboard, this will be added to balance
			
			
			cin >> transaction;
			cin.clear();
			serviceCharge = 0.35;
			
			balance -= transaction;
			
			cout << "\nNew Balance is:	$" << balance << endl;	//Display new balance after transaction type
			cout << "\nTotal Service Charges:	$" << (totalServiceCharges += serviceCharge) << endl;
			}
			
	else if(type == 'D' || type == 'd')
	{
	 cout << "Enter transaction amount:	$";	//Capture Transaction type from keyboard, this  will be subtracted from balance 
			
			
			cin >> transaction;
			cin.clear();
			serviceCharge = 0.35;
			
			balance += transaction;
			
			cout << "\nNew Balance is:	$" << balance << endl;		//Display new balance after transaction type 
			cout << "\nTotal Service Charges:	$" << (totalServiceCharges += serviceCharge) << endl;
			
		}
	else if(type == 'E' || type == 'e'){
		cout << "Processing end of the month";
		cout << "\nFinal balance: $" << balance << endl;
		exit(0);
	}
		
	}while(true);
	
	
	return 0;	
}
