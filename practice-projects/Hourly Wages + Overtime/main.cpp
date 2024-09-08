/*****
* Author: Glowstudent
* Hourly Wages + Overtime
*****/

#include <iostream>

using namespace std;

int main()
{
	double regularWages,
	       basePayRate = 18.25,
	       regularHours = 40.0,
	       overtimeWages,
	       overtimePayRate = 27.78,
	       overtimeHours = 10,
	       totalWages;

	regularWages = basePayRate * regularHours;
	overtimeWages = overtimePayRate * overtimeHours;
	totalWages = regularWages + overtimeWages;

	cout << "Regular: $" << regularWages << " for " << regularHours << "hrs" << endl;
	cout << "Overtime: $" << overtimeWages << " for " << overtimeHours << "hrs" << endl;
	cout << "\nWages for this week are $" << totalWages << endl;

	return 0;
};
