/*****
 * Author: Glowstudent
 * Program: Pennies for Pay
 *****/

#include <iostream>
#include <iomanip>
#include <limits>
#include <locale>

using namespace std;

int main()
{
    int days;
    double nextDayPay = 0.01, totalPay = 0.00;

    cout << "Enter the number of days you worked: ";
    cin >> days;

    while (days <= 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "The number of days must be at least 1." << endl;
        cout << "Enter the number of days you worked: ";
        cin >> days;
    }

    cout << endl;

    cout << "Day\t\tPay" << endl;
    cout << "----------------------" << endl;

    cout.imbue(locale(""));
    for (int i = 1; i <= days; i++)
    {
        cout << i << "\t\t$" << fixed << setprecision(2) << nextDayPay << endl;
        totalPay += nextDayPay;
        nextDayPay *= 2;
    }

    cout << endl;
    cout << "Total pay: $" << fixed << setprecision(2) << totalPay << endl;

    return 0;
}