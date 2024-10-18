/*****
 * Author: Glowstudent
 * Program: Sales Bar Chart
 *****/

#include <iostream>
#include <limits>

using namespace std;

void clearScreen()
{
    // Clear the screen
#if defined(_WIN32) || defined(_WIN64)
    system("cls");
#elif defined(__linux__)
    system("clear");
#elif defined(__APPLE__)
    system("clear");
#endif
}

int main()
{
    int storeSales[5];

    clearScreen();

    // Use a loop to get the sales for each store
    for (int i = 1; i <= 5; i++)
    {
        cout << "Enter today's sales for store " << i << ": ";
        cin >> storeSales[i - 1];

        while (storeSales[i - 1] < 0 || cin.fail())
        {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            // If the input is large enough it says it is negative so we can use a generic error message instead of checking for both instead.
            cout << "Invalid input. Please re-enter: ";
            cin >> storeSales[i - 1];
        }
    }

    cout << "\nSALES BAR CHART\n(Each * = $100)\n";

    // Use a loop to display the sales bar chart
    for (int i = 1; i <= 5; i++)
    {
        cout << "Store " << i << ": ";
        for (int j = 0; j < storeSales[i - 1] / 100; j++)
        {
            cout << "*";
        }
        cout << endl;
    }

    return 0;
}