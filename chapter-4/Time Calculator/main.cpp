/*****
 * Author: Glowstudent
 * Time Calculator
 *****/

#include <iostream>
#include <limits>
#include <string>

using namespace std;

void formatTime(int days, int hours, int minutes, int seconds)
{
    string result;

    // Print with only the necessary time units and with proper grammar
    // 60 seconds = 1 minute
    // 61 seconds = 1 minute and 1 second
    // 3740 seconds = 1 hour, 2 minutes, and 20 seconds

    if (days > 0)
    {
        result += to_string(days) + " day" + (days > 1 ? "s" : "");
    }
    if (hours > 0)
    {
        if (!result.empty())
            result += (minutes > 0 || seconds > 0) ? ", " : " and ";
        result += to_string(hours) + " hour" + (hours > 1 ? "s" : "");
    }
    if (minutes > 0)
    {
        if (!result.empty())
            result += (seconds > 0) ? ", " : " and ";
        result += to_string(minutes) + " minute" + (minutes > 1 ? "s" : "");
    }
    if (seconds > 0)
    {
        if (!result.empty())
            result += " and ";
        result += to_string(seconds) + " second" + (seconds > 1 ? "s" : "");
    }

    if (result.empty())
    {
        cout << "There was an error calculating the time." << "Please try again." << endl;
    }
    else
    {
        cout << "The number of seconds you entered is equivalent to: " << result << "." << endl;
    }
}

int main()
{
    int seconds;

    cout << "Enter a number of seconds: ";
    cin >> seconds;

    while (seconds < 0 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Error: Enter a number of seconds: ";
        cin >> seconds;
    }

    int minutes = seconds / 60;
    int hours = minutes / 60;
    int days = hours / 24;
    seconds %= 60;
    minutes %= 60;
    hours %= 24;

    formatTime(days, hours, minutes, seconds);

    return 0;
}