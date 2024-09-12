/*****
* Author: Glowstudent
* Input/Output Manipulation
*****/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int intOne = 1, intTwo = 2, intThree = 3, intFour = 4, intFive = 5;
	string headingOne, headingTwo, headingThree, headingFour, headingFive;

	headingOne = "Heading One", headingTwo = "Heading Two", headingThree = "Heading Three", headingFour = "Heading Four", headingFive = "Heading Five";

	cout << "Formatting output helps the user see what's going on." << endl;
	cout << "In\n\nThis one is garbage:" << endl;

	// No formatting
	cout << headingOne << headingTwo << headingThree << headingFour << headingFive << endl;
	cout << intOne << intTwo << intThree << intFour << intFive << endl;

	cout << "\n\n";

	// Tab formatting
	cout << headingOne << "\t" << headingTwo << "\t" << headingThree << "\t" << headingFour << "\t" << headingFive << endl;
	cout << intOne << "\t" << intTwo << "\t" << intThree << "\t" << intFour << "\t" << intFive << endl;

	cout << "\n\n";

	// Using setw (Set Width) formatting
	cout << headingOne << setw(15) << headingTwo << setw(15) << headingThree << setw(15) << headingFour << setw(15) << headingFive << endl;
	cout << intOne << setw(15) << intTwo << setw(15) << intThree << setw(15) << intFour << setw(15) << intFive << endl;

	cout << "\n\n";

	// Using setw (Set Width) & right aligned formatting
	cout << headingOne << setw(15) << headingTwo << setw(15) << headingThree << setw(15) << headingFour << setw(15) << headingFive << endl;
	cout << right << intOne << right << setw(15) << intTwo << right << setw(15) << intThree << right << setw(15) << intFour << right << setw(15) << intFive << endl;

	cout << "\n\n";

	// Set Precision for numbers, 4 with a fixed precision of 2 becomes 4.00
	cout << "intFour / intFive: " << setprecision(2) << fixed << (static_cast<double>(intFour) / static_cast<double>(intFive)) << endl;
}