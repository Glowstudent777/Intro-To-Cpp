/*****
 * Author: Glowstudent
 * Program: Sum of Numbers
 *****/

#include <iostream>
#include <limits>

using namespace std;

int main()
{
    int input, sum = 0;

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