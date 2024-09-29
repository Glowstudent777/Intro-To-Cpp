/*****
 * Author: Glowstudent
 * Color Mixer
 *****/

#include <iostream>
#include <string>
#include <limits>

using namespace std;

int main()
{
    string color1, color2;

    cout << "This program mixes two primary colors.\n";

    cout << "Enter a primary color (red, blue, yellow): ";
    getline(cin, color1);

    while (color1 != "red" && color1 != "blue" && color1 != "yellow")
    {
        cout << "Error: Invalid color. Please enter a primary color (red, blue, yellow): ";
        getline(cin, color1);
    }

    cout << "Enter another primary color: ";
    cin >> color2;

    while (color2 != "red" && color2 != "blue" && color2 != "yellow")
    {
        cout << "Error: Invalid color. Please enter a primary color (red, blue, yellow): ";
        cin >> color2;
    }

    if (color1 == color2)
    {
        cout << "The mixed color is " << color1 << ".\n";
    }
    else if (color1 == "red" && color2 == "blue" || color1 == "blue" && color2 == "red")
    {
        cout << "The mixed color is purple.\n";
    }
    else if (color1 == "red" && color2 == "yellow" || color1 == "yellow" && color2 == "red")
    {
        cout << "The mixed color is orange.\n";
    }
    else if (color1 == "blue" && color2 == "yellow" || color1 == "yellow" && color2 == "blue")
    {
        cout << "The mixed color is green.\n";
    }
    else
    {
        cout << "Error: Invalid colors.\n";
    }

    return 0;
}