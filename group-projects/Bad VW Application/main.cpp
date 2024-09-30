/*****
 * Author: Glowstudent
 * Bad VW Application (VolksWagen)
 *****/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

float calculateHonestMPG(float mpg)
{
    return mpg - (mpg * 0.10);
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

    cout << setprecision(1) << fixed;

    // Numbers are averaged from highway and city MPG
    cout << "VW Models" << endl;
    cout << "| Model       | MPG  | 10% Reduction | Honest MPG |" << endl;
    cout << "|-------------|------|---------------|------------|" << endl;
    cout << "| 1976 Golf   | 23   | 2.3           | " << calculateHonestMPG(23) << "       |" << endl;
    cout << "| 1974 Beetle | 20   | 2             | " << calculateHonestMPG(20) << "       |" << endl;
    cout << "| Atlas       | 20.5 | 2.05          | " << calculateHonestMPG(20.5) << "       |" << endl;
    cout << "| 2022 Jetta  | 35.3 | 3.53          | " << calculateHonestMPG(35.3) << "       |" << endl;
    cout << "| Passat      | 24.8 | 2.48          | " << calculateHonestMPG(24.8) << "       |" << endl;

    // Spacer
    cout << endl;

    cout << "Chrysler/Fiat Models" << endl;
    cout << "| Model | MPG  | 10% Reduction | Honest MPG |" << endl;
    cout << "|-------|------|---------------|------------|" << endl;
    cout << "| 200   | 23.6 | 2.36          | " << calculateHonestMPG(23.6) << "       |" << endl;
    cout << "| 300   | 20   | 2             | " << calculateHonestMPG(20) << "       |" << endl;
    cout << "| 500x  | 28.7 | 2.87          | " << calculateHonestMPG(28.7) << "       |" << endl;
    cout << "| Neon  | 21.4 | 2.14          | " << calculateHonestMPG(21.4) << "       |" << endl;
    cout << "| Bravo | 22.5 | 2.25          | " << calculateHonestMPG(22.5) << "       |" << endl;

    return 0;
}