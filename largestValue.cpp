/*  Program:     Largest Value
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     10/12/20
    Description: User enters 4 numbers and the program 
                 determines which number is the largest.

    I certify that the code below is my own work.
	
	Exception(s): N/A
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

double max2(double a, double b);
double displayMax(double max);

int main()
{
    cout << "Author: Selina Arjomand\n";
    cout << "This program allows one to input four values." << endl;
    cout << "It uses function max2 to determine the maximum." << endl << endl;

    int counter;
    double num1;
    double num2;
    double num3;
    double num4;
    double max;

    //gets 4 numbers from user
   for (counter = 0; counter < 4; counter++)
    {
        if(counter == 0) {
            cout << "Please enter the first value " << setw(3) << "--> ";
            cin >> num1;

        } else if (counter == 1) {
            cout << "Please enter the second value" << setw(3) << "--> ";
            cin >> num2;

        } else if (counter == 2) {
            cout << "Please enter the third value " << setw(3) << "--> ";
            cin >> num3;

        } else {
            cout << "Please enter the fouth value " << setw(3) << "--> ";
            cin >> num4;

        }
    }

    //compares the 4 number and saves largest as max
    for (counter = 0; counter < 3; counter++)
    {
        if(counter == 0) {
            max = max2(num1, num2);

        } else if (counter == 1) {
            max = max2(num2, num3);

        } else if (counter == 2) {
            max = max2(num3, num4);

        }
    }

    displayMax(max);

    return 0;
}    


double max2(double a, double b) {
    double max;
    if (a > b){
        max = a;
    } else {
        max = b;
    }
    return max;
}

double displayMax(double max) {
    cout << fixed << showpoint << setprecision(1);
    cout << endl << "The largest value is " << max << endl;
}
