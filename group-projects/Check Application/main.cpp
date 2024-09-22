/*****
* Author: Glowstudent
* Check Application
* Note: Run with C++ 20
* Spacing might be off depending on if your compiler shows commas with cout.imbue(locale("")); Onlines GDB does but my local compiler does not.
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
	int spacing = 12, letters = 6, endSpacing = 2;

	cout << "Enter the employees name: ";
	getline(cin, employee);
	cout << "Enter " << employee << "'s pay: ";
	cin >> pay;

	// Spacing
	cout << "\n";

	// 7 is the length of the string ".000000"
	int payCommas = (to_string(pay).length() - 7) > 3 ? (to_string(pay).length() - 7) / 3 : 0;

	// Fun math to figure out the extra spacing needed to make the check look nice
	// +9 is the length of the string " PayCheck" including the space
	// | $300.00 | is + 1 because -4 for the hidden 0s but +5 for the text surrounding 300: | $300 |
	int payEndExtra = (employee.length() + 9) < (to_string(pay).length() + 1 + payCommas) ? endSpacing : (endSpacing + (employee.length() + 9 - (to_string(pay).length() + 1 + payCommas)));
	int employeeEndExtra = (employee.length() + 9) > (to_string(pay).length() + 1 + payCommas) ? endSpacing : (endSpacing + (to_string(pay).length() + 1 + payCommas - (employee.length() + 9)));
	int midEndExtra = (payEndExtra > employeeEndExtra) ? (employee.length() + 9 + employeeEndExtra) : (payEndExtra < employeeEndExtra) ? (to_string(pay).length() + 1 + payEndExtra) : (payEndExtra == employeeEndExtra) ? (employee.length() + 9 + employeeEndExtra) : endSpacing;
	int topNbottom = (spacing - letters + topNbottom + payCommas + beforeName.length() + endSpacing + ((payEndExtra > employeeEndExtra) ? (employee.length() + 9 + employeeEndExtra) : (payEndExtra < employeeEndExtra) ? (to_string(pay).length() + 1 + payEndExtra) : (payEndExtra == employeeEndExtra) ? (employee.length() + 9 + employeeEndExtra) : endSpacing));

	cout.imbue(locale(""));
	cout << string(topNbottom, '>') << endl;
	cout << "> " << setprecision(2) << fixed << setw(spacing - letters + beforeName.length() + 3) << "| $" << pay << " |" << setw(payEndExtra) << ">" << endl;
	cout << "> " << setw(spacing - letters + beforeName.length() + midEndExtra + payCommas) << ">" << endl;
	cout << "> " << beforeName << setw(spacing + employee.length() - letters) << employee << " PayCheck" << setw(employeeEndExtra) << ">" << endl;
	cout << string(topNbottom, '>') << endl;

	return 0;
}