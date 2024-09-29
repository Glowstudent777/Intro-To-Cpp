/*****
 * Author: Glowstudent
 * Roman Numeral Converter
 *****/

#include <iostream>
#include <limits>

using namespace std;

int main()
{

    int number;

    cout << "Enter a number between 1 and 10: ";
    cin >> number;

    while (number < 1 || number > 10 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Enter a number between 1 and 10: ";
        cin >> number;
    }

    switch (number)
    {
    case 1:
        cout << "The Roman numeral is I.\n";
        break;
    case 2:
        cout << "The Roman numeral is II.\n";
        break;
    case 3:
        cout << "The Roman numeral is III.\n";
        break;
    case 4:
        cout << "The Roman numeral is IV.\n";
        break;
    case 5:
        cout << "The Roman numeral is V.\n";
        break;
    case 6:
        cout << "The Roman numeral is VI.\n";
        break;
    case 7:
        cout << "The Roman numeral is VII.\n";
        break;
    case 8:
        cout << "The Roman numeral is VIII.\n";
        break;
    case 9:
        cout << "The Roman numeral is IX.\n";
        break;
    case 10:
        cout << "The Roman numeral is X.\n";
        break;
    }

    return 0;
}