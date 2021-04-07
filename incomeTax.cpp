#include <iostream>
#include <string>
#include <iomanip> //to set decimal precision
#include <cstdlib> //to use random function
#include <ctime> //to get diff results for random fuction
#include <cmath> //to use library math functions
#include <fstream> //for files

using namespace std;

int main()
{
    double taxAmount;
	double grossIncome;
	
	cout << "Input the gross income:  ";
	cin >> grossIncome;

	if (grossIncome >= 300000)
		taxAmount = (grossIncome - 10000) * 0.2;

	else if (grossIncome < 300000 && grossIncome >= 75000)
		taxAmount = (grossIncome - 10000) * 0.15;

	else if (grossIncome < 75000 && grossIncome >= 10000)
		taxAmount = (grossIncome - 10000) * 0.1;

	else
		taxAmount = 0;
        
	cout << "Gross income is " << grossIncome << " and the tax amount is " << taxAmount << endl;

    return 0;

}