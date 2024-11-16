/*****
 * Author: Glowstudent
 * Program: Rectangle Area - Complete
 *****/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

double getLength()
{
    double length;

    cout << "Enter the length of the rectangle: ";
    cin >> length;

    while (length < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << "Length must be a positive value." << endl;
        cout << "Enter the length of the rectangle: ";
        cin >> length;
    }

    return length;
}

double getWidth()
{
    double width;

    cout << "Enter the width of the rectangle: ";
    cin >> width;

    while (width < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << "Width must be a positive value." << endl;
        cout << "Enter the width of the rectangle: ";
        cin >> width;
    }

    return width;
}

double getArea(double length, double width)
{
    return length * width;
}

void displayData(double length, double width, double area)
{
    cout << endl;
    cout << setprecision(2) << fixed;
    cout << "The length of the rectangle is: " << length << endl;
    cout << "The width of the rectangle is: " << width << endl;
    cout << "The area of the rectangle is: " << area << endl;
}

int main()
{
    double length, width, area;

    length = getLength();
    width = getWidth();
    area = getArea(length, width);

    displayData(length, width, area);

    return 0;
}