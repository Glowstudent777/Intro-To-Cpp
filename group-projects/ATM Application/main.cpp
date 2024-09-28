/*****
 * Author: Glowstudent
 * ATM Application
 * Note: Run with C++ 20
 * Spacing might be off depending on your compiler. OnlinesGDB can freak out sometimes with string fills but my local compiler does not.
 *****/

#include <iostream>
#include <iomanip>
#include <string>

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

void printScreen(string title, float userBal, float atmBal, string message)
{
    const int screenWidth = title.length() % 2 == 0 ? 40 : 41;

    cout << string(screenWidth, '*') << endl;
    cout << "*" << setw((screenWidth - title.length()) / 2 - 1) << "" << title << setw((screenWidth - title.length()) / 2) << "*" << endl;
    cout << string(screenWidth, '*') << endl;

    // User Balance
    cout << "*" << setprecision(2) << fixed << setw((((screenWidth - 15 - (to_string(userBal).length() - 4)) / 2) - (screenWidth % 2 == 0 ? 0 : 1))) << "" << "User Balance: $" << userBal << setw(((screenWidth - 15 - (to_string(userBal).length() - 4)) / 2) + ((to_string(userBal).length() - 4) % 2 == 0 ? 0 : 1)) << "*" << endl;

    // Successfull Transaction
    cout << "*" << setw(screenWidth - 2) << "" << "*" << endl;
    if (message.length() > 0)
        cout << "*" << setw(((screenWidth - message.length()) / 2) - (screenWidth % 2 == 0 ? 0 : 1)) << "" << message << setw(((screenWidth - message.length()) / 2) + (message.length() % 2 == 0 ? 1 : 0)) << "*" << endl;
    else
        cout << "*" << setw(screenWidth - 2) << "" << "*" << endl;
    cout << "*" << setw(screenWidth - 2) << "" << "*" << endl;

    // ATM Withdrawl Options
    // Values don't change so spacing is hardcoded
    cout << "*" << setw(24) << "Choose One" << setw(16) << "*" << endl;
    cout << "*" << setw(29) << "| $40          | $80" << setw(11) << "*" << endl;
    cout << "*" << setw(30) << "| $200         | $400" << setw(10) << "*" << endl;

    // Spacing
    cout << "*" << setw(screenWidth - 2) << "" << "*" << endl;
    cout << "*" << setw(screenWidth - 2) << "" << "*" << endl;
    cout << "*" << setw(screenWidth - 2) << "" << "*" << endl;

    // ATM Balance
    cout << "*" << setprecision(2) << fixed << setw(((screenWidth - 21 - (to_string(atmBal).length() - 4)) / 2) - (screenWidth % 2 == 0 ? 0 : 1)) << "" << "Amount Left in ATM: $" << atmBal << setw(((screenWidth - 21 - (to_string(atmBal).length() - 4)) / 2) + ((to_string(atmBal).length() - 4) % 2 == 0 ? 0 : 1)) << "*" << endl;
    cout << string(screenWidth, '*') << endl;
}

int main()
{
    const string title = "ATM Application";
    float userBalance = 1000;
    float atmBalance = 500;

    string message;
    string userInput;

    // ATM Has $500.00
    // User has $1,000.00
    // ATM can only dispense $40, $80, $200, and $400 amounts
    // After withdrawl, the console will show the amount left in the account
    // And will show how much the ATM has left to dispense

    // Program will look like this:
    // *****************************************
    // *            ATM Application            *
    // *****************************************
    // *        User Balance: $1000.00         *
    // *                                       *
    // *          Choose One                   *
    // *      | $40          | $80             *
    // *      | $200         | $400            *
    // *                                       *
    // *                                       *
    // *                                       *
    // *                                       *
    // *    Amount Left in ATM: $500.00        *
    // *****************************************
    // Choose An Option:

    // Loop for the ATM to refresh after each transaction
    while (true)
    {
        clearScreen();
        printScreen(title, userBalance, atmBalance, message);
        cout << "Choose Amount to Withdrawl or type EXIT to quit: ";
        getline(cin, userInput);

        while (userInput != "40" && userInput != "80" && userInput != "200" && userInput != "400")
        {
            if (userInput == "EXIT")
            {
                cout << "Exiting ATM Application..." << endl;
                exit(0);
            }
            else
            {
                message = "";
                clearScreen();
                printScreen(title, userBalance, atmBalance, message);
                cout << "Invalid Input. Please enter a valid amount or EXIT." << endl;
                cout << "Choose Amount to Withdraw or type EXIT to quit: ";
                getline(cin, userInput);
            }
        }

        float amount = stof(userInput);

        while (userBalance < amount || atmBalance < amount)
        {
            message = "";
            clearScreen();
            printScreen(title, userBalance, atmBalance, message);
            cout << "Insufficient Funds. Please enter a valid amount or EXIT." << endl;
            cout << "Choose Amount to Withdraw or type EXIT to quit: ";
            getline(cin, userInput);

            while (userInput != "40" && userInput != "80" && userInput != "200" && userInput != "400")
            {
                if (userInput == "EXIT")
                {
                    cout << "Exiting ATM Application..." << endl;
                    exit(0);
                }
                else
                {
                    message = "";
                    clearScreen();
                    printScreen(title, userBalance, atmBalance, message);
                    cout << "Invalid Input. Please enter a valid amount or EXIT." << endl;
                    cout << "Choose Amount to Withdraw or type EXIT to quit: ";
                    getline(cin, userInput);
                }
            }
            amount = stof(userInput);
        }

        userBalance -= amount;
        atmBalance -= amount;
        message = "Transaction successful!";
    }

    return 0;
}