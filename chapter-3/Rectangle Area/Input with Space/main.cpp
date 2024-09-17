/*****
* Author: Glowstudent
* Rectangle Area
*****/

#include <iostream>

using namespace std;

int main() {
    int length, width, area;

    cout << "This program calculates the area of a rectangle.\n";

    cout << "Enter the length and width of the rectangle seperated by a space (12 8): ";
    cin >> length >> width;

    area = length * width;
    cout << "The area of the rectangle is: " << area << endl;

    return 0;
}
