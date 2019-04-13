/*************************************************************************************************************************
*
*   Source.cpp
*   Rod Cutting/Dynamic Programming & Activity-Selection Problem/Greedy Algorithm
*
*   Created by Zachary Torricelli on 3/18/19.
*   Copyright © 2019 Zachary Torricelli. All rights reserved.
*
*   Implement your dynamic programming algorithms to solve rod cutting.
*   Read Page 360, Chapter 15 in your textbook for the problem definition.
*      1. Use the same price list as in your textbook (Figure 15.1 on Page 360).
*      2. Test n=1…10 and see if you can get the same results as in your book (Page 362).
*      3. Implement and test either top-down or bottom-up version (refer to pseudocode on pages 365-369).
*         Compare and explain the differences in your report.
*
*   Implement your greedy algorithm for the activity-selection problem.
*   Read Page 415, Chapter 16 in your textbook for the problem definition.
*      1. Use the same activity list as in your textbook (Page 415).
*      2. Implement and test a greedy algorithm to solve the problem (either recursive or iterative version is OK).
*
*************************************************************************************************************************/



// Include statements and using directive
#include <iostream>
#include <algorithm>
#define SIZE 10
#define CAPACITY 11

using namespace std;


// Function prototypes
void mainMenu();
void rodCutterMenu();
void activitySelectionMenu();
int rodCutterTopDown(int[], int);
void activitySelector(int[], int[]);


// Main Driver Function
int main()
{

	// Calls the main menu function
	mainMenu();

	system("pause");
	return 0;

}



// Main menu function
void mainMenu()
{

	// Function variable
	int choice = 3;

	// Displays a welcome message to the console
	cout << "Welcome to Zac's Rod Cutter and Activity Selector!" << endl;
	cout << "Please enter a number (1-3)." << endl << endl;

	// Do-while loop for the activity selector menu
	do
	{

		// Displays a menu to the console
		cout << "1. Rod Cutter" << endl;
		cout << "2. Activity Selector" << endl;
		cout << "3. Exit the Program" << endl << endl;

		cin >> choice;


		// Makes sure the user inputs a valid option
		while (cin.fail())
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Please enter a number (1-3)." << endl << endl;
			cin >> choice;

		}


		// Switch statement to go between options
		switch (choice)
		{

			// Case 1 will alow the user to view the length and prices
		case 1:

			system("CLS");

			// Calls the menu function for the rod cutter
			rodCutterMenu();

			break;


			// Case 2 will allow the user to select a length and display the maximum price value
		case 2:

			system("CLS");

			// Calls the menu function for the activity-selection
			activitySelectionMenu();

			break;


			// Case 3 will exit the program
		case 3:

			exit(0);

			// Default case will collect the invalid options input and let the user try again
		default:

			system("CLS");
			cout << "Invalid selection. Try again" << endl;

		}


	} while (choice != 3);

}



// Menu function for the rod cutter problem
void rodCutterMenu()
{

	// Function variables
	int choice = 3;
	int lengthIndex[SIZE];
	int priceIndex[] = { 1, 5, 8, 9, 10, 17, 17, 20, 24, 30 };
	int length = -1;
	int maximumPrice;


	// Displays a welcome message to the console
	cout << "Welcome to Zac's Rod Cutter!" << endl;
	cout << "Please enter a number (1-3)." << endl << endl;


	// Do-while loop for the rod cutter menu
	do
	{

		// Displays a menu to the console
		cout << "1. View Length and Prices Chart" << endl;
		cout << "2. Select Length to View Maximum Price" << endl;
		cout << "3. Exit Rod Cutter" << endl << endl;

		cin >> choice;


		// Makes sure the user inputs a valid option
		while (cin.fail())
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Please enter a number (1-3)." << endl << endl;
			cin >> choice;

		}


		// Switch statement to go between options
		switch (choice)
		{

			// Case 1 will alow the user to view the length and prices
		case 1:

			system("CLS");

			cout << "Length:\t";


			// For loop to display the list of possible lengths
			for (int i = 1; i < SIZE + 1; i++)
			{

				lengthIndex[i] = i;
				cout << lengthIndex[i] << "\t";

			}


			cout << endl << "----------------------------------------------------------------------------------------------" << endl;


			cout << "Price:\t";


			// For loop to display the list of possible prices
			for (int j = 0; j < SIZE; j++)
			{

				cout << priceIndex[j] << "\t";

			}


			cout << endl << endl;

			break;


			// Case 2 will allow the user to select a length and display the maximum price value
		case 2:

			system("CLS");


			// While loop to make the user input a number between 0 and 10
			while (length < 0 || length > 10)
			{

				// Prompts the user to select a length
				cout << "Please select a length (1-10): ";
				cin >> length;

			}


			// Makes sure the user inputs a valid option
			while (cin.fail())
			{

				cin.clear();
				cin.ignore(numeric_limits<streamsize>::max(), '\n');
				cout << endl << "Please select a length (1-10): " << endl << endl;
				cin >> length;

			}


			// Sets a variable equal to the return value of the function rodCutterTopDown
			maximumPrice = rodCutterTopDown(priceIndex, length);

			// Displays the length entered as well as the maximum price value from the given length
			cout << "The length you entered is: " << length << endl;
			cout << "The maximum price given the length of " << length <<
				" is " << maximumPrice;

			cout << endl << endl;

			break;


			// Case 3 will return to the main menu
		case 3:

			mainMenu();

			// Default case will collect the invalid options input and let the user try again
		default:

			system("CLS");
			cout << "Invalid selection. Try again" << endl;

		}


	} while (choice != 3);

}



