/*  Program:     Total Bottles
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     10/19/20
    Description: User imputs the number of days and
                 the number of bottles returned each day.
                 The program will find the total
                 number of bottles returned. 

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

int getTotalBottles(int days);

int main()
{
    cout << "Author: Selina Arjomand\n";

    int days;
    int myBottles;

    cout << "Enter the number of days: ";
    cin >> days;

    myBottles = getTotalBottles(days);
    cout << "The total number of bottles is " << myBottles << endl;

    return 0;
}

int getTotalBottles(int days) {
	int totalBottles = 0;
	int todayBottles;
	int counter;
 	
    for (counter = 1; counter<= days; counter++){
      	cout << "Enter number of bottles returned: ";
        cin >> todayBottles;
		
		while(todayBottles < 0){
			cout << "Error: Cannot enter a negative number. Please input a positive number." << endl;
			cout << "Enter number of bottles returned: ";
	        cin >> todayBottles;
        }
        totalBottles = totalBottles + todayBottles;
	}
	return totalBottles;
}
