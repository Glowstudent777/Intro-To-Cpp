/*****
 * Author: Glowstudent
 * Currency Converter
 *****/

#include <iostream>
#include <iomanip>
#include <locale>
#include <string>

using namespace std;

int main()
{
    const float YEN_PER_DOLLAR = 98.93, EUROS_PER_DOLLAR = 0.74;
    float dollars, yen, euros;

    cout << "Enter the amount of dollars you have: ";
    cin >> dollars;

    yen = dollars * YEN_PER_DOLLAR;
    euros = dollars * EUROS_PER_DOLLAR;

    cout.imbue(locale(""));
    cout << "Dollars: $" << setprecision(2) << fixed << dollars << endl;
    cout << "Yen: ¥" << setprecision(2) << fixed << yen << endl;
    cout << "Euros: €" << setprecision(2) << fixed << euros << endl;

    return 0;
}