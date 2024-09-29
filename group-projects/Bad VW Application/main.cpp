/*****
 * Author: Glowstudent
 * Bad VW Application (VolksWagen)
 *****/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Vehicle
{
public:
    string model;
    float mpg;
    float reduction = 0;
    float honestMpg = 0;
};

void displayTable(const string titles[], Vehicle models[])
{
    // Find the longest string in each column and store the length for formatting

    int columns = 0;
    while (!titles[columns].empty())
    {
        columns++;
    }

    for (int i = 0; i < columns; i++)
    {
        cout << setw(15) << titles[i];
    }

    cout << columns << endl;
}

int main()
{
    // A table of 5 VW models, one golf, and one beetle
    // The table will show the model and the MPG

    // Another 5 vehicles but Chrysler or Fiat models, one Jeep
    // The table will show the model and the MPG

    // A cell in the table will show the 10% reduction in MPG for each model
    // Newly calculated honest MPG to the nearest 10th for each model

    // Basic table layout
    // | Model | MPG | 10% Reduction | Honest MPG |
    // |-------|-----|---------------|------------|
    // | Golf  | 30  | 3             | 27         |
    // | Beetle| 25  | 2.5           | 22.5       |
    // | Jeep  | 20  | 2             | 18         |

    string titles[4] = {"Model", "MPG", "10% Reduction", "Honest MPG"};

    // array of VW models
    Vehicle vwModels[3] = {
        {"Golf", 30},
        {"Beetle", 25},
        {"Jeep", 20}};

    // array of Chrysler/Fiat models
    Vehicle chryslerFiatModels[3] = {
        {"200", 30},
        {"300", 25},
        {"Jeep", 20}};

    // Display the table
    displayTable(titles, vwModels);

    // Spacer
    cout << endl;
    cout << endl;

    // Display the table
    cout << "VW Models" << endl;
    cout << "| Model  | MPG | 10% Reduction | Honest MPG |" << endl;
    cout << "|--------|-----|---------------|------------|" << endl;
    cout << "| Golf   | 30  | 3             | 27         |" << endl;
    cout << "| Beetle | 25  | 2.5           | 22.5       |" << endl;
    cout << "| Jeep   | 20  | 2             | 18         |" << endl;

    // Spacer
    cout << endl;

    cout << "Chrysler/Fiat Models" << endl;
    cout << "| Model  | MPG | 10% Reduction | Honest MPG |" << endl;
    cout << "|--------|-----|---------------|------------|" << endl;
    cout << "| 200    | 30  | 3             | 27         |" << endl;
    cout << "| 300    | 25  | 2.5           | 22.5       |" << endl;
    cout << "| Jeep   | 20  | 2             | 18         |" << endl;

    return 0;
}