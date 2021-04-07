/*  Program:     Math Test
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     10/12/20
    Description: User enters their name and answers 5 random math questions, 
                 and the program determines how many they got correct.

    I certify that the code below is my own work.
	
	Exception(s): N/A
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

string inputName();
void generateNumbers(int &number1, int &number2);
int getAnswer(int number1, int number2);
void displayInfo(int right, string studentName);


int main()
{
    int counter;
	string studentName;
	int right = 0;
	int number1;
	int number2;
	int answer;

    srand(time(0));			// to generate random sequence each time
	studentName = inputName();

	//Loop to run program again
	for (counter = 0; counter < 5; counter++)
    {
        //calls functions
        generateNumbers(number1, number2);
        answer = getAnswer(number1, number2);
        if (answer == number1 + number2){
            cout << "Right" << endl << endl;
            right++;
        } else {
            cout << "Wrong" << endl << endl;

        }
    }	

	displayInfo(right, studentName);

    return 0;
}


string inputName() {
    string name;
	cout << "Enter student name: ";
	cin >> name;
	return name;
}

void generateNumbers(int &number1, int &number2) {
	number1 = rand() % 500 + 1;
	number2 = rand() % 500 + 1;
}

int getAnswer(int number1, int number2) {
	int answer;
	cout << "Equation is " << number1 << "+" << number2 << endl;
	cout << "Enter the sum: ";
	cin >> answer;
	return answer;
}

void displayInfo(int right, string studentName) {
	cout << "Information for " << studentName << endl;
	cout << "The number right: " << right << endl;
}

