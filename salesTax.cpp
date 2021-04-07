/*  Program:     Calculating Sales Tax
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     9/15/20
    Description: User enters their total sales and the program uses it to calulate county, state, and total sales tax.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void inputData(double &totalSales);
void calcCounty(double totalSales, double &countyTax);
void calcState(double totalSales, double &stateTax);
void calcTotalTax(double &totalTax, double countyTax, double stateTax);
void displayTaxes(double totalTax, double countyTax, double stateTax);

int main()
{

	cout << "Author: Selina Arjomand\n";
    
    double totalSales;
    double countyTax;
    double stateTax;
    double totalTax;

    inputData(totalSales);
    calcCounty(totalSales, countyTax);
    calcState(totalSales, stateTax);
    calcTotalTax(totalTax, countyTax, stateTax);
    displayTaxes(totalTax, countyTax, stateTax);

	return 0;
}

void inputData(double &totalSales){
    cout << "Enter the total sales for the month: " << endl;
    cin >> totalSales;
}

void calcCounty(double totalSales, double &countyTax){
    countyTax = totalSales * 0.02;
}

void calcState(double totalSales, double &stateTax){
    stateTax = totalSales * 0.04;
}

void calcTotalTax(double &totalTax, double countyTax, double stateTax){
    totalTax = countyTax + stateTax;
}

void displayTaxes(double totalTax, double countyTax, double stateTax){
    cout << fixed << showpoint << setprecision(2);

    cout << "County Sales Tax: " << setw(10) << countyTax << endl;
    cout << "State Sales Tax:  " << setw(10) << stateTax << endl;
    cout << "Total Sales Tax:  " << setw(10) << totalTax << endl;
    
}