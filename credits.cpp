/*  Program:     Calculating Credits
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     9/07/20
    Description: Get the user's name, major, credits needed and taken, and then calcute credits remaining to take.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <string>

using namespace std;

int main()
{
    cout << "Author: Selina Arjomand\n";

    double creditsTaken;
    double creditsDegree;
    double creditsLeft;
    string studentName;
    string degreeName;

    cout << "Enter student first name: " << endl;
    cin >> studentName;

    cout << "Enter degree's name: " << endl;
    getline(cin, degreeName);
    getline(cin, degreeName);

    cout << "Enter the number of credits in degree: " << endl;
    cin >> creditsDegree;

    cout << "Enter the number of credits you have completed: " << endl;
    cin >> creditsTaken;
    
    creditsLeft = creditsDegree - creditsTaken;
     
    cout << "The student's first name is " << studentName << endl;
    cout << "The student's degree is " << degreeName << endl;
    cout << "The student has " << creditsLeft << " credits left to complete before graduation." << endl;

	return 0;
}