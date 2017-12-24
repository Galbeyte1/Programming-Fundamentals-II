//*****************************************************************************/
//
//Program   : Postal Packages 
//Programmer: Galbeyte Salad
//Completed : 11/26/2017
//Status    : COMPLETED
//
//*****************************************************************************/

#include<iostream>
#include<iomanip>

using namespace std;

int main(){
	
	// 								Initialized Variables
	int weight = 0;				// Integer Variable for Weight of Package		
	int side1, side2, side3;	// Integer variables to hold dimensions of box	
	int counterACCEPT = 0;		// Integer Variable for # of packages accepted	
	int counterREJECT = 0;		// Integer variable for # of packages rejected	
	int girth;						// Integer Variable for girth of box
									// Girth = 2*(sum of sides - largest side)	
	int transaction = 0;		// Transaction counting variable
	string status;				// Status keeping variable
	float cost;					// Cost variable 
	
	// Arrays to keep Weight classifications and Corresponding Shipping Costs
	int weightTBL[15] = {1, 2, 3, 5, 7, 10, 13, 16, 20, 25, 30, 35, 40, 45, 50};
	float shippingChargeTBL[15] = {1.5, 2.1, 4, 6.75, 9.9, 14.95, 19.4, 24.2, 27.3, 31.9, 38.5, 43.5, 44.8, 47.4, 55.2};
	
	// Prototypes
	int findGirth(int side1, int side2, int side3, int girth);								// Determine Girth
	float findWeight(int a[], int sizeA, float b[], int sizeB, int weight);		// Determine shipping cost		
	
	cout << "For each transaction, enter package weight and 3 dimensions." << endl;
	cout << "Enter -1 to quit." << endl;
	cout << endl;
	
	// Use a while loop to ask user to enter data.
	// User will enter -1 to quit.	
	while (weight != -1){
		
	cout << "Enter package weight and 3 dimensions:		";
	cin >> weight;
	cin.ignore();
	// When the user is ready to exit, only input of -1 is needed.
	if (weight == -1){
		break;
		cout << endl;
	}
	cin >> side1;
	cin.ignore();
	cin >> side2;
	cin.ignore();
	cin >> side3;
	cin.clear();
	cout << endl;
	
	// Validate that weight and dimensions are greaer than zero
	if (weight > 0 || side1 > 0 || side2 > 0 || side3 > 0){
		
		// Use Girth determining function to find girth then validate girth
		girth = findGirth(side1, side2, side3, girth);
		if (girth <= 60){
			
			// When girth is in range status is accepted
			status = "Accepted";
			counterACCEPT += 1;
			// Then find cost using linear search function
			cost = findWeight(weightTBL, 15, shippingChargeTBL, 15, weight);
		}
		else{
			
			// When girth is not in range, status is rejected
			status = "Rejected";
			counterREJECT += 1;
			cost = 0;
		}
	}
	transaction += 1;
	cout << fixed << showpoint << setprecision(2) << endl;
	// Display 
	cout << "Transaction:	" << transaction << endl;
	cout << "Status	:	" << status << endl;
	cout << "Weight	:	" << weight << endl;
	cout << "Cost	:	" << cost << endl;
	cout << endl;
	}
	
	// Display after user enters -1
	cout << "Number of accepted packages:	" << counterACCEPT << endl;
	cout << "Number of rejected packages:	" << counterREJECT << endl;
	return 0;
}

// Funtion to calculate and return girth
int findGirth(int side1, int side2, int side3, int girth){
	
	int largest;		// Initialize the largest holding variable
	
	// Determine the largest of the sides
	if (side1 > side2 && side1 > side3){	
		largest = side1;
	}
	else if (side2 > side1 && side2 > side3){
		largest = side2;
	}
	else if (side3 > side1 && side3 > side2){
		largest = side3;
	}
	// Girth is determined by 2 times the sum of the 2 shortest sides
	girth = 2*(side1 + side2 + side3 - largest);
	
	return girth;
}
// This function will do a linear search and determine the cost of shipping
float findWeight(int a[], int sizeA, float b[], int sizeB, int weight){
	
	int index = 0;			// Loop counter
	int position = -1;		// Position keeping variable
	bool found = false;
	
	while (index < sizeA && !found){
		
		// Determine if weight is less than the next weight class
		if (a[index] > weight){
			found = true;
			// Assign position to the previous weight class
			position = (index - 1);
		}
		index++;			// Loop counter should go up with each loop
	}
	// Return the position of the cost array parallel to the weight array
	return b[position];
}
