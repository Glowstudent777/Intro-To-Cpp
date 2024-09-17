/*****
* Author: Glowstudent
* Check Application
*****/

#include <iostream>
#include <iomanip>
#include <locale>
#include <string>

using namespace std;

int main()
{
	/*****
	* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	* >                               | $1,000,000 |  >
	* >                                               >
	* > ___Pay to the Order of___     Johnny PayCheck >
	* >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
	*****/

	string employee, beforeName = "___Pay to the Order of___";
	double pay;
	int spacing = 12;

	cout << "Enter the employees name: ";
	getline(cin, employee);
	cout << "Enter " << employee << "'s pay: ";
	cin >> pay;

	// Spacing
	cout << "\n";

	setprecision(2);
	fixed;
	cout.imbue(locale(""));

	cout << ">>>>>>>" << "\n"
	     << "> " << right << setw(beforeName.length() + spacing) << "| $" << pay << " |" << setw(5) << ">" << "\n"
	     << "> " << "\n"
	     << "> " << beforeName << right << setw(spacing) << employee << " PayCheck" << setw(5) << ">" << "\n"
	     << ">>>>>>>" << "\n";

	return 0;
}