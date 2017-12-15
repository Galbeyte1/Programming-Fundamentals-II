//*****************************************************************************/
//
//Program   : Monkey Food 
//Programmer: Galbeyte Salad
//Completed : 11/19/2017
//Status    : COMPLETE
//
//****************************************************************************/
#include<iostream>
#include<iomanip>
#include<string>
using namespace std;

//	Prototypes
float inputPounds(float a[][7], int rowSize, const int rows, const int columns, string b[], int colSize);
float averagePounds(float a[][7], int rowSize, const int rows, const int columns);
float printTable(float a[][7], int rowSize, const int rows, const int columns, string b[], int colSize);
float leastAmount(float a[][7], int rowSize, const int rows, const int columns);
float largestAmount(float a[][7], int rowSize, const int rows, const int columns);

int main(){
	
	// Initalized Variables
	const int rows = 3;
	const int columns = 7;
	
	// Initialize days of the week 2D Array
	string dayOfWeek[7] = {"Sun", "Mon", "Tue", "Wed", "Thu", "Fri", "Sat"};
	
	// Initialize 2D Arrays
	float pounds[rows][columns];
	
	// Call the functions
	cout << inputPounds(pounds, rows, rows, columns, dayOfWeek, columns);
	
	
	// Print the table input
	cout << printTable(pounds, rows, rows, columns, dayOfWeek, columns);
	cout << endl;
	
	// Show the average
	cout << "The average food eaten per day by all monkeys     : " << averagePounds(pounds, rows, rows, columns) << endl;
	cout << "The least amount of food eaten by any monkey      : " << leastAmount(pounds, rows, rows, columns) << endl;
	cout << "The largest amount of food eaten per by any monkey: " << largestAmount(pounds, rows, rows, columns) << endl;
	
	
	return 0;
}
float printTable(float a[][7], int rowSize, const int rows, const int columns, string b[], int colSize){
	
	int width = 13;
	
	// Display the contents of the 2D Array in table format
	cout << fixed << showpoint << setprecision(2) << endl;
	cout << "Monkeys" << setw(6) << b[0] << setw(width) << b[1] << setw(width) << b[2] << setw(width) << b[3] << setw(width) <<  b[4] << setw(width) << b[5] << setw(width) << b[6] << endl;
	
	for (int j = 0; j <= (rows - 1); j++){
			
		cout << (j + 1) << setw(width) << a[j][0] << setw(width) << a[j][1] << setw(width) <<  a[j][2] << setw(width) << a[j][3] << setw(width) << a[j][4] << setw(width) << a[j][5] << setw(width) <<  a[j][6] << endl;
	}
}
float inputPounds(float a[][7], int rowSize, const int rows, const int columns, string b[], int colSize){
	
	
	for (int j = 0; j <= (rows - 1); j++){
		
		for (int i = 0; i <= (columns - 1); i++){
			
			cout << "Enter pounds eaten by Monkey " << (j + 1) << " on " << b[i] << ":	";
			cin >> a[j][i];
			
			if (a[j][i] < 0){
			
			cout << "Invalid Input. Must enter positive number of pounds eaten by Monkey " << (j + 1) << " on " << b[i] << ":	";
			cin >> a[j][i];
			}
		}
	}	
}
float averagePounds(float a[][7], int rowSize, const int rows, const int columns){
	
	float sum;
	float average;
	float numberOfFeedings = (rows * columns);
	
	for (int j = 0; j <= (rows - 1); j++){
		
		for (int i = 0; i <= (columns - 1); i++){
	
		sum += a[j][i];
		}
	}
	average = (sum / numberOfFeedings);
	
	return average;
}
float leastAmount(float a[][7], int rowSize, const int rows, const int columns){
	
	float least = 1000;
    
    for (int j = 0; j <= (rows - 1); j++){
        
        for (int i = 0; i <= (columns - 1); i++){
            
            if (a[j][i] < least){
                
                least = a[j][i];
            }
            
            }
        }
        
    return least;
}
float largestAmount(float a[][7], int rowSize, const int rows, const int columns){
	
	float largest = 0;
    
    for (int j = 0; j <= (rows - 1); j++){
        
        for (int i = 0; i <= (columns - 1); i++){
            
            if (a[j][i] > largest){
                
                largest = a[j][i];
            }
            
            }
        }
        
    return largest;
}
