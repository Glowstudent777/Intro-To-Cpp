/*****
* Author: Glowstudent
* Class Demo
*****/

#include <iostream>
#include <limits>
#include <string>

using namespace std;

int main()
{
	int demoOne = 5, demoTwo = 6;
	double demoThree;
	string nameEntryCin, nameEntryGet;

	// Divide integers demoOne by divideTwo
	// Cast double to get fraction decimals
	demoThree = static_cast<double>(demoOne) / static_cast<double>(demoTwo);
	cout << "The quotient of demoOne / demoTwo is: " << demoThree << endl;

	// cin cannot deal with spaces, tabs, literals, etc.
	// "first last" returns "Thank you, first"
	cout << "Enter your name: ";
	cin >> nameEntryCin;
	cout << "Thank you, " << nameEntryCin << endl;

	// Just some spacing
	cin.ignore(numeric_limits<streamsize>::max(), '\n');
	cout << "\n" << endl;

	// getline can deal with strings unlike cin.
	cout << "Enter your name: ";
	getline(cin, nameEntryGet);
	cout << "Thank you, " << nameEntryGet << endl;

	return 0;
}