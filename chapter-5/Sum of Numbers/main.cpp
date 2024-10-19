/*****
 * Author: Glowstudent
 * Program: Sum of Numbers
 *****/

#include <iostream>
#include <limits>

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
    int input, sum = 0;

    clearScreen();

    cout << "Enter a positive integer value: ";
    cin >> input;

    while (input < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Invalid input. Please re-enter: ";
        cin >> input;
    }

    switch (input)
    {
    case 0:
        cout << "The result is 0." << endl;
        break;
    case 1:
        cout << "The result is 1, the loneliest number." << endl;
        break;
    default:
        for (int i = 1; i <= input; i++)
        {
            sum += i;
        }

        cout << "The sum of all numbers up to " << input << " is " << sum << endl;
        break;
    }

    return 0;
}