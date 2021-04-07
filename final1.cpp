/*  Program:     Lab Final Question 1
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     12/09/20
    Description: The program makes the pattern of
                 rectangles and right triangles.

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
void rectanglePattern(int rows, int columns);
void trianglePattern(int length, char c);

int main()
{
    int option;
    int rows;
    int columns;
    int triLength;
    char c;

    while(option != 3){
        option = getMenuOption();
        switch (option) {
            case 1:
                cout << "Enter the number of rows: ";
                cin >> rows;
                cout << "Enter the number of colums: ";
                cin >> columns;

                rectanglePattern(rows, columns);

                break;

            case 2:            
                cout << "Enter the base length: ";
                cin >> triLength;
                cout << "Enter the character you want the triangle out of: ";
                cin >> c;

                trianglePattern(triLength, c);

                break;

            case 3:
                cout << "Thanks for using my program.\n";
                break;

            default:         
                cout << "Invalid selection\n";
                break;
        }
    }
}

int getMenuOption(){
    int input;
   
    cout << "1. Make a rectangle\n";
    cout << "2. Make a triangle\n";
    cout << "3. Quit\n\n";
    cout << "Enter your selection: ";
    cin >> input;
    return input;
}

void rectanglePattern(int rows, int columns){
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            cout << "#";
        }
        cout << endl;
    }
    cout << endl << endl;
}

void trianglePattern(int length, char c){
    for(int i = 1; i <= length; i++)
    {
        for(int j = 1; j <= i; j++)
        {
            cout << c;
        }
        cout << endl;
    }
    cout << endl << endl;
}