/*  Program:     Median
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     11/02/20
    Description: return the median of 3 numbers (lab 9 #2)

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

double medianScore3(double s1, double s2, double s3);

int main()
{
    double s1;
    double s2;
    double s3;
    double median;

    cout << "Enter number: ";
    cin >> s1;
    cout << "Enter number: ";
    cin >> s2;
    cout << "Enter number: ";
    cin >> s3;  

    median = medianScore3(s1, s2, s3);
    cout << fixed << showpoint << setprecision(1);
    cout << "The median is: " << median << endl;
}

double medianScore3(double s1, double s2, double s3) {
    double temp;
    if (s1 > s2)
    {
        temp = s1;
        s1 = s2;
        s2 = temp;
    }
    if (s2 > s3)
    {
        temp = s2;
        s2 = s3;
        s3 = temp;
    }
    return s2;
}