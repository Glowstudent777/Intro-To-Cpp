/*****
 * Author: Glowstudent
 * Program: Monkey Business
 *****/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    double data[3][5], average = 0, total = 0;
    int lowMonkey = -1, highMonkey = -1;
    double low = -1, high = -1;

    for (int i = 0; i < 3; i++)
    {
        cout << "Enter the data for monkey " << i + 1 << endl;
        for (int j = 0; j < 5; j++)
        {
            cout << "Enter pounds of food eaten for day " << j + 1 << ": ";
            cin >> data[i][j];

            while (data[i][j] < 0 || data[i][j] < 0)
            {
                cout << "Invalid input. Please enter a positive number: ";
                cin >> data[i][j];
            }
        }
    }

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            total += data[i][j];
            average += data[i][j];

            if (low == -1 && high == -1)
            {
                low = data[i][j];
                lowMonkey = i;

                high = data[i][j];
                highMonkey = i;
            }

            if (data[i][j] < low)
            {
                low = data[i][j];
                lowMonkey = i;
            }

            if (data[i][j] > high)
            {
                high = data[i][j];
                highMonkey = i;
            }
        }
    }

    cout << endl;
    cout << setprecision(2) << fixed;
    cout << "The average amount of food eaten by all monkeys per day: " << average / 15 << endl;
    cout << "The least amount of food eaten during the week is " << low << " by monkey " << (lowMonkey + 1) << endl;
    cout << "The most amount of food eaten during the week is " << high << " by monkey " << (highMonkey + 1) << endl;

    return 0;
}