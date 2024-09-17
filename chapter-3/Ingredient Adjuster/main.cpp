/*****
 * Author: Glowstudent
 * Ingredient Adjuster
 *****/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    // Measurements are in cups.
    float sugar = 1.5, butter = 1, flour = 2.75, cookies = 48, sugarTotal, butterTotal, flourTotal;
    int cookiesToMake;

    // Consistent spacing
    const int indent = 15;

    cout << "How many cookies do you want to make? ";
    cin >> cookiesToMake;

    sugarTotal = (sugar / cookies) * cookiesToMake;
    butterTotal = (butter / cookies) * cookiesToMake;
    flourTotal = (flour / cookies) * cookiesToMake;

    // Spacing :)
    cout << "\n";

    cout << "To make " << cookiesToMake << " cookies, you will need the following ingredients:" << endl;
    cout << "\n";
    cout << "Sugar" << setw(indent+1) << "Butter" << setw(indent-1) << "Flour" << endl;
    cout << "----------" << setw(indent) << "----------" << setw(indent) << "----------" << endl;
    int sugarExtra = to_string((int)sugarTotal).length(), butterExtra = to_string((int)butterTotal).length();
    cout << setprecision(2) << fixed << sugarTotal << " cups" << setw(indent - 4 - sugarExtra) << butterTotal << " cups" << setw(indent - 4 - butterExtra) << flourTotal << " cups" << endl;

    return 0;
}
