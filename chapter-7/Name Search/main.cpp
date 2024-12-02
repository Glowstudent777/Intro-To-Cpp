/*****
 * Author: Glowstudent
 * Program: Name Search
 *****/

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

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

string toUpper(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }

    return str;
}

int main()
{
    vector<string> boyNames;
    vector<string> girlNames;
    string s, name, temp;
    bool popBoy = false, popGirl = false;
    ifstream boyFile, girlFile;

    boyFile.open("BoyNames.txt");
    girlFile.open("GirlNames.txt");

    if (!boyFile)
    {
        cout << "Error opening BoyNames.txt\n";
        return 1;
    }

    if (!girlFile)
    {
        cout << "Error opening GirlNames.txt\n";
        return 1;
    }

    while (getline(boyFile, s) && !boyFile.eof())
    {
        if (s == "")
            continue;

        boyNames.push_back(s);
    }
    while (getline(girlFile, s) && !girlFile.eof())
    {
        if (s == "")
            continue;

        girlNames.push_back(s);
    }

    boyFile.close();
    girlFile.close();

    while (true)
    {
        clearScreen();

        cout << "Enter a name to search for (exit to exit): ";
        getline(cin, s);

        while (s == "" || s == " ")
        {
            cout << "Please enter a name: ";
            getline(cin, s);
        }

        if (toUpper(s) == "EXIT")
            break;

        for (int i = 0; i < boyNames.size(); i++)
        {
            if (popBoy && popGirl)
                break;

            if (toUpper(s) == toUpper(boyNames[i]))
            {
                popBoy = true;
                name = boyNames[i];
            }

            if (toUpper(s) == toUpper(girlNames[i]))
            {
                popGirl = true;
                name = girlNames[i];
            }
        }

        if (popBoy && popGirl)
            cout << name << " is a popular name for both boys and girls.\n";
        else if (popBoy)
            cout << name << " is a popular boy name.\n";
        else if (popGirl)
            cout << name << " is a popular girl name.\n";
        else
            cout << name << " is not a popular name.\n";

        popBoy = false;
        popGirl = false;
        name = "";
        s = "";

        cout << endl;
        cout << "Press Enter to continue...";
        getline(cin, temp);

        temp = "";
    }

    return 0;
}