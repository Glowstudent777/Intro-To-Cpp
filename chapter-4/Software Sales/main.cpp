/*****
 * Author: Glowstudent
 * Software Sales
 *****/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    const double PACKAGE_PRICE = 99.0;

    int quantity;
    double discount, total;

    cout << "Enter the number of units sold: ";
    cin >> quantity;

    while (cin.fail() || quantity < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Enter the number of units sold: ";
        cin >> quantity;
    }

    if (quantity >= 10 && quantity <= 19)
    {
        discount = 0.2;
    }
    else if (quantity >= 20 && quantity <= 49)
    {
        discount = 0.3;
    }
    else if (quantity >= 50 && quantity <= 99)
    {
        discount = 0.4;
    }
    else if (quantity >= 100)
    {
        discount = 0.5;
    }
    else
    {
        discount = 0.0;
    }

    total = quantity * PACKAGE_PRICE * (1 - discount);

    cout << fixed << setprecision(2);
    cout << "The total cost of the purchase is $" << total << endl;

    return 0;
}