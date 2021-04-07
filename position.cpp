/*  Program:     Return Character Position
    Author:      Selina Arjomand
    Class:	     CSCI 110 MW
    Date:	     11/22/20
    Description: The program takes in a string and character 
                 and locates that character's position in 
                 the string.

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

int findChar(char c, string str);

int main()
{
    cout << "Author: Selina Arjomand\n\n";

    string str;
    char c;
    int index;

    cout << "Enter a string: ";
    getline(cin, str);

    cout << "Enter a character: ";
    cin >> c;

    index = findChar(c, str);

    if(index == -1)
    {
        cout << "The character '" << c << "' was not found in this string." << endl;
    }
    else
    {
        cout << "The character '" << c << "' is at index: " << index << endl;
    }

    return 0;
}

int findChar(char c, string str){
	bool found = false;
	int size = str.length();
	int index = 0;

	while(found == false && index < size){
		if(c == str[index]){
			found = true;
			return index;
			break;
		}
		index++;
	}

	if(found == false){
		return -1;
	}

}