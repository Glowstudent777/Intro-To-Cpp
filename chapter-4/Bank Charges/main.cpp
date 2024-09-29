/*****
 * Author: Glowstudent
 * Bank Charges
 *****/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    const double MIN_BALANCE = 400.0;
    const double MIN_BALANCE_FEE = 15.0;
    const double MONTHLY_FEE = 10.0;

    int checks;
    double balance, total;

    cout << "Enter the beginning balance: ";
    cin >> balance;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Enter the beginning balance: ";
        cin >> balance;
    }

    cout << "Enter the number of checks written: ";
    cin >> checks;

    while (cin.fail() || checks < 0)
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Enter the number of checks written: ";
        cin >> checks;
    }

    if (balance < 0)
    {
        cout << string(30, '*') << endl;
        cout << "*      URGENT MESSAGE!       *" << endl;
        cout << "* Your account is overdrawn. *" << endl;
        cout << string(30, '*') << endl;
    }

    if (balance < MIN_BALANCE)
    {
        total = MONTHLY_FEE + MIN_BALANCE_FEE;
    }
    else
    {
        total = MONTHLY_FEE;
    }

    if (checks < 20)
    {
        total += checks * 0.1;
    }
    else if (checks >= 20 && checks <= 39)
    {
        total += checks * 0.08;
    }
    else if (checks >= 40 && checks <= 59)
    {
        total += checks * 0.06;
    }
    else if (checks >= 60)
    {
        total += checks * 0.04;
    }

    cout << fixed << setprecision(2);
    cout << "The bank service fees for the month are $" << total << endl;

    return 0;
}