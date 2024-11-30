/*****
 * Author: Glowstudent
 * Program: Rainfall Statistics
 *****/

#include <iostream>
#include <iomanip>
#include <limits>
#include <vector>

using namespace std;

int main()
{
    vector<double> monthlyRainfall(12);
    double totalRainfall = 0, averageRainfall = 0, lowestRainfall = 0, highestRainfall = 0;
    int lowestMonth = 0, highestMonth = 0;

    cout << "Enter the rainfall for each month for the past year." << endl;

    for (int j = 1; j <= 12; j++)
    {
        double rainfall;

        cout << "Enter the rainfall for month " << j << " : ";
        cin >> rainfall;

        while (rainfall < 0 || cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << "The rainfall must be at least 0." << endl;
            cout << "Enter the rainfall for month " << j << " : ";
            cin >> rainfall;
        }

        rainfall += 0; // -0 to 0, -0 can become weird numbers sometimes; probably memory problem or something.
        monthlyRainfall[j - 1] = rainfall;
    }

    for (int j = 0; j < 12; j++)
    {
        totalRainfall += monthlyRainfall[j];

        if (j == 0)
        {
            lowestRainfall = monthlyRainfall[j];
            highestRainfall = monthlyRainfall[j];
            lowestMonth = j + 1;
            highestMonth = j + 1;
        }
        else
        {
            if (monthlyRainfall[j] < lowestRainfall)
            {
                lowestRainfall = monthlyRainfall[j];
                lowestMonth = j + 1;
            }

            if (monthlyRainfall[j] > highestRainfall)
            {
                highestRainfall = monthlyRainfall[j];
                highestMonth = j + 1;
            }
        }
    }

    averageRainfall = totalRainfall / 12;

    cout << endl;
    cout << fixed << setprecision(2);
    cout << "Total Rainfall: " << totalRainfall << endl;
    cout << "Average Rainfall: " << averageRainfall << endl;
    cout << "Lowest Rainfall was month " << lowestMonth << ": " << lowestRainfall << endl;
    cout << "Highest Rainfall was month " << highestMonth << ": " << highestRainfall << endl;

    return 0;
}