/*****
* Author: Glowstudent
* Miles Per Gallon
*****/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	float gallonsOfGas, milesPerTank, milesPerGallon;
	
	cout << "Enter gallons of gas your car holds: ";
	cin >> gallonsOfGas;
	
	cout << "Enter the amount of miles your car can drive on a full tank of gas: ";
	cin >> milesPerTank;
	
	milesPerGallon = milesPerTank / gallonsOfGas;
	
	cout << "Estimated miles-per-gallon: " << setprecision(2) << fixed << milesPerGallon << endl;
	
	return 0;
}
