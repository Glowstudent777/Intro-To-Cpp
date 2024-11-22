#ifndef CONSOLEUTILS_H
#define CONSOLEUTILS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>
#include <functional>
#include <random>

enum class Alignment
{
    left,
    center,
    right
};

void printText(std::string text, int width, Alignment dir, int offset = 0, char symbol = '*')
{
    int displayLength = text.length();
    int left = 0;
    int right = 0;

    // -2 to account for the asterisks
    switch (dir)
    {
    case Alignment::left:
        left = offset;
        right = width - displayLength - left - 2;
        break;
    case Alignment::center:
        left = ((width - displayLength) / 2) - 1;
        right = width - displayLength - left - 2;
        break;
    case Alignment::right:
        right = offset;
        left = width - displayLength - right - 2;
        break;
    }

    std::cout << symbol << std::string(left, ' ') << text << std::string(right, ' ') << symbol << std::endl;
}

void printSpacer(int width, char symbol = '*')
{
    std::cout << symbol << std::string(width - 2, symbol) << symbol << std::endl;
}

void fullLine(int width, char symbol = '*')
{
    std::cout << std::string(width, symbol) << std::endl;
}

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

void resetInput()
{
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

std::string format_currency(float amount)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(2) << amount / 100;
    std::string formatted = stream.str();
    return formatted;
}

void setTitle(std::string title)
{
    std::cout << "\033]0;" << title << "\007";
}

std::string toUpper(std::string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }

    return str;
}

void getInt_Menu(int &input, int menu, void (*func)(int), int min = '\0', int max = '\0', std::string cmessage = "", bool clearOnFail = false)
{
    if (cmessage != "")
    {
        std::cout << cmessage;
    }
    else
    {
        std::cout << "Enter your choice: ";
    }
    std::cin >> input;

    while (std::cin.fail() || ((min == max && max == '\0') ? false : (input < min || input > max)))
    {
        if (clearOnFail == true)
        {
            clearScreen();
            func(menu);
        }
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid Input. Please enter a valid input: ";
        std::cin >> input;
    }
}

void getInt(int &input, std::string cmessage = "", int min = '\0', int max = '\0')
{
    if (cmessage != "")
    {
        std::cout << cmessage;
    }
    else
    {
        std::cout << "Enter your choice: ";
    }
    std::cin >> input;

    while (std::cin.fail() || ((min == '\0' && max == min) ? false : (input < min || input > max)))
    {
        resetInput();
        std::cout << "Invalid Input. Please enter a valid input: ";
        std::cin >> input;
    }
}

void randomInt(int &var, int min = 1, int max = 100)
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(min, max);

    var = floorf(dis(gen) * 100) / 100;
}

void normalizeString(std::string &str)
{
    std::string temp;
    bool first = true;

    for (int i = 0; i < str.length(); i++)
    {
        if ((str[i + 1] == ' ' && str[i] == ' ') || (first && str[i] == ' ') || (!str[i + 1] && str[i] == ' '))
            continue;

        temp += str[i];
        first = false;
    }

    str = temp;
}

#endif
