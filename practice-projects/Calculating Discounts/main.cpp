/*****
* Author: Glowstudent
* Calculating Discounts
*****/

#include <iostream>

using namespace std;

int main()
{
	double regularPrice = 59.95,
	       discount,
	       salePrice;

	discount = regularPrice * 0.2;
	salePrice = regularPrice - discount;

	cout << "Regular Price: $" << regularPrice << endl;
	cout << "Discount Amount: $" << discount << endl;
	cout << "Sales Price: $" << salePrice << endl;

	return 0;
}
