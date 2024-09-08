/*****
* Author: Glowstudent
* Restaurant Bill
*****/

#include <iostream>

using namespace std;

int main()
{
	float taxPercent = 0.0675,
	      tipPercent = 0.20,
	      mealCost = 88.67,
	      tip,
	      tax,
	      total;


	tax = mealCost * taxPercent;
	tip = (mealCost + tax) * tipPercent;
	total = mealCost + tax + tip;

	cout << "The tax on your bill is: $" << tax << endl;
	cout << "Your tip is: $" << tip << endl;

	cout << "\nYour total bill is: $" << total << endl;

	return 0;
}
