/*****
 * Author: Glowstudent
 * Stadium Seating
 *****/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
    int classASeats, classBSeats, classCSeats;
    float classASeatCost = 15, classBSeatCost = 12, classCSeatCost = 9, totalIncome, classATotal, classBTotal, classCTotal;

    // Consistent spacing
    const int indent = 10, letters = 6;

    cout << "How many Class A seats were sold? ";
    cin >> classASeats;

    cout << "How many Class B seats were sold? ";
    cin >> classBSeats;

    cout << "How many Class C seats were sold? ";
    cin >> classCSeats;

    classATotal = classASeatCost * classASeats;
    classBTotal = classBSeatCost * classBSeats;
    classCTotal = classCSeatCost * classCSeats;

    // Spacing :)
    cout << "\n";

    cout << "Class A" << setw(indent) << "Class B" << setw(indent) << "Class C" << endl;
    cout << "-------" << setw(indent) << "-------" << setw(indent) << "-------" << endl;
    
    int aExtra = to_string((int)classATotal).length(), bExtra = to_string((int)classBTotal).length();
    cout << setprecision(2) << fixed << "$" << classATotal << setw(indent - 3 - aExtra) << "$" << classBTotal << setw(indent - 3 - bExtra) << "$" << classCTotal << endl;

    // More Spacing :)
    cout << "\n";

    totalIncome = (classASeats * classASeatCost) + (classBSeats * classBSeatCost) + (classCSeats * classCSeatCost);

    cout << setprecision(2) << fixed << "Total income generated from ticket sales: $" << totalIncome << endl;

    return 0;
}
