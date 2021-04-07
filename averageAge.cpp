/*  Program:     Average Age
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     10/12/20
    Description: User enters the number of ages so the program can determine 
                 the average of all the ages.

    I certify that the code below is my own work.
	
	Exception(s): N/A
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
    int counter;
    int totalAge = 0;
    double averageAge;
    int age;
    int number;

    cout << "How many ages do you want to enter? ";
    cin >> number;

    for (counter = 1; counter <= number; counter++)
    {
        cout << "Enter age: ";
		cin >> age;
		totalAge = totalAge + age;
    }

    averageAge = 1.0 * totalAge / number;

    cout << fixed << showpoint << setprecision(1);
    cout << "The average age is " << averageAge << endl;

    return 0;
    
} 
