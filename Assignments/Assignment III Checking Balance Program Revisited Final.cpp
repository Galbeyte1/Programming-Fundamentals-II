//*****************************************************************************/
//
//Program   : Checkbook Balalancing Revistited 
//Programmer: Galbeyte Salad
//Completed : October 1, 2017
//Status    : Incomplete
//
//*****************************************************************************/

#include<iostream>
#include<iomanip>
using namespace std;

//Prototype Functions for Checking and Depositing processes
float checkProcessing(float amount, float balance);
float depositProcessing(float amount, float balance);
float serviceChargeDetermine(float balance);


int main(){
	
	// Initialize variables
	char type = ' ';
	float balance = 0;
	float amount = 0;
	float serviceCharge = 0;
	float totalServiceCharges = 0;
	
	
	// Enter Beginning Balance
	cout << "Enter Beginning Balance:	$";
	cin >> balance;
	cin.ignore();
	
	cout << fixed << showpoint << setprecision(2) << endl;
	
	// Display Commands
	cout << "Commands:	\n";
	cout << "	C - Process a Check\n";
	cout << "	D - Process a Deposit\n";
	cout << "	E - End The Program\n" << endl;
	
	

	
	do{
		// Capture Transaction Type and Amount in a single line
		
		cout << fixed << showpoint << setprecision(2) << endl;
		cout << "Enter Transaction Type and Amount: ";
		cin >> type;
		cin.ignore();
		
		
		
		// Condition for Processing a check
		if (type == 'C' || type == 'c'){
			
			cin >> amount;
			cin.ignore();
			
			cout << "Current Balance is:	$" << balance << endl << endl;
			// Display Transaction Type and Amount
			// Call function to process check
			// Call function to determine and display service charge
			balance = checkProcessing(amount, balance);
			
			cout << "Balance:	$" << balance << endl;
			
			
			// To keep a running total of the services charges from multiple
			//		transactions I used += 
			totalServiceCharges += serviceChargeDetermine(balance);
			cout << "Total service charges:		$" << totalServiceCharges << endl;
		}
		
		// Condition for Depositing a check
		else if (type == 'D' || type == 'd'){
			
			cin >> amount;
			cin.ignore();
			
			cout << "Current Balance is:	$" << balance << endl << endl;
			// Display Transaction Type and Amount
			// Call function to deposit check
			// Call function to determine and display service charge
			balance = depositProcessing(amount, balance);
			cout << "Balance:	$" << balance << endl;
			
			
			// To keep a running total of the services charges from multiple
			//		transactions I used += 
			
			// For processing a deposit a service charge is unecessary
			totalServiceCharges += (serviceChargeDetermine(balance) - 0.35);				
			cout << "Total service charges:		$" << totalServiceCharges << endl;
		}
		
		// Condition to say invalid command type
		else if(type == 'E' || type == 'e'){
		
		// MAKE SURE TO ADD FINAL BALANCE HERE
		cout << "Final Balance:	$" << balance << endl;
		cout << "Total Service Charge:	$" << totalServiceCharges << endl; 
		break;
			
		}
		else{
			
		cout << "Invalid Command Type" << endl;
		
		}
		
	}while (type != 'E' || type != 'e');
	
	
	
		
	
	return 0;
}

//************************************************************
// Function: checkProcessing
//
// This function processes a check
//************************************************************

float checkProcessing(float amount, float balance){
	
	balance -= amount;
	
	return balance;
	
}

//************************************************************
// Function: depositProcessing
//
// This function processes a check
//************************************************************
float depositProcessing(float amount, float balance){
	
	balance += amount;
	
	return balance;
	
}

//************************************************************
// Function: serviceChargeDetermine
//
// This function gives the usual service charge of 35 cents
// 		plus an additional service charge depending on
//		the status of the balance
//************************************************************
float serviceChargeDetermine(float balance){
	
	
	float serviceCharge = 0.35;
	float totalServiceCharges = 0;
	float lowBalanceCharge = 10;
	float insufficientFundCharge = 30;
	
	if (balance >= 1000){
		
		
		totalServiceCharges = totalServiceCharges + serviceCharge;
		
		
		
		return totalServiceCharges;
		
	}
	else if (balance > 0 && balance < 1000){
		
		
		// Display service charge for a check and low balance
		cout << "Service charge:	$" << serviceCharge << endl;
		cout << "Service charge:	$" << lowBalanceCharge << " balance below $1000.00" << endl;
		// Total Service Charges
		totalServiceCharges = totalServiceCharges + serviceCharge + lowBalanceCharge;
		// Dsiplay total service charge
		
		
		return totalServiceCharges;
		
	}
	
	else if (balance < 0){
		
		
		// Display service charge for a check and low balance
		cout << "Service charge:	$" << serviceCharge << endl;
		cout << "Service charge:	$" << insufficientFundCharge << " balance below $0.00" << endl;
		// Total Service Charges
		totalServiceCharges = totalServiceCharges + serviceCharge + insufficientFundCharge;
		// Dsiplay total service charge
		
		
		return totalServiceCharges;
		
	}
	
}
