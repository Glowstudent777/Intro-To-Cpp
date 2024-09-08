/*****
* Author: Glowstudent
* Calculating Percentages
*****/

#include <iostream>

using namespace std;

int main()
{
	double monthlyPay = 6000.0, contribution;

	contribution = monthlyPay * 0.05;
	cout << "5 percent is $" << contribution << " per month.\n";

	contribution = monthlyPay * 0.07;
	cout << "7 percent is $" << contribution << " per month.\n";

	contribution = monthlyPay * 0.10;
	cout << "10 percent is $" << contribution << " per month.\n";

	return 0;
}
