/*  Program:     Matrix
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     11/02/20
    Description: display matrix (lab 9 #1)

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

int getRow(int n);

int main()
{
    int n;
    int rows;
    int count;

    cout << "Enter n: ";
    cin >> n;
    count = n;
    rows = getRow(n);

    int matrix[rows][5];
    for (int i = 0; i < rows; i++)
    {      
        for (int j = 0; j < 5; j++)
        {
            if (count > 0)
            {
                matrix[i][j] = count;
                count--;
            }
        }
    }
    
    //print matrix
    count = n;
    for (int i = 0; i < rows; i++)
    {      
        for (int j = 0; j < 5; j++)
        {
            if (count > 0)
            {
                cout << matrix[i][j] << "   ";
                count--;
            }
        }
        cout << endl;
    }

}

int getRow(int n){
    int rows = n / 5;
    int r = n % 5;
    if (r != 0){
        rows++;
    }
    return rows;
}