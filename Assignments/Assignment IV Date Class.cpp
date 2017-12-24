//*****************************************************************************/
//
//Program   : Date Class 
//Programmer: Galbeyte Salad
//Completed : October 8, 2017
//Status    : Complete
//
//*****************************************************************************/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

class Date{
	
	// Private member variables
	private: 					
	
		int day;
		int month;
		int year;
		
		string nameMonth;
		
		string monthConverter(int month);			// Convert Month
	
	
	// Public Member Function Prototypes	
	public:						
	
		Date();				//Default Constructor 
		void setDate(int m, int d, int y);
	
		void outputNumeric();
		void outputAmerican();
		void outputEuropean();
		
		
		
};

Date::Date(){				//  Constructor values set to 1/1/2001
	
	month = 1;				// January
	day = 1;
	year = 2001;
	
	monthConverter(month);
	
};

void Date::setDate(int m,int d, int y){
	
	// Validate Month Day Year
	if ((m >= 1 && m <= 12) && (d >= 1 && d <= 31) && (y >= 1950 && y <= 2020)){
		
		month = m;
		day = d;
		year = y;
		
		// Call the converter function after update is sucessful
		monthConverter(m);
		
		cout << "Update successful. " << endl;
	}
	// One or more invalid values, member variables not update
	else{
		
		cout << "Update unsuccessful. Date set to defualt" << endl;
	}
	}
	
		
	

//		Numerical format member function
void Date::outputNumeric(){
	
	cout << "Numeric:	" << month << "/" << day << "/" << year << endl;
}	


//		American format member function
void Date::outputAmerican(){
	
	cout << "American:	" << nameMonth << " " << day << ", " << year << endl;		// Used a month converter for later
}	


//		European format member function
void Date::outputEuropean(){
	
	cout << "European:	" << day << " " << nameMonth << " " << year << endl;		// Used a month converter for later
}


// Use condition statements to
// Converts integer month to a string month
string Date::monthConverter(int month){
	
	if (month == 1){
		
		nameMonth = "January";
	}
	else if (month == 2){
		
		nameMonth = "February";
	}
	else if (month == 3){
		
		nameMonth = "March";
	}
	else if (month == 4){
		
		nameMonth = "April";
	}
	else if (month == 5){
		
		nameMonth = "May";
	}
	else if (month == 6){
		
		nameMonth = "June";
	}
	else if (month == 7){
		
		nameMonth = "July";
	}
	else if (month == 8){
		
		nameMonth == "August";
	}
	else if (month == 9){
		
		nameMonth = "September";
	}
	else if (month == 10){
		
		nameMonth = "October";
	}
	else if (month == 11){
		
		nameMonth = "November";
	}
	else if (month == 12){
		
		nameMonth = "December";
	}
	
	return nameMonth;
}

int main(){
	//	Ask for user to enter month, day, and year in one line
	//  Display the date in numerous formats
	
	Date dateobj;		//	Declare a Date Object
	int inputMonth, inputDay, inputYear;
		
	// Get Date month, day, and year from Keyboard
	cout << "Enter the Month, Day, and Year of the Date:	";
	cin >> inputMonth >> inputDay >> inputYear;
	
	
	// Call member functions
	dateobj.setDate(inputMonth, inputDay, inputYear);
	
	
	
	// Call member functions to output user input
	dateobj.outputNumeric();
	dateobj.outputAmerican();
	dateobj.outputEuropean();
	
	return 0;
	
}
