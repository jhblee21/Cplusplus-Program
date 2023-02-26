#include <iostream>
#include <string>
#include "nCharString.h"
using namespace std;

// This function prints main menu,
// and gets/returns user menu choice:
int printMenu() {
	string userInput;   // Get user menu selection as string
	int i;              // Convert user menu selection from string to int after validating

	cin.clear();

	// Loop and print main menu until user inputs valid menu selection:
	while ((userInput != "1") && 
		   (userInput != "2") &&
		   (userInput != "3") &&
		   (userInput != "4")
		  ) 
	{
	// Print main menu header:
		cout << endl << nCharString(7, ' ') << "CORNER GROCER ITEM SALES REPORT" << nCharString(8, ' ') << endl;
		// first print width *'s followed by an endl
		cout << nCharString(46, '*') << endl;
		cout << nCharString(2, ' ') << "Please select from the following menu:" << endl;
		cout << nCharString(2, ' ') << "(Enter 1, 2, 3, or 4)" << endl << endl;
		cout << "* 1 - Look Up Item Sales Count" << nCharString(15, ' ') << "*" << endl << endl;
		cout << "* 2 - Print Summary of Item Sales Count" << nCharString(6, ' ') << "*" << endl << endl;
		cout << "* 3 - Print Histogram of Item Sales Count" << nCharString(4, ' ') << "*" << endl << endl;
		cout << "* 4 - Exit Program" << nCharString(27, ' ') << "*" << endl;
		// finally print the bottom border width *'s followed by an endl
		cout << nCharString(46, '*') << endl;

		// Validate user menu selection input:
		try {
			getline(cin, userInput);
			if
				(
					(userInput != "1") &&
					(userInput != "2") &&
					(userInput != "3") &&
					(userInput != "4")
				)
			{
				// Exception if user does not input 1, 2, 3, or 4
				throw runtime_error("Invalid entry. Please enter a valid menu option.");
			}
			else {
				// If user input is 1, 2, 3, or 4: convert user input from string to integer:
				i = stoi(userInput);
			}
		}
		catch (runtime_error& excpt) {
			cout << excpt.what() << endl;
		}
		cout << endl;
	}

	// return user menu selection as int to mainMenu function:
	return i;
}
