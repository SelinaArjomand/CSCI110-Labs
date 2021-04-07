/*  Program:     Project 2: Statistical Calculator
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     11/28/20
    Description: The program performs recursion 3 different
                 ways and lets the user choose their 
                 option from a menu.

    I certify that the code below is my own work.
	
	Exception(s): N/A
*/

#include <iostream>
#include <string>
#include <iomanip> //to set decimal precision
#include <cstdlib> //to use random function
#include <ctime> //to get diff results for random fuction
#include <cmath> //to use library math functions
#include <fstream> //for files

using namespace std;

int getMenuOption();
int factorial(int n);
int recFib(int n);
int mystery(int a, int b);

int main()
{
    cout << "Author: Selina Arjomand\n\n";
    
    //variables
    int n;
    int n2;
    int result;
    int option;

    while (option != 4) {
    
        option = getMenuOption();

        while(option < 1 || option > 4){
            cout << "That is an invalid selection. Enter 1, 2, 3, or 4: ";
            cin >> option;
        }

        if (option > 0 && option < 4){
            cout << "Enter the number: ";
            cin >> n;
        }

        switch (option) {
            case 1:
                result = factorial(n);
                break;

            case 2:            
                result = recFib(n);
                break;

            case 3:  
                cout << "Enter the second number: ";
                cin >> n2;
                result = mystery(n, n2);
                break;

            case 4:           
                cout << "Thanks for using my program.\n";
                break;

            default:         
                cout << "Invalid selection\n";
                break;
        }

        if (option > 0 && option < 4){
            cout << "The answer is: " << result << endl << endl;
        }

    }
    
    return 0;
}

int getMenuOption(){
    int input;
   
    cout << "1. Recursive Factorial\n";
    cout << "2. Recursive Fibonacci\n";
    cout << "3. Mystery Function\n";
    cout << "4. Quit\n\n";
    cout << "Enter your selection: ";
    cin >> input;
    return input;
}

int factorial(int n){
    int result;
    if (n == 1)         
        result = 1;
    else                
        result = n * factorial(n-1);
                    
    return result;
}

int recFib(int n){
    int result;
    if (n == 1 || n == 2)
        result = 1;         
    else  
        result = recFib(n-1) + recFib(n-2);

    return result;
}

int mystery(int a, int b){
    int result;         
    if (b == 0)              
        result = 1;        
    else              
        result = a * mystery(a, b-1);
      
    return result;
}