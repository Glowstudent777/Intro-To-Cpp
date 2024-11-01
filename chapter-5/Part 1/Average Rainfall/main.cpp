/*****
 * Author: Glowstudent
 * Program: Average Rainfall
 *****/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    int years;
    double totalRainfall = 0.00, averageRainfall = 0.00;

    cout << "Enter the number of years: ";
    cin >> years;

    while (years < 1 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "The number of years must be at least 1." << endl;
        cout << "Enter the number of years: ";
        cin >> years;
    }

    cout << endl;

    for (int i = 1; i <= years; i++)
    {
        for (int j = 1; j <= 12; j++)
        {
            double rainfall;

            cout << "Enter the rainfall for year " << i << ", month " << j << ": ";
            cin >> rainfall;

            while (rainfall < 0 || cin.fail())
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');

                cout << "The rainfall must be at least 0." << endl;
                cout << "Enter the rainfall for year " << i << ", month " << j << ": ";
                cin >> rainfall;
            }

            totalRainfall += rainfall;
        }
    }

    averageRainfall = totalRainfall / (years * 12);

    cout << endl;

    cout << "The total rainfall for " << years << " years is " << fixed << setprecision(2) << totalRainfall << " inches." << endl;
    cout << "The average monthly rainfall for " << years * 12 << " months is " << fixed << setprecision(2) << averageRainfall << " inches." << endl;

    return 0;
}