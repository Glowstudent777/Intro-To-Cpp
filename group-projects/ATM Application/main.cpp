/*****
 * Author: Glowstudent
 * ATM Application
 *****/

#include <iostream>
#include <iomanip>
#include <string>


using namespace std;

int main()
{
    // Consistent spacing
    const string title = "ATM Application";
    const int screenWidth = title.length() % 2 == 0 ? 40 : 41;
    const int screenHeight = 20;

    float userBalance = 1000;
    float atmBalance = 500;

    const int sideExtraL = ((screenWidth % 2 == 0 ? screenWidth/2 : (screenWidth + 1)/2) + 11 - (to_string(userBalance).length()));

    // ATM Has $500.00
    // User has $1,000.00
    // ATM can only dispense $40, $80, $200, and $400 amounts
    // After withdrawl, the console will show the amount left in the account
    // And will show how much the ATM has left to dispense

    //*************************************
    //*          ATM Application          *
    //*                                   *
    //*       User Balance: $1,000.00     *
    //*                                   *
    //*       How much to withdraw?       *
    //*                                   *
    //*   | $40                  | $80    *
    //*                                   *
    //*   | $200                 | $400   *
    //*                                   *
    //*                                   *
    //*  EXIT                             *
    //*                                   *
    //*    Amount Left in ATM: $500.00    *
    //*************************************

    // Clear the screen
    #if defined(_WIN32) || defined(_WIN64)
        system("cls");
    #elif defined(__linux__)
        system("clear");
    #elif defined(__APPLE__)
        system("clear");
    #endif

    cout << sideExtraL << endl;
    cout << (screenWidth % 2 == 0 ? screenWidth/2 : (screenWidth + 1)/2) << endl;
    // int balCommas = (to_string(userBalance).length() - 7) > 3 ? (to_string(userBalance).length() - 7) / 3 : 0;

    
    cin >> userBalance;

    // Title
    cout << string(screenWidth, '*') << endl;
    cout << "*" << setw((screenWidth - title.length()) / 2 - 1) << "" << title << setw((screenWidth - title.length()) / 2) << "*" << endl;
    cout << string(screenWidth, '*') << endl;

    // User Balance
    cout << "*" << setprecision(2) << fixed << setw(sideExtraL) << "User Balance: $" << userBalance << setw((screenWidth / 2) - to_string(userBalance).length()) << "*" << endl;
    
    // Spacing
    cout << "*" << "\n";
    
    cout << "*" << string((screenWidth - 20) / 2, ' ') << "Choose One" << endl;
    cout << "*" << string((screenWidth - 20) / 2, ' ') << "| $40" << string((screenWidth - 20) / 2, ' ') << "| $80" << endl;
    cout << "*" << string((screenWidth - 20) / 2, ' ') << "| $200" << string((screenWidth - 20) / 2, ' ') << "| $400" << endl;

    return 0;
}