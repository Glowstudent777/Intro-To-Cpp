/*****
 * Author: Glowstudent
 * Restaurant Menu
 *****/

#include <iostream>
#include <limits>
#include <iomanip>
#include <string>

#include <cctype>
#include <random>

using namespace std;

// Should never see this. Used in the default section of the switch statements.
string errormsg = "There was an error. Please try again.";

// Let the other functions see these before the full logic function is implemented.
void getInt(int &choice, int program, int min, int max, bool clearOnFail);
void getChar(char &input, int program, bool clearOnFail);
void printMenu(int choice);

void Weekdays();
void Saturday();
void Sunday();

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

void randomPrice(float &price, float min, float max)
{
    random_device rd;
    mt19937 gen(rd());

    uniform_real_distribution<float> dis(min, max);

    price = floorf(dis(gen) * 100) / 100;
}

void printMenu(int choice)
{
    switch (choice)
    {
    case 0:
        cout << "Select The Correct Menu:" << endl;
        cout << "1. Monday to Friday" << endl;
        cout << "2. Saturday" << endl;
        cout << "3. Sunday" << endl;
        break;
    case 1:
        cout << "== Monday Through Friday Menu ==" << endl;
        cout << endl;
        // Charge for water because we're fancy assholes
        cout << "== Food ==                      == Drinks ==" << endl;
        cout << "1. Fish           - $29.99      4. Water - $1.00" << endl;
        cout << "2. Sirlion Steak  - $44.99      5. Wine  - $7.00" << endl;
        cout << "3. King Crab      - *MK         6. Beer  - $12.00" << endl;
        break;
    case 2:
        cout << "== Saturday Menu ==" << endl;
        cout << endl;
        cout << "== Food ==                       == Drinks ==" << endl;
        cout << "1. Lobster         - *MK         4. Water            - $1.00" << endl;
        cout << "2. Ribeye          - $75.00      5. Wine             - $7.00" << endl;
        cout << "3. 3oz Wagyu Beef  - $89.99      6.   - $44.99" << endl;
        break;
    case 3:
        cout << "== Sunday Menu ==" << endl;
        cout << endl;
        cout << "== Food ==                     == Drinks ==" << endl;
        cout << "1. Ribs          - $25.00      4. Water            - $1.00" << endl;
        cout << "2. Lobster       - *MK         5. Wine             - $7.00" << endl;
        cout << "3. Filet Mignon  - $75.00      6. Whiskey (Pappy)  - $44.99" << endl;
        break;
    default:
        clearScreen();
        printMenu(0);
        getInt(choice, 0, 1, 3, true);
        break;
    }
}

// Later maybe add min/max optional to just get an int no matter what
// Later maybe add string cmessage for a custom message other than "Enter your choice: "
void getInt(int &input, int program, int min, int max, bool clearOnFail = false)
{
    cout << "Enter your choice: ";
    cin >> input;

    while (cin.fail() || input < min || input > max)
    {
        if (clearOnFail == true)
        {
            clearScreen();
            printMenu(program);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input. Please enter a valid input: ";
        cin >> input;
    }
}

void getChar(char &input, int program, bool clearOnFail = false)
{
    cout << "Enter your choice: ";
    cin >> input;

    while (cin.fail() || !isalpha(input))
    {
        if (clearOnFail == true)
        {
            clearScreen();
            printMenu(program);
        }
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Invalid Input. Please enter a valid input: ";
        cin >> input;
    }
}

int main()
{
    int choice;

    clearScreen();
    printMenu(0);

    getInt(choice, 0, 1, 4, true);

    // Set the stage for the programs
    clearScreen();
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    switch (choice)
    {
    case 1:
        Weekdays();
        break;
    case 2:
        Saturday();
        break;
    case 3:
        Sunday();
        break;
    default:
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        main();
        break;
    }

    return 0;
}

void Weekdays()
{
    int input;
    float mk;

    randomPrice(mk, 50.00, 100.00);

    printMenu(1);
    cout << "*Current MK is: " << mk << endl;
    getInt(input, 1, 1, 6);

    cout << "You selected: " << input << endl;
}

void Saturday()
{
    int input;
    float mk;

    randomPrice(mk, 50.00, 100.00);

    printMenu(2);
    cout << "*Current MK is: " << mk << endl;
    getInt(input, 2, 1, 6);

    cout << "You selected: " << input << endl;
}

void Sunday()
{
    int input;
    float mk;

    randomPrice(mk, 50.00, 100.00);

    printMenu(3);
    cout << "*Current MK is: " << mk << endl;
    getInt(input, 3, 1, 6);

    cout << "You selected: " << input << endl;
}