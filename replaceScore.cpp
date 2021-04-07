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

void getScores(int scores[], int n);
int getLow(int scores[], int n);

int main()
{
    int n;
    int score;
    int newScore;
    int lowest;

    cout << "Enter the number of test scores: ";
    cin >> n;
    
    int scores[n];
    getScores(scores, n);
    
    cout << "Enter the new score: ";
    cin >> newScore;
    cout << endl;

    lowest = getLow(scores, n);
    cout << "The lowest score was: " << scores[lowest] << endl;
    scores[lowest] = newScore;
    cout << "The lowest score has been changed to: " << scores[lowest] << endl;
}

void getScores(int scores[], int n){
	for (int i = 0; i < n; i++) {
        cout << "Enter score: ";
        cin >> scores[i];
    }
}

int getLow(int scores[], int n) {
    int lowest = scores[0];
    int location = 0;

    for (int i = 0; i < n; i++)
    {
        if (scores[i] < lowest)
        {
            lowest = scores[i];
            location = i;
        }
    }
    return location;
}