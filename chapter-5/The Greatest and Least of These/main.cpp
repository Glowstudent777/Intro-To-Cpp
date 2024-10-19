/*****
 * Author: Glowstudent
 * Program: The Greatest and Least of These
 *****/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    int smallest, largest, input;
    bool first = true;

    do
    {
        if (first)
            cout << "Enter an integer (-99 to end): ";
        else
            cout << "Enter another integer (-99 to end): ";

        cin >> input;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "Invalid input. Please Enter an integer (-99 to end): ";
            cin >> input;
        }

        switch (input)
        {
        case -99:
            break;
        default:
            if (input < smallest || first)
                smallest = input;
            if (input > largest || first)
                largest = input;

            first = false;
            break;
        }

    } while (input != -99);

    cout << endl;

    if (first)
    {
        smallest = 0;
        largest = 0;
    }
    
    cout << "Smallest: " << smallest << endl;
    cout << "Largest: " << largest << endl;

    return 0;
}