/*  Program:     Project 1: Automated Highway Patrol
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     10/14/20
    Description: User the car's license plate, speed, and speed limit. 
                 The program will determine if a ticket needs to be 
                 issued, the ticket price, the number of tickets given 
                 out, the percent of ticketed vehicles, and the average 
                 ticket price.

    I certify that the code below is my own work.
	
	Exception(s): N/A
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

void getInfo(int &currentSpeed, int &speedLimit);
void getTicket(int speed, int speedLimit, bool &ticket);
void calcSpeedDiff(bool ticket, int speed, int speedLimit, int &speedDiff);
int ticketPrice(int speedDiff);
void displayInfo(bool ticket, int speedDiff, int ticketFee, string plateNum);
int getTicketsSum(int ticketFee, int &ticketSum);
double getPercentTicketed(int counter, int ticketsGiven);
double avgTicketPrice(int ticketSum, int ticketsGiven);
void displayData(int counter, int ticketsGiven, double percentTicketed, double avgTicketFee);

int main()
{
    string plateNum;
    int currentSpeed;
    int speedLimit;
    int speedOver;
    int speedUnder;
    int speedDiff;

    bool ticket;
    int ticketFee;
    int ticketSum = 0;

    int counter = 0;
    int ticketsGiven = 0;
    double percentTicketed;
    double avgTicketFee;

    cout << "Enter a license plate number: ";
    cin >> plateNum;

    while (plateNum != "QUIT")
    {
        counter++;
        getInfo(currentSpeed, speedLimit);
        getTicket(currentSpeed, speedLimit, ticket);
        calcSpeedDiff(ticket, currentSpeed, speedLimit, speedDiff);

        if (ticket == true) {
            ticketsGiven++;
            ticketFee = ticketPrice(speedDiff);
            ticketSum = getTicketsSum(ticketFee, ticketSum);
        }
        displayInfo(ticket, speedDiff, ticketFee, plateNum);

        cout << "Enter a license plate number: ";
        cin >> plateNum;
    }
    percentTicketed = getPercentTicketed(counter, ticketsGiven);
    avgTicketFee = avgTicketPrice(ticketSum, ticketsGiven); 
    displayData(counter, ticketsGiven, percentTicketed, avgTicketFee);

    return 0;

}    

void getInfo(int &currentSpeed, int &speedLimit) {
    cout << "Enter current vehicle's speed: ";
    cin >> currentSpeed;
    cout << "Enter speed limit in the zone: ";
    cin >> speedLimit;
}

void getTicket(int speed, int speedLimit, bool &ticket) {
    if (speed >= speedLimit + 5){
        ticket = true;
    } else {
        ticket = false;   
    }
}

void calcSpeedDiff(bool ticket, int speed, int speedLimit, int &speedDiff) {
    if (ticket ==true){
        speedDiff = speed - speedLimit;
    } else {
        speedDiff = speedLimit - speed;
        if (speed >= speedLimit){
            speedDiff = speedDiff * -1;
        }
    }
}

int ticketPrice(int speedDiff) {
    int baseFee = 150;
    int additionalFee;
    int total;
    if (speedDiff < 20) {
        additionalFee = speedDiff * 5;

    } else if (speedDiff > 20 && speedDiff <=50) {
        additionalFee = speedDiff * 10;

    } else {
        additionalFee = 850;

    }
    total = baseFee + additionalFee;
    return total;
}

void displayInfo(bool ticket, int speedDiff, int ticketFee, string plateNum) {
    if (ticket == true){
        cout << "Vehicle travelled " << speedDiff << " miles over the speed limit." << endl;
        cout << "A ticket of $" << ticketFee << " is issued to " << plateNum << endl << endl;
    } else {
        cout << "Vehicle travelled " << speedDiff << " miles under the speed limit." << endl;
        cout << "No ticket is issued to " << plateNum << "." << endl << endl;
    }
} 

int getTicketsSum(int ticketFee, int &ticketSum) {
    ticketSum = ticketSum + ticketFee;
    return ticketSum;
}

double getPercentTicketed(int counter, int ticketsGiven) {
    double percentTicketed = 1.0 * ticketsGiven / counter;
    percentTicketed = percentTicketed * 100;
    return percentTicketed;
}

double avgTicketPrice(int ticketSum, int ticketsGiven) {
    double avg;
    avg = 1.0 * ticketSum / ticketsGiven;
    return avg;
}

void displayData(int counter, int ticketsGiven, double percentTicketed, double avgTicketFee) {
    cout << fixed << showpoint << setprecision(2);

    cout << endl << "Tickets were given to " << ticketsGiven << " out of " << counter << " vehicles." << endl;
    cout << "Percent of ticketed vehicles:  " << percentTicketed << "%" << endl;
    cout << "Average ticket amount:        " << avgTicketFee << "." << endl;
    cout << "Thank you for using our AHP program." << endl;
}