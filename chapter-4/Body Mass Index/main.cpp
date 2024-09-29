/*****
 * Author: Glowstudent
 * Body Mass Index
 *****/

#include <iostream>
#include <limits>
#include <iomanip>

using namespace std;

int main()
{
    float weight;
    float height;
    float bmi;

    cout << "Enter your weight in pounds: ";
    cin >> weight;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter your weight in pounds: ";
        cin >> weight;
    }

    cout << "Enter your height in inches: ";
    cin >> height;

    while (cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Enter your height in inches: ";
        cin >> height;
    }

    bmi = (weight * 703) / (height * height);

    if (bmi < 18.5)
    {
        cout << setprecision(1) << fixed << "Your BMI is " << bmi << ". You are underweight." << endl;
    }
    else if (bmi >= 18.5 && bmi <= 24.9)
    {
        cout << setprecision(1) << fixed << showpoint << "Your BMI is " << bmi << ". You are normal." << endl;
    }
    else if (bmi >= 25 && bmi <= 29.9)
    {
        cout << setprecision(1) << fixed << "Your BMI is " << bmi << ". You are overweight." << endl;
    }
    else
    {
        cout << setprecision(1) << fixed << "Your BMI is " << bmi << ". You are obese." << endl;
    }

    return 0;
}