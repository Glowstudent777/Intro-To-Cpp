/*****
 * Author: Glowstudent
 * Days in a Month
 *****/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    int month, year;

    cout << "This program tells you how many days are in a month.\n";

    cout << "Enter a month (1, 2, etc. ): ";
    cin >> month;

    while (cin.fail() || month < 1 || month > 12)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Enter a month (1, 2, etc. ): ";
        cin >> month;
    }

    cout << "Enter a year: ";
    cin >> year;

    while (cin.fail() || year < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Enter a year: ";
        cin >> year;
    }

    if (month == 2)
    {
        if (year % 4 == 0 && (year % 100 != 0 || year % 400 == 0))
        {
            cout << "29 days" << endl;
        }
        else
        {
            cout << "28 days" << endl;
        }
    }
    else if (month == 4 || month == 6 || month == 9 || month == 11)
    {
        cout << "30 days" << endl;
    }
    else
    {
        cout << "31 days" << endl;
    }

    return 0;
}