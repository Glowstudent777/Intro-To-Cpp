/*****
 * Author: Glowstudent
 * Program: Grade Book
 *****/

#include <iostream>
#include <string>
#include <iomanip>
#include <limits>

using namespace std;

int main()
{
    string students[5], studentName;
    char grades[5];
    double testScores[5][4], averages[5], tempAverage = 0;

    for (int i = 0; i < 5; i++)
    {
        cout << "Enter student " << i + 1 << "'s name: ";
        getline(cin, studentName);

        while (studentName.empty())
        {
            cout << studentName.empty() << endl;
            cout << (studentName == "") << endl;
            cout << studentName << endl;

            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Student name cannot be empty." << endl;
            cout << "Enter student " << i + 1 << "'s name: ";
            getline(cin, studentName);
        }

        for (int j = 0; j < 4; j++)
        {
            cout << "Enter " << studentName << "'s score for test " << j + 1 << ": ";
            cin >> testScores[i][j];

            while (cin.fail() || testScores[i][j] > 100 || testScores[i][j] < 0)
            {
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
                cout << "Invalid score. Please enter a valid score: ";
                cin >> testScores[i][j];
            }

            tempAverage += testScores[i][j];
        }

        if (tempAverage / 4 >= 90)
        {
            grades[i] = 'A';
        }
        else if (tempAverage / 4 >= 80)
        {
            grades[i] = 'B';
        }
        else if (tempAverage / 4 >= 70)
        {
            grades[i] = 'C';
        }
        else if (tempAverage / 4 >= 60)
        {
            grades[i] = 'D';
        }
        else
        {
            grades[i] = 'F';
        }

        students[i] = studentName;
        averages[i] = tempAverage / 4;

        tempAverage = 0;

        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    cout << endl;
    cout << setw(20) << left << "Student Name" << setw(20) << left << "Average" << setw(20) << left << "Grade" << endl;
    cout << "-----------------------------------------------" << endl;
    for (int i = 0; i < 5; i++)
    {
        cout << setw(20) << left << students[i] << setw(20) << left << averages[i] << setw(20) << left << grades[i] << endl;
    }

    return 0;
}