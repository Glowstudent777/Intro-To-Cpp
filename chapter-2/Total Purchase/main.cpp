/*****
* Author: Glowstudent
* Total Purchase
*****/

#include <iostream>

using namespace std;

int main()
{
	float item1 = 15.95,
	      item2 = 24.95,
	      item3 = 6.95,
	      item4 = 12.95,
	      item5 = 3.95,
	      salesTax = 0.07,
	      tax,
	      subtotal,
	      total;

	subtotal = (item1 + item2 + item3 + item4 + item5);
	tax = subtotal * salesTax;
	total = subtotal + tax;

	cout << "Item 1: $" << item1
	     << "\nItem 2: $" << item2
	     << "\nItem 3: $" << item3
	     << "\nItem 4: $" << item4
	     << "\nItem 5: $" << item5
	     << "\n---------------" << endl;
	cout << "Your subtotal is: $" << subtotal << endl;
	cout << "Your total after tax is: $" << total << endl;

	return 0;
}
