#include <iostream> 
#include <string>
#include "printMenu.h"
#include "InputOutput.h"
#include "nCharString.h"
using namespace std;

// Main function to loop menu and user decisions
// Note: This function validates user's menu option inputs. 
void mainMenu() {
	string tmpStr;    // String to grab newline at the end of the line
	string quitCmd;   // User input to continue/quit menu
	string item;      // Stores user input for item name for menu option 1
	int userInput;    // Assigned with user menu option choice
	InputOutput io;   // InputOutput class object to initiate open, read/write, close of input/output file

	// Open, read, then close input file:
	io.openInputFile();
	io.readInputFile();
	io.setMapValue();
	io.closeInputFile();

	// Open, write, then close output file. Output file used as back up
	io.openOutputFile();
	io.writeOutputFile();   // "frequency.dat" Data File Creation for back up. Includes every unique produce item with number of times each item appears in the input file.
	io.closeOutputFile();

	// Print main menu:
	userInput = printMenu();   // printMenu() returns integer 1, 2, 3, or 4

	// Execute menu function based on user input:
	while (userInput != 4) {
		switch (userInput) {
			// Menu option 1: Look up and print the item sales count
			case 1:   
				while (quitCmd != "q") {
					try {
						// First print menu header:
						cout << nCharString(15, ' ');
						cout << "Item Sales Count";
						cout << nCharString(15, ' ') << endl;
						cout << nCharString(46, '=') << endl;
						cout << "Enter the produce item to look for (case-sensitive):" << endl;

						// Get user item input and return item frequency from the Map:
						cin >> item;
						cout << "Sales Count: " << io.getMapValue(item) << endl << endl;
						
					}
					// Catch exceptions due to typos or item missing from the list:
					catch (logic_error& excpt) {
						cout << "Invalid item. Please try again." << endl << endl;

					}

					// Prompt user to continue/quit:
					cout << "Enter any key to look for another item ('q' to exit to menu): " << endl;
					getline(cin, tmpStr);
					getline(cin, quitCmd);
				}
				break;

			// Menu option 2: Print Summary of Item Sales Count
			case 2:   
				// First print menu header:
				cout << nCharString(11, ' ');
				cout << "Item Sales Count Summary";
				cout << nCharString(11, ' ') << endl;
				cout << nCharString(46, '=') << endl << endl;
				io.printList();   // Call printList function from the io class object

				// Prompt user to continue:
				cout << endl << "Enter any key to return to menu" << endl;
				getline(cin, tmpStr);

				break;

			// Menu option 3: Print Histogram of Item Sales Count
			case 3:   
				// First print menu header:
				cout << nCharString(10, ' ');
				cout << "Item Sales Count Histogram";
				cout << nCharString(10, ' ') << endl;
				cout << nCharString(46, '=') << endl << endl;
				io.printHist();   // Call printList function from the io class object

				// Prompt user to continue:
				cout << endl << "Enter any key to return to menu" << endl;
				getline(cin, tmpStr);

				break;
		}
		
		// Print main menu and get user menu choice at the end of loop:
		userInput = printMenu();
	}
}