/*****
 * Author: Glowstudent
 * Program: National Commerce Bank
 *****/

#include <iostream>
#include <vector>

using namespace std;

bool testPIN(const vector<int>, const vector<int>, int);

int main()
{
    const int NUM_DIGITS = 7;
    vector<int> pin1 = {2, 4, 1, 8, 7, 9, 0};
    vector<int> pin2 = {2, 4, 6, 8, 7, 9, 0};
    vector<int> pin3 = {1, 2, 3, 4, 5, 6, 7};

    if (testPIN(pin1, pin2, NUM_DIGITS))
        cout << "Error: pin1 and pin2 report to be the same.\n";
    else
        cout << "Success: pin1 and pin2 are different.\n";

    if (testPIN(pin1, pin3, NUM_DIGITS))
        cout << "Error: pin1 and pin3 report to be the same.\n";
    else
        cout << "Success: pin1 and pin3 are different.\n";

    if (testPIN(pin1, pin1, NUM_DIGITS))
        cout << "Success: pin1 and pin1 report to be the same.\n";
    else
        cout << "Error: pin1 and pin1 are different.\n";

    return 0;
}

bool testPIN(const vector<int> custPIN, const vector<int> databasePIN, int size)
{
    for (int index = 0; index < size; index++)
    {
        if (custPIN[index] != databasePIN[index])
            return false;
    }
    return true;
}