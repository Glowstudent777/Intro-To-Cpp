/*****
 * Author: Glowstudent
 * Program: Student Line Up
 *****/

#include <iostream>
#include <string>
#include <fstream>
#include <set>

using namespace std;

int main()
{
    ifstream inFile;
    string s;
    set<string> students;

    inFile.open("LineUp.txt");

    if (!inFile)
    {
        cout << "Error opening file." << endl;
        return 1;
    }

    while (getline(inFile, s) && s != "")
    {
        students.insert(s);
    }
    inFile.close();

    cout << "There are " << students.size() << " students in the file." << endl;

    cout << "\nThe students in the file are: " << endl;
    for (auto student : students)
    {
        cout << student << endl;
    }

    return 0;
}