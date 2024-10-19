/*****
 * Author: Glowstudent
 * Program: Membership Fees Increase
 *****/

#include <iostream>
#include <iomanip>

using namespace std;

void clearScreen()
{
    // Clear the screen
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#elif defined(__linux__)
    system("clear");
#elif defined(__APPLE__)
    system("clear");
#endif
}

int main()
{
    const double INCREASE_RATE = 0.04;
    const int years = 6;
    double membershipFee = 2500.0;

    clearScreen();

    cout << "Membership Fees Increase\n\n";

    cout << setprecision(2) << fixed;
    cout << "The current membership fee is $" << membershipFee << ".\n";
    cout << "The membership fee will increase by " << INCREASE_RATE * 100 << "% each year.\n\n";

    cout << "\nYear\t\tMembership Fee\n";
    cout << "------------------------------\n";

    for (int i = 1; i <= years; i++)
    {
        membershipFee += membershipFee * INCREASE_RATE;

        cout << i << "\t\t$" << membershipFee << endl;
    }

    return 0;
}