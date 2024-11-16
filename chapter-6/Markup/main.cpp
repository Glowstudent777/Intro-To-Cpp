/*****
 * Author: Glowstudent
 * Program: Markup
 *****/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

double calculateRetail(double wholesaleCost, int markupPercentage)
{
    return wholesaleCost + (wholesaleCost * markupPercentage / 100);
}

int main()
{
    double wholesaleCost, retailPrice;
    int markupPercentage;

    cout << "Enter the wholesale cost of the item: $";
    cin >> wholesaleCost;

    while (wholesaleCost < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << "Wholesale cost must be a positive value." << endl;
        cout << "Enter the wholesale cost of the item: $";
        cin >> wholesaleCost;
    }

    cout << endl;
    cout << "Enter the markup percentage (1 = 1%): ";
    cin >> markupPercentage;

    while (markupPercentage < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << "Markup percentage must be a positive value." << endl;
        cout << "Enter the markup percentage (1 = 1%): ";
        cin >> markupPercentage;
    }

    retailPrice = calculateRetail(wholesaleCost, markupPercentage);

    cout << endl;
    cout << setprecision(2) << fixed;
    cout << "The retail price for the item is: $" << retailPrice << endl;

    return 0;
}