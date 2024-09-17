/*****
* Author: Glowstudent
* Weight Conversion
*****/

#include <iostream>

using namespace std;

int main() {
    double pounds, kilograms;

    cout << "This program converts pounds to kilograms.\n";

    cout << "Enter the weight in pounds: ";
    cin >> pounds;

    // 1lb is 0.453592kg
    kilograms = pounds * 0.453592;
    cout << "The weight in kilograms is: " << kilograms << endl;

    return 0;
}