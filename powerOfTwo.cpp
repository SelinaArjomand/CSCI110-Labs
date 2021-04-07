/*  Program: Power of Two    
    Author: Selina Arjomand     
    Class:	CSCI 140 TTh     
    Date:	03/01/21     
    Description: This program checks if a number is a power of 2.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <cmath>
#include <math.h>

using namespace std;

int main()
{

	cout << "Author: Selina Arjomand\n";

    int number;
    bool result = true;

    cout << "Enter number: ";
    cin >> number;

    if (number == 0){
        result = false;

    } else {
        while (number != 1){
            if (number%2 != 0){
                result = false;
            }
            number = number/2;
        }
    }

    if (result == true){
        cout << "yes" << endl;

    } else {
        cout << "no" << endl;

    }
    
	return 0;
}