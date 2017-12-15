//*****************************************************************************/
//
//Program   : Test Scores 
//Programmer: Galbeyte Salad
//Completed : 12/03/2017
//Status    : COMPLETE
//
//*****************************************************************************/
#include<iostream>
#include<iomanip>
using namespace std;

int gradesCheck(int a, int col);
float gradesAvg(int a[], int cols);
void inputGrades(int a[], int SIZE);
int sort(int a[], int SIZE);

int main(){
	
	// Initialize Size variable
	int SIZE;
	
	// Store the number of grades the users wishes in the size variable
	cout << "Enter the number of grades you wish to input:	";
	cin >> SIZE;
	
	// Declare an array of the size the user inputed
	int grades[SIZE];
	
	// Call the function to input grades and pass the
	// Array Grades and the Size as parameters
	inputGrades(grades, SIZE);
	
	// Call the function to sort and display the grades and pass the
	// grades array and size
	sort(grades, SIZE);
	
	return 0;
}
int gradesCheck(int a, int col){
	
	while (a < 0 || a > 104){
	
	cout << "Invalid Input. Enter Grade " << (col + 1) << " :	";
	cin >> a;
	
	}
	return a;
}
float gradesAvg(int a[], int cols){
	
	int sum;
	int avg;
	
	for (int i = 0; i < cols; i++){
		
		sum += a[i];
	}
	
	avg = sum / cols;
	return avg;
}
void inputGrades(int a[], int SIZE){
	
	for (int i = 0; i < SIZE; i++){
		
		cout << "Enter Grade " << (i + 1) << " :	";
		cin >> a[i];
		
		a[i] = gradesCheck(a[i], i); 
	}
}
int sort(int a[], int SIZE){
	
	
	
	for (int i = 0; i < SIZE - 1; i++){
		
		double temp;
		
		for (int j = (i + 1); j < SIZE; j++){
			
			if (a[i] > a[j]){
				
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		
		}
	}
	
	//Display
	cout << fixed << showpoint << setprecision(1) << endl;
	cout << setw(17) << "Grade" << endl;
	cout << setw(17) << "-----" << endl;
	for (int i = 0; i < SIZE; i++){
		
		cout << setw(17) << a[i] << endl;
	}
	cout << setw(17) << "-----" << endl;
	cout << "Avergae" << setw(10) << gradesAvg(a, SIZE) << endl;
	
}
