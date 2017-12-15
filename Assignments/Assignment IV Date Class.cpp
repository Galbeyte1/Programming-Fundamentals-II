#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

class Date{
	
	private: 					// Private member variables
	
		int day;
		int month;
		int year;
		
	public:						// Public Member Function Prototypes
	
		Date();				//Default Constructor 
		void setDate(int month, int day, int year);
		
		
		//	Not sure if I need these get member functions
		//		seems like it would defeat the purpose of the
		//		output member function
		int getMonth(){
			
			return month;
		}
		
		int getDay(){
			
			return day;
		}
		
		int getYear(){
			
			return year;
		}
		
		//	Pass the data coming from the get member functions through output member functions?
		void outputNumeric();
		void outputAmerican();
		void outputEurpean();
		// Should I include a dateConverter(); ?
		
};

Date::Date(){				//  Constructor values set to 1/1/2001
	
	day = 1;
	month = 1;				// January
	year = 2001;
	
};

void Date::setDate(int m, int d, int y){
	
	// Validate Month
	if (m >= 1 || m <= 12){
		
		month = m;
	}
	
	// Validate Day
	if (d >= 1 || d <= 31){
		
		day = d;
	}
	
	// Validate Year
	if (y >= 1950 || y <= 2020){
		
		year = y;	
	}
}

void Date::outputNumeric(){
	
}	
	
void Date::outputAmerican(){
	
}	

void Date::outputEurpean(){
	
}


int main(){
	//	Ask for user to enter month, day, and year in one line
	//  Display the date in numerous formats
	
	Date user;		//	Declare a Date Object
	int userMonth, userDay, userYear;
	
	
	// Get Date month, day, and year from Keyboard
	cout << "Enter the Month, Day, and Year of the Date:	";
	cin >> userMonth;
	cin.ignore();
	cin >> userDay;
	cin.ignore();
	cin >> userYear;
	cin.ignore();
	
	// Call member functions
	user.setDate(userMonth, userDay, userYear);
	
	// Call member functions to output user information to display	 //	MISSING INFO HERE!!!!!!!
	cout << "Numeric :	" << endl;
	cout << "American:	" << endl;
	cout << "European:	" << endl;
	
	return 0;
	
}
