/*  Program:     Determining Retail Store's Bonuses
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     9/30/20
    Description: User enters their monthly sales and sales increase percentage so the 
                 program can determine store and employee bonuses.

    I certify that the code below is my own work.
	
	Exception(s): N/A

*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

void getSales(double &sales);
void getIncrease(double &salesIncrease);
void storeBonus(double monthlySales, double &storeAmount);
void empBonus(double salesIncrease, double &empAmount);
void printBonus(double storeAmount, double empAmount);

int main()
{

	cout << "Author: Selina Arjomand\n";
    
    double monthlySales;
    double storeAmount;
    double empAmount;
    double salesIncrease;
    string keepGoing = "y";

    while(keepGoing == "y"){
        getSales(monthlySales);
        getIncrease(salesIncrease);
        storeBonus(monthlySales, storeAmount);
        empBonus(salesIncrease, empAmount);
        printBonus(storeAmount, empAmount);

        cout << "Do you want to run the program again?(Enter y for yes): ";
        cin >> keepGoing;
        
    }

	return 0;
}

void getSales(double &sales){
    cout << "Enter the monthly sales: $";
    cin >> sales;
}

void getIncrease(double &salesIncrease){
    cout << "Enter the percentage of the sales increase as a decimal: ";
    cin >> salesIncrease;
}

void storeBonus(double monthlySales, double &storeAmount){
    if (monthlySales >= 110000){
        storeAmount = 6000;
    }
    else if(monthlySales >= 100000){
        storeAmount = 5000;  
    } 
    else if (monthlySales >= 90000){
        storeAmount = 4000;
    }
    else if (monthlySales >= 80000){
        storeAmount = 3000;
    }
    else {
        storeAmount = 0;
    }
}

void empBonus(double salesIncrease, double &empAmount){
    if(salesIncrease >= .05){
        empAmount = 75;
    } 
    else if (salesIncrease >= .04){
        empAmount = 50;
    }
    else if (salesIncrease >= .03){
        empAmount = 40;
    }
    else {
        empAmount = 0;
    }
}

void printBonus(double storeAmount, double empAmount){
    cout << "The store bonus is $" << storeAmount << endl;
    cout << "The employee bonus is $" << empAmount << endl << endl;

    if (storeAmount == 6000 && empAmount == 75){
        cout << "Congrats! You have reached the highest bonus amounts possible!" << endl
        << endl;
    }
    
}