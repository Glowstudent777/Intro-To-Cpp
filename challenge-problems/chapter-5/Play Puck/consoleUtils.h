#ifndef CONSOLEUTILS_H
#define CONSOLEUTILS_H

#include <iostream>
#include <iomanip>
#include <sstream>
#include <limits>

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

#endif