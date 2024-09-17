/*****
 * Author: Glowstudent
 * Decimal of Fraction
 *****/

#include <iostream>

using namespace std;

int main()
{
    double numerator, denominator, decimal;

    cout << "This program converts a fraction to a decimal.\n";

    cout << "Enter the numerator: ";
    cin >> numerator;

    cout << "Enter the denominator: ";
    cin >> denominator;

    decimal = numerator / denominator;

    cout << "The decimal of the fraction " << numerator << "/" << denominator << " is: " << decimal << endl;

    return 0;
}