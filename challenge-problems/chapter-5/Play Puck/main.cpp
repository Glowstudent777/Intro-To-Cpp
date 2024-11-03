/*****
 * Author: Glowstudent
 * Program: Play Puck
 *****/

#include <iostream>
#include <string>
#include <fstream>
#include <set>
#include <unordered_map>
#include <vector>
#include "consoleUtils.h"

using namespace std;

// List from https://geojango.com/pages/list-of-nhl-teams
const set<string> teams = {"Anaheim Ducks", "Arizona Coyotes", "Boston Bruins", "Buffalo Sabres", "Calgary Flames", "Carolina Hurricanes", "Chicago Blackhawks", "Colorado Avalanche", "Columbus Blue Jackets", "Dallas Stars", "Detroit Red Wings", "Edmonton Oilers", "Florida Panthers", "Los Angeles Kings", "Minnesota Wild", "Montreal Canadiens", "Nashville Predators", "New Jersey Devils", "New York Islanders", "New York Rangers", "Ottawa Senators", "Philadelphia Flyers", "Pittsburgh Penguins", "San Jose Sharks", "Seattle Kraken", "St. Louis Blues", "Tampa Bay Lightning", "Toronto Maple Leafs", "Vancouver Canucks", "Vegas Golden Knights", "Washington Capitals", "Winnipeg Jets"};
const unordered_map<string, vector<string>> prefixMap = {
    {"ANAHEIM", {}},
    {"ARIZONA", {"AZ"}},
    {"BOSTON", {}},
    {"BUFFALO", {}},
    {"CALGARY", {"AB"}},
    {"CAROLINA", {"NC"}},
    {"CHICAGO", {}},
    {"COLORADO", {"CO"}},
    {"COLUMBUS", {}},
    {"DALLAS", {"TX"}},
    {"DETROIT", {}},
    {"EDMONTON", {"AB"}},
    {"FLORIDA", {"FL"}},
    {"LOS ANGELES", {"LA"}},
    {"MINNESOTA", {"MN"}},
    {"MONTREAL", {"QC"}},
    {"NASHVILLE", {"TN"}},
    {"NEW JERSEY", {"NJ"}},
    {"NEW YORK", {"NY"}},
    {"OTTAWA", {"ON"}},
    {"PHILADELPHIA", {"PHILLY", "PA"}},
    {"PITTSBURGH", {"PITTS", "PA"}},
    {"SAN JOSE", {"SJ"}},
    {"SEATTLE", {"WA"}},
    {"ST. LOUIS", {"ST LOUIS", "SAINT LOUIS", "SL"}},
    {"TAMPA BAY", {"TAMPA", "TB"}},
    {"TORONTO", {"ON"}},
    {"VANCOUVER", {"BC"}},
    {"VEGAS", {"LAS VEGAS", "LOS VEGAS", "NV"}},
    {"WASHINGTON", {"DC"}},
    {"WINNIPEG", {"MANITOBA", "MB"}}};
const string sentinel = "END";
set<string> userTeams = {};
ofstream outFile;
ifstream inFile;

// This function took way too long to write and I can't believe it works nor do I fully understand it
// I'm sure there's a better way to do this but if it works, don't touch it
// Comments will explain what's happening with my understanding.
string stripPrefix(string input)
{
    string inputUpper = toUpper(input);

    // This for loop takes the prefix map and creates a key/value pair.
    // The auto should make the key/value pair the type of <string, vector<string>> like my map.
    // EX: ["NEW YORK", {"NY"}]
    for (const auto &[fullPrefix, abbreviations] : prefixMap)
    {
        if (inputUpper.find(fullPrefix + " ") == 0)
        {
            return input.substr(fullPrefix.size() + 1);
        }

        // This for loop takes each abbreviation from the abbreviations vector.
        // The "ST. LOUIS" key will loop through this {"ST LOUIS", "SAINT LOUIS", "SL"} and assign each value as the abbr value.
        // First loop checks for "ST LOUIS", second loop checks for "SAINT LOUIS", third loop checks for "SL", etc.
        for (const string &abbr : abbreviations)
        {
            if (inputUpper.find(abbr + " ") == 0 || inputUpper == abbr)
            {
                return input.substr(abbr.size() + 1);
            }
        }
    }

    return input;
}

void handleInput(string input)
{
    for (auto team : teams)
    {
        if (toUpper(input) == toUpper(team) || toUpper(stripPrefix(input)) == toUpper(stripPrefix(team)))
        {
            if (!userTeams.count(team))
            {
                outFile << team << endl;
                userTeams.insert(team);
            }
            break;
        }
    }
}

int main()
{
    string input;
    string s;
    int teamsNamed = 0;

    setTitle("Play Puck");
    clearScreen();

    cout << "Welcome to Play Puck!" << endl;
    cout << "Enter the names of as many NHL teams as you can. There are a total of 32. Can you name them all?" << endl;
    cout << "Enter 'END' when you are unable to think of anymore." << endl;
    cout << "\n";

    outFile.open("NamedTeams.txt");

    while (true)
    {
        cout << "Enter a team name: ";
        getline(cin, input);

        if (toUpper(input) == sentinel)
        {
            break;
        }
        handleInput(input);
    }

    outFile.close();
    clearScreen();

    inFile.open("NamedTeams.txt");

    // Can't do .size() from userTeams because one req is to count from the file.
    while (getline(inFile, s) && s != "")
    {
        teamsNamed++;
    }

    if (teamsNamed == 32)
        cout << "Outstanding! You managed to name all 32 teams!" << endl;
    else if (teamsNamed >= 16)
        cout << "Very Good! You named at least half the teams! " << teamsNamed << " to be exact." << endl;
    else if (teamsNamed >= 8)
        cout << "You did good. You named " << teamsNamed << ", teams which is at least a 4th of them." << endl;
    else if (teamsNamed > 0)
        cout << "You named " << teamsNamed << ", which is alright." << endl;
    else
        cout << "You didn't name any teams :(" << endl;

    if (teamsNamed > 0)
    {
        cout << "\nHere are the teams you entered:" << endl;

        // Reset to beginning of file
        inFile.clear();
        inFile.seekg(0);

        // Can't list from userTeams because one req is to read from file the named teams.
        while (getline(inFile, s) && s != "")
        {
            cout << "* " << s << endl;
        }
    }

    inFile.close();

    return 0;
}