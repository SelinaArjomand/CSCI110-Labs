/*  Program:     Prime Number
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     11/02/20
    Description: Determines whether number is prime or not (lab 9 EC)

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

int main() {
    int n;
    bool prime = true;

    cout << "Enter a positive integer: ";
    cin >> n;

    if (n == 0 || n == 1) {
        prime = false;
    }
    else {
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                prime = false;
            }
        }
    }
    if (prime)
        cout << n << " is a prime number." << endl;
    else
        cout << n << " is not a prime number." << endl;

    return 0;
}