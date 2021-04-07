/*  Program: Miles to Kilometers    
    Author: Selina Arjomand     
    Class:	CSCI 140 TTh     
    Date:	03/01/21     
    Description: This program converts miles to kilometers.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <cmath>

using namespace std;

int main()
{

	cout << "Author: Selina Arjomand\n";

    double miles;

    cout << "Enter miles traveled: ";
    cin >> miles;

    cout << miles << " mile(s) = " << miles * 1.609 << " kilometer(s)." << endl;

	return 0;
}