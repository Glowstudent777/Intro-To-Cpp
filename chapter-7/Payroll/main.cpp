/*****
 * Author: Glowstudent
 * Program: Payroll
 *****/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

bool isNumber(const std::string &s)
{
    return !s.empty() && s.find_first_not_of("-.0123456789") == std::string::npos;
}

int main()
{
    const long int empId[7] = {5658845, 4520125, 7895122, 8777541, 8451277, 1302850, 7580489};
    const double minPayRate = 15.00;
    int hours[7];
    double payRate[7], wages[7];

    for (int i = 0; i < 7; i++)
    {
        string s;
        int tempHours;
        double tempPayRate;

        cout << "Enter the hours worked by employee " << empId[i] << ": ";
        getline(cin, s);

        while (s.empty() || !isNumber(s) || stoi(s) < 0)
        {
            cout << "Invalid input. Please enter a positive number: ";
            getline(cin, s);
        }

        tempHours = stoi(s);

        cout << "Enter the pay rate for employee " << empId[i] << ": ";
        getline(cin, s);

        while (s.empty() || !isNumber(s) || stod(s) < minPayRate)
        {
            cout << "Invalid input. Please enter a positive number greater than or equal to " << minPayRate << ": ";
            getline(cin, s);
        }

        tempPayRate = stod(s);

        hours[i] = (int)tempHours;
        payRate[i] = tempPayRate;

        wages[i] = tempHours * tempPayRate;
    }

    cout << endl;
    cout << setprecision(2) << fixed;
    cout << "Employee ID\tHours Worked\tPay Rate\tWages" << endl;
    cout << "--------------------------------------------------------" << endl;
    for (int i = 0; i < 7; i++)
    {
        cout << empId[i] << "\t\t" << hours[i] << "\t\t$" << payRate[i] << "\t\t$" << wages[i] << endl;
    }
    cout << endl;

    return 0;
}