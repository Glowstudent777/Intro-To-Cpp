/*****
 * Author: Glowstudent
 * Program: Numeric Processing
 *****/

#include <iostream>
#include <string>
#include <fstream>
#include <iomanip>

using namespace std;

int main()
{
    ifstream inFile;
    string s;
    double average = 0;
    int count = 0, sum = 0;

    inFile.open("Random.txt");

    if (!inFile)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    while (getline(inFile, s) && s != "")
    {
        sum += stoi(s);
        count++;
    }

    average = static_cast<double>(sum) / static_cast<double>(count);

    cout << "There are " << count << " numbers in the file." << endl;
    cout << fixed << setprecision(2);
    cout << "The average of the numbers in the file is: " << average << endl;
    cout << setprecision(0);
    cout << "The sum of the numbers in the file is: " << sum << endl;

    inFile.close();

    return 0;
}