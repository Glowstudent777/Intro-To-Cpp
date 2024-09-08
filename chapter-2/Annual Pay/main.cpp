/*****
* Author: Glowstudent
* Annual Pay
*****/

#include <iostream>

using namespace std;

int main()
{
	float payAmount = 2200.0,
	      annualPay;
	int payPeriods = 26;

	annualPay = payAmount * payPeriods;

	cout << "Your annual pay is: $" << annualPay << endl;

	return 0;
}
