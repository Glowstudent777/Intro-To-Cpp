/*****
* Author: Glowstudent
* Cin Multi Input
*****/

#include <iostream>

using namespace std;

int main()
{
    int whole;
    double fractional;
    char letter;

    cout << "Enter an integer, a double, and a character separated by spaces: ";
    cin >> whole >> fractional >> letter;

    cout << "You entered: " << "Whole: " << whole << "\nFractional: " << fractional << "\nLetter: " << letter << endl;

    return 0;
}