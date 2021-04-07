/*  Program:     Blood Drive
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     10/26/20
    Description: The program takes in the number of pints 
                 donated during the drive based on a seven-
                 hour drive period. The program then
                 calculates the average, highest, and lowest
                 number of pints donanted. 

    I certify that the code below is my own work.
	
	Exception(s): N/A
*/

#include <iostream>
#include <string>
#include <iomanip> //to set decimal precision
#include <cstdlib> //to use random function
#include <ctime> //to get diff results for random fuction
#include <cmath> //to use library math functions

using namespace std;

void getPints(double pints[], int hours);
double getAverage(double pints[], int hours);
double getHigh(double pints[ ], int hours);
double getLow(double pints[ ], int hours);
bool isAscending(double a[], int n);
void displayInfo(double averagePints, double highPints, double lowPints, bool ascending);

const int MAX_HOURS = 7;
int main()
{
    cout << "Author: Selina Arjomand\n";

	//Declare local variables
	string again = "yes";
	double pints[MAX_HOURS];
    double averagePints;
    double highPints;
    double lowPints;
    bool ascending;

    while (again == "yes")
    {
        cout << "Enter data for the 7 hours" << endl << endl;
        getPints(pints, MAX_HOURS);
        averagePints = getAverage(pints, MAX_HOURS);
        highPints = getHigh(pints, MAX_HOURS);
        lowPints = getLow(pints, MAX_HOURS);
        ascending = isAscending(pints, MAX_HOURS);
        displayInfo(averagePints, highPints, lowPints, ascending);

        cout << "Do you want to run again (yes or no)? ";
        cin >> again;
    }
}

void getPints(double pints[], int hours){
	int counter;

    for (counter = 0; counter < hours; counter++){
        cout << "Enter pints collected: ";
        cin >> pints[counter];
    }
}

double getAverage(double pints[], int hours){
	int counter;
	double totalPints = 0;
	double averagePints;
    for (counter = 0; counter < hours; counter++)
    {
        totalPints = totalPints + pints[counter];
    }

    averagePints = totalPints / counter;
    return averagePints;
}

double getHigh(double pints[], int hours){
    int index;
    double highest = pints[0];

    for (index = 0; index < hours; index++)
    {
        if (pints[index] > highest)
        {
            highest = pints[index];
        }
    }
    return highest;
}

double getLow(double pints[], int hours){
    int index;
    double lowest = pints[0];

    for (index = 0; index < hours; index++)
    {
        if (pints[index] < lowest)
        {
            lowest = pints[index];
        }
    }
    return lowest;
}

bool isAscending(double a[], int n){
	bool ascending = true;
	for(int i = 0; i < n-1; i++){
		if(a[i] > a[i+1]){
			ascending = false;
		}
	}
	return ascending;
}

void displayInfo(double averagePints, double highPints, double lowPints, bool ascending){
    cout << fixed << showpoint << setprecision(1);

    cout << "The average number of pints donated: " << averagePints << endl;
    cout << "The highest number of pints donated: " << highPints << endl;
    cout << "The lowest number of pints donated: " << lowPints << endl;
    if (ascending == true)
    {
        cout << "The array is in ascending order." << endl << endl;

    } else {
        cout << "The array is not in ascending order." << endl << endl;

    }
}