/*****
* Author: Glowstudent
* Miles Per Gallon
*****/

#include <iostream>

using namespace std;

int main()
{
	int maxGallons = 15, maxMiles = 375;
	float milesPerGallon;

	milesPerGallon = (float) maxMiles / (float) maxGallons;

	cout << "Miles per Gallon: " <<  milesPerGallon << endl;

	return 0;
}