// Menu function for the activity-selection problem
void activitySelectionMenu()
{

	// Function variables
	int choice = 3;
	int start[] = { 1, 3, 0, 5, 3, 5, 6, 8, 8, 2, 12 };
	int finish[] = { 4, 5, 6, 7, 9, 9, 10, 11, 12, 14, 16 };
	int activities[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11 };


	// Displays a welcome message to the console
	cout << "Welcome to Zac's Activity Selector!" << endl;
	cout << "Please enter a number (1-3)." << endl << endl;


	// Do-while loop for the activity selector menu
	do
	{

		// Displays a menu to the console
		cout << "1. View Start and Finish Times" << endl;
		cout << "2. Run Activity Selector" << endl;
		cout << "3. Exit Activity Selector" << endl << endl;

		cin >> choice;


		// Makes sure the user inputs a valid option
		while (cin.fail())
		{

			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout << endl << "Please enter a number (1-3)." << endl << endl;
			cin >> choice;

		}


		// Switch statement to go between options
		switch (choice)
		{

			// Case 1 will alow the user to view the length and prices
		case 1:

			system("CLS");

			cout << "Length:\t";


			// For loop to display the list of possible lengths
			for (int i = 1; i < CAPACITY + 1; i++)
			{

				cout << activities[i] << "\t";

			}


			cout << endl << "----------------------------------------------------------------------------------------------" << endl;


			cout << "Start:\t";


			// For loop to display the list of possible prices
			for (int j = 0; j < CAPACITY; j++)
			{

				cout << start[j] << "\t";

			}


			cout << endl << "Finish:\t";


			// For loop to display the list of possible prices
			for (int k = 0; k < CAPACITY; k++)
			{

				cout << finish[k] << "\t";

			}


			cout << endl << endl;

			break;


			// Case 2 will allow the user to select a length and display the maximum price value
		case 2:

			system("CLS");

			activitySelector(start, finish);

			cout << endl << endl;

			break;


			// Case 3 will return to hte main menu
		case 3:

			mainMenu();

			// Default case will collect the invalid options input and let the user try again
		default:

			system("CLS");
			cout << "Invalid selection. Try again" << endl;

		}


	} while (choice != 3);

}



// TopDown Rod Cutter function used to determine the maximum profit from the given length
int rodCutterTopDown(int insertPriceIndex[], int insertLength)
{

	// If the length is 0, return the value 0
	if (insertLength == 0)
	{

		return 0;

	}


	// maximumValue = -∞
	int maximumValue = INT_MIN;


	// For loop used to find the maximum profit value
	for (int i = 0; i < insertLength; i++)
	{

		maximumValue = max(maximumValue, insertPriceIndex[i]
			+ rodCutterTopDown(insertPriceIndex, insertLength - i - 1));

	}

	// Returns the maximum profit value
	return maximumValue;

}



// Activity Selector function to select a maximum-size set of mutually compatible activities
void activitySelector(int insertStart[], int insertFinish[])
{

	cout << "Activities Selected are as Follows: " << endl;

	int index = 1;
	cout << index << endl;

	for (int m = 2; m <= CAPACITY; m++)
	{

		if (insertStart[m] >= insertFinish[index])
		{

			// Displays the activity selected (+1 because our array starts at index 0)
			cout << m + 1 << endl;
			index = m;

		}

	}

}