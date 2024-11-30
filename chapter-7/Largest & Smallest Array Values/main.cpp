/*****
 * Author: Glowstudent
 * Program: Largest/Smallest Array Values
 *****/

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

void getNumbers(int count, int arr[])
{
    for (int i = 0; i < count; i++)
    {
        int input;

        cout << "Enter a number (" << (count - (i + 1)) << " left): ";
        cin >> input;

        while (cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << endl;
            cout << "Invalid Input. Please try again." << endl;
            cout << "Enter a number (" << (count - (i + 1)) << " left): ";
            cin >> input;
        }

        input += 0; // Weird bug fix
        arr[i] = input;
    }
}

int main()
{
    int values[10];
    int smallest, largest, count = 10;

    cout << "This program will find the largest and smallest numbers in a set of 10 numbers." << endl;

    getNumbers(count, values);

    for (int i = 0; i < count; i++)
    {
        if (i == 0)
        {
            smallest = values[i];
            largest = values[i];
        }
        else
        {
            if (values[i] < smallest)
                smallest = values[i];

            if (values[i] > largest)
                largest = values[i];
        }
    }

    cout << endl;
    cout << "The largest number entered is: " << largest << endl;
    cout << "The smallest number entered is: " << smallest << endl;

    return 0;
}