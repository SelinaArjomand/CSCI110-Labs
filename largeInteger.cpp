/*  Program: Large Integers    
    Author: Selina Arjomand     
    Class:	CSCI 140 TTh     
    Date:	04/01/21     
    Description: This program intakes two large integer, stores them in
                 in arrays, adds them, and outputs the result.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <string>
#include <cmath> //to use library math functions

using namespace std;

void convertToInt(int numArray[], string num);
int addIntegers(int result[], int num1Array[], int num2Array[]);
void outputResult(int extra, int result[]);

int main()
{
    cout << "Author: Selina Arjomand\n";
    int MAX = 20;
    int num1Array[MAX];
    int num2Array[MAX];
    int result[MAX];

    string largeInt1;
    string largeInt2;
    string expression;
    int extra;

    cout << "Enter an expression --> ";
    cin >> largeInt1;
    cin >> expression;
    cin >> largeInt2;
    int int1Length = largeInt1.size();
    int int2Length = largeInt2.size();

    if ((int1Length > 20) || (int2Length > 20)) {
        cout << "Invalid operand(s)" << endl;

    } else {
        convertToInt(num1Array, largeInt1);
        convertToInt(num2Array, largeInt2);

        extra = addIntegers(result, num1Array, num2Array);
        
        for (int i = (MAX - int1Length); i < MAX; i++)
        {
            cout << num1Array[i];
        }
        cout << " + ";
        for (int i = (MAX - int2Length); i < MAX; i++)
        {
            cout << num2Array[i];
        }
        cout << " = ";
        outputResult(extra, result);
        
    }

}


void convertToInt(int numArray[], string num){
    int MAX = 20;
    int count = 0;
    int numlength = num.size();

    string temp;
    int tempNum;
    for (int i = MAX - 1; i >= (MAX - numlength); i--)
    {
        temp = num.at((numlength - 1) - count);
        tempNum = stoi(temp);
        numArray[i] = tempNum;
        count++;
    } 

    for (int i = 0; i < (MAX - numlength); i++)
    {
        numArray[i] = 0;
    } 
}

int addIntegers(int result[], int num1Array[], int num2Array[]){
    int MAX = 20;
    int extra = 0;
    for (int i = MAX - 1; i >= 0; i--)
    {
        result[i] = num1Array[i] + num2Array[i] + extra;
        if(result[i] > 9) {
            result[i] = result[i] - 10;
            extra = 1;
        } else {
            extra = 0;
        }
    } 
    return extra;
}

void outputResult(int extra, int result[]){
    int MAX = 20;
    //int resultLength;

    int count = 0;
    int i = 0;
    while (result[i] == 0)
    {
        count++;
        i++;
    }
    
    
    if (extra != 0){
        cout << "overflow" << endl;

    } else {
        for (int i = count; i < MAX; i++)
        {
            cout << result[i];
        }
        cout << endl;
    }
    
}