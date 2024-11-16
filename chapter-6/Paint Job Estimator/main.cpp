/*****
 * Author: Glowstudent
 * Program: Paint Job Estimator
 *****/

#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

using namespace std;

int getRooms()
{
    int rooms;

    cout << "Enter the number of rooms to be painted: ";
    cin >> rooms;

    while (rooms < 1 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << "Number of rooms must be at least 1." << endl;
        cout << "Enter the number of rooms to be painted: ";
        cin >> rooms;
    }

    return rooms;
}

double getSquareFeet(int roomNum)
{
    double sqfeet;

    cout << "Enter the square feet of room " << roomNum << ": ";
    cin >> sqfeet;

    while (sqfeet < 1 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << "Square feet must be at least 1." << endl;
        cout << "Enter the square feet of room " << roomNum << ": ";
        cin >> sqfeet;
    }

    return sqfeet;
}

double pricePerGallon()
{
    double minPrice = 10.00, price;

    cout << "Enter the price of paint per gallon: $";
    cin >> price;

    while (price < minPrice || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << "Price must be at least $" << minPrice << "." << endl;
        cout << "Enter the price of paint per gallon: $";
        cin >> price;
    }

    return price;
}

void displayData(int &gallonsNeeded, int &hours, double &paintPrice, double &laborPrice, double &totalCost)
{
    cout << endl;
    cout << setprecision(2) << fixed;
    cout << "Gallons of paint needed: " << gallonsNeeded << endl;
    cout << "Hours of labor required: " << hours << endl;
    cout << "Total cost of paint: $" << paintPrice * gallonsNeeded << endl;
    cout << "Labor costs: $" << laborPrice << endl;
    cout << "Total: $" << totalCost << endl;
}

int main()
{
    // For every 110 sq feet of wall space, 1 gallon of paint and 8 hours of labor are required.
    // The company charges $25.00 per hour for labor.
    const double pricePerHour = 25.00, sqfeetPerGallon = 110, hourPerGallon = 8;
    double sqfeet, paintPrice, laborPrice, totalCost;
    int gallons, hours;
    const int rooms = getRooms();
    const double timePerSqFeet = 1 / (sqfeetPerGallon / hourPerGallon);

    for (int i = 0; i < rooms; i++)
    {
        sqfeet += getSquareFeet(i + 1);
    }

    paintPrice = pricePerGallon();

    // Rounding because you can't buy a fraction of a gallon or pay for a fraction of an hour.
    gallons = ceil(sqfeet / sqfeetPerGallon);
    hours = ceil(sqfeet * timePerSqFeet);
    laborPrice = hours * pricePerHour;
    totalCost = gallons * paintPrice + laborPrice;

    displayData(gallons, hours, paintPrice, laborPrice, totalCost);

    return 0;
}