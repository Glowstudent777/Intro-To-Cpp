/*****
 * Author: Glowstudent
 * Program: Largest/Smallest Array Values
 *****/

#include <iostream>
#include <vector>
#include <iomanip>
#include <limits>

using namespace std;

void getNumbers(int count, vector<int> &vec)
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

        input += 0;
        vec.push_back(input);
    }
}

int main()
{
    vector<int> values;
    int smallest, largest, count = 10;

    getNumbers(count, values);

    for (int i = 1; i < count; i++)
    {
        if (i == 1)
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