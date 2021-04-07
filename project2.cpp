/*  Program:     Project 2: Statistical Calculator
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     11/11/20
    Description: The program makes an array from files or 
                 keyboard input. The program then sorts the
                 array in descending order and calculates the
                 array's maximum value, average, median, and
                 standard deviation.

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
void inputListFile(double arr[], int &count);
void inputList(double arr[], int &count);
void printList(double arr[], int n, int valuesPerLine);
void sortDescending(double arr[], int n);
void swap(int &a, int &b);
int maxValue(double arr[], int n);
double averageList(double arr[], int n);
double medianSortedList(double arr[], int n);
double stdDeviation(double arr[], int n);
void printStats(double max, double ave, double med, double std);


const int MAX_VALUES = 20;
int main()
{
    cout << "Selina Arjomand's Statistical Calculator\n\n";
    
    //variables
    double list[MAX_VALUES];
    double max;
    double avg;
    double median;
    double stdev;
    int n = 0;
    int option;

    while(option != 4){
        option = getMenuOption();
        switch (option) {
            case 1:
                n = 3;          
                inputListFile(list, n);
                cout << "There are " << n << " values in the data set." << endl << endl;

                //Print Original List
                cout << "Original List: " << endl;
                printList(list, n, 5);
                cout << endl << endl;

                //Print Descending List
                cout << "Descending List: " << endl;
                sortDescending(list, n);
                printList(list, n, 6);
                cout << endl << endl;

                //Get Stats
                max = list[0];
                avg = averageList(list, n);
                median = medianSortedList(list, n);
                stdev = stdDeviation(list, n);

                //Print Stats
                printStats(max, avg, median, stdev);

                break;

            case 2:            
                inputList(list, n);

                //Print Original List
                cout << "Original List: " << endl;
                printList(list, n, 5);
                cout << endl << endl;
                
                //Print Descending List
                cout << "Descending List: " << endl;
                sortDescending(list, n);
                printList(list, n, 6);
                cout << endl << endl;
                
                //Get Stats
                max = list[0];
                avg = averageList(list, n);
                median = medianSortedList(list, n);
                stdev = stdDeviation(list, n);

                //Print Stats
                printStats(max, avg, median, stdev);

                break;

            case 3:  
                n = MAX_VALUES;         
                inputListFile(list, n);
                cout << "There are " << n << " values in the data set." << endl << endl;

                //Print Original List
                cout << "Original List: " << endl;
                printList(list, n, 5);
                cout << endl << endl;

                //Print Descending List
                cout << "Descending List: " << endl;
                sortDescending(list, n);
                printList(list, n, 6);
                cout << endl << endl;

                //Get Stats
                max = list[0];
                avg = averageList(list, n);
                median = medianSortedList(list, n);
                stdev = stdDeviation(list, n);

                //Print Stats
                printStats(max, avg, median, stdev);

                break;

            case 4:           
                cout << "Thanks for using my statistical calculator.\n";
                break;

            default:         
                cout << "Invalid selection\n";
                break;
        }
    }
    return 0;
}

int getMenuOption(){
    int input;
   
    cout << "1. Use stored data\n";
    cout << "2. Input data from keyboard\n";
    cout << "3. Input data from a file\n";
    cout << "4. Quit\n\n";
    cout << "Enter your selection: ";
    cin >> input;
    return input;
}

//input list through file
void inputListFile(double arr[], int &count){
    ifstream listInFile;
    double value;

    listInFile.open("p2Input.txt");
    if (!listInFile)
    {
        cout << "Enter opening file for input. Stop program now." << endl;
        return;
    }
	
    listInFile >> value;
    for (int i = 0; i < count; i++)
    {
        arr[i] = value;
        listInFile >> value;
    }
    listInFile.close();
}

//input list through keyboard
void inputList(double arr[], int &count){
    double value;

    cout << "Enter one value at a time (at least 3 and up to 20)." << endl;
    cout << "You must enter valid data or program will not work." << endl;
	cout << "Enter -1 to signal end of data(-1 or -1.0)." << endl << endl;
    cout << "Please enter a value --> ";
	cin >> value;

	while(!(value == -1 || value == -1.0)){
        arr[count] = value;
        count++;
		cout << "Please enter a value --> ";
		cin >> value;
	}
    cout << "There are " << count << " values in the data set." << endl << endl;
}

//print the original and new arrays
void printList(double arr[], int n, int valuesPerLine){
    int index = 0;
    while (n > 0)
    {
        for (int i = 0; i < valuesPerLine; i++)
        {
            if (n > 0)
            {
                cout << arr[index] << "     ";
                index++;
                n--;
            }
        }
        cout << endl;
    }
}

//reorder list in descending order, calls on swap module
void sortDescending(double arr[], int n){
    int index = 0;
    while (index < n-1)
    {
        for (int i = 0; i < n-1; i++)
        {
            if (arr[i] < arr[i+1])
            {
                swap(arr[i], arr[i+1]);
            }
        }
        index++;
    }
}

void swap(int &a, int &b){
    int temp = a;
    a = b;
    b = temp;
}

//THE STATS: Avg, Median, Std Dev

double averageList(double arr[], int n){
    double total = 0;
    double avg;
    for (int i = 0; i < n; i++)
    {
        total = total + arr[i];
    }
    avg = total / n;
    return avg;
}

double medianSortedList(double arr[], int n){
    int index; 
    double median;

    if (n % 2 != 0) {
        index = (n - 1) / 2;
        median = arr[index];
        return median; 

    } else {
        index = n / 2;
        median = (arr[index] + arr[index-1]) / 2;
        return median;
    }
}

double stdDeviation(double arr[], int n){
    double total = 0;
    double mean;
    double standardDeviation = 0;

    for (int i = 0; i < n; i++)
    {
        total = total + arr[i];
    }
    mean = total / n;

    for(int i = 0; i < n; ++i)
    {
        standardDeviation += pow(arr[i] - mean, 2);
    }

    return sqrt(standardDeviation / n);
}

void printStats(double max, double ave, double med, double std){
    cout << fixed << showpoint << setprecision(1);

    cout << "Maximum:             " << max << endl;
    cout << "Average:             " << ave << endl;
    cout << "Median:              " << med << endl;
    cout << "Standard Deviation:  " << std << endl << endl;
} 

