/*  Program:     Descending Bubble Swap
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     11/11/20
    Description: The program usese files to take in the number of 
                 pints donated during the drive. The program then
                 calculates the average, highest, and lowest
                 number of pints donanted. 

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

void bubbleSort(int arr[], int n);
void swap(int &a, int &b);

const int MAX = 5;
int main()
{
    int array[MAX];
    int number;

    for (int i = 0; i < MAX; i++)
    {
        cout << "Enter number: ";
        cin >> number;
        array[i] = number;
    }

    int index = 0;
    while (index < MAX-1)
    {
        bubbleSort(array, MAX);
        index++;
    }

    for (int i = 0; i < MAX; i++)
    {
        cout << array[i] << endl;
    }

    return 0;
}

void bubbleSort(int arr[], int n){
    for (int i = 0; i < n-1; i++)
    {
        if (arr[i] < arr[i+1])
        {
            swap(arr[i], arr[i+1]);
        }
    }   
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}