/*****
 * Author: Glowstudent
 * Restaurant Menu
 *****/

#include <iostream>
#include <limits>
#include <iomanip>
#include <string>
#include <map>

// Random number generation
#include <random>

using namespace std;

// Should never see this. Used in the default section of the switch statements.
string errormsg = "There was an error. Please try again.";

// Vector lets us store the order without knowing the size of the array ahead of time.
vector<int> order;
// Map lets us store the count of each item ordered.
map<int, int> itemCount;

// Let the other functions see these before the full logic function is implemented.
void getInt(int &input, int program, int min, int max, string cmessage, bool clearOnFail);
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

// Code is from the example on https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution
// Just modified to use min/max instead of 1.0 and 2.0
// Commented with my understanding of each line
void randomPrice(float &price, float min, float max)
{
    // References for future reference:
    // https://en.cppreference.com/w/cpp/numeric/random/random_device
    // https://en.cppreference.com/w/cpp/numeric/random/mersenne_twister_engine
    // https://en.cppreference.com/w/cpp/numeric/random/uniform_real_distribution

    // Apparently it can generate the same number sequences so it should be used as a seeder rather than just a random number generator
    // Used to seed the random number generator
    random_device rd;

    // The random number generator seeded with rd
    // mt19937 is a apparently called a "Standard Mersenne Twister Engine"
    // Less secure than a crypto co4814 but still we're not doing security here and still passes randomness tests
    mt19937 gen(rd());

    // The distribution of the random number generator
    // <float> so we get a float otherwise it will default to a double if left empty
    uniform_real_distribution<float> dis(min, max);

    // times 100 and divided by 100 just truncates the float to 2 decimal places
    // dis(gen) generates a random number between min and max
    price = floorf(dis(gen) * 100) / 100;
}

void printBill(float total, int menu)
{

    float tax = total * 0.0825;
    tax = floorf(tax * 100) / 100;

    // Maps are very useful but a bit confusing in C++
    // https://en.cppreference.com/w/cpp/container/map
    // https://cplusplus.com/reference/map/map/
    for (int item : order)
    {
        itemCount[item]++;
    }

    cout << "--------------------------------" << endl;

    // Show number of each item ordered
    for (const auto &entry : itemCount)
    {
        switch (menu)
        {
        case 1:
            switch (entry.first)
            {
            case 1:
                cout << "Fish: " << entry.second << " ordered" << endl;
                break;
            case 2:
                cout << "Sirlion Steak: " << entry.second << " ordered" << endl;
                break;
            case 3:
                cout << "King Crab: " << entry.second << " ordered" << endl;
                break;
            case 4:
                cout << "Water: " << entry.second << " ordered" << endl;
                break;
            case 5:
                cout << "Wine: " << entry.second << " ordered" << endl;
                break;
            case 6:
                cout << "Beer: " << entry.second << " ordered" << endl;
                break;
            default:
                cout << "Unknown item ordered" << endl;
                break;
            }
            break;
        case 2:
            switch (entry.first)
            {
            case 1:
                cout << "Lobster: " << entry.second << " ordered" << endl;
                break;
            case 2:
                cout << "Ribeye: " << entry.second << " ordered" << endl;
                break;
            case 3:
                cout << "3oz Wagyu Beef: " << entry.second << " ordered" << endl;
                break;
            case 4:
                cout << "Water: " << entry.second << " ordered" << endl;
                break;
            case 5:
                cout << "Wine: " << entry.second << " ordered" << endl;
                break;
            case 6:
                cout << "Old Fashioned: " << entry.second << " ordered" << endl;
                break;
            default:
                cout << "Unknown item ordered" << endl;
                break;
            }
            break;
        case 3:
            switch (entry.first)
            {
            case 1:
                cout << "Smoked Ribs: " << entry.second << " ordered" << endl;
                break;
            case 2:
                cout << "Lobster: " << entry.second << " ordered" << endl;
                break;
            case 3:
                cout << "Filet Mignon: " << entry.second << " ordered" << endl;
                break;
            case 4:
                cout << "Water: " << entry.second << " ordered" << endl;
                break;
            case 5:
                cout << "Wine: " << entry.second << " ordered" << endl;
                break;
            case 6:
                cout << "Rip Van Winkle: " << entry.second << " ordered" << endl;
                break;
            default:
                cout << "Unknown item ordered" << endl;
                break;
            }
            break;
        }
    }

    cout << "--------------------------------" << endl;
    cout << "Subtotal: $" << total << endl;
    cout << "Tax:      $" << tax << endl;
    cout << "--------------------------------" << endl;
    cout << "Total:    $" << total + tax << endl;
}

// I would prefer a dynamic menu for easier changes but due to time constraints I'm going to hard code the menus
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
        cout << "2. Sirlion Steak  - $44.99      5. Wine  - $12.00" << endl;
        cout << "3. King Crab      - *MK         6. Beer  - $10.00" << endl;
        break;
    case 2:
        cout << "== Saturday Menu ==" << endl;
        cout << endl;
        cout << "== Food ==                       == Drinks ==" << endl;
        cout << "1. Lobster         - *MK         4. Water          - $1.00" << endl;
        cout << "2. Ribeye          - $75.00      5. Wine           - $12.00" << endl;
        cout << "3. 3oz Wagyu Beef  - $89.99      6. Old Fashioned  - $20.99" << endl;
        break;
    case 3:
        cout << "== Sunday Menu ==" << endl;
        cout << endl;
        cout << "== Food ==                     == Drinks ==" << endl;
        cout << "1. Smoked Ribs   - $25.00      4. Water            - $1.00" << endl;
        cout << "2. Lobster       - *MK         5. Wine             - $12.00" << endl;
        cout << "3. Filet Mignon  - $75.00      6. Rip Van Winkle   - $44.99" << endl;
        break;
    default:
        clearScreen();
        printMenu(0);
        getInt(choice, 0, 1, 3, "", true);
        break;
    }
}

// Later maybe add min/max optional to just get an int no matter what
void getInt(int &input, int program, int min, int max, string cmessage = "", bool clearOnFail = false)
{
    if (cmessage != "")
    {
        cout << cmessage;
    }
    else
    {
        cout << "Enter your choice: ";
    }
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

int main()
{
    int choice;

    clearScreen();
    printMenu(0);

    getInt(choice, 0, 1, 4, "", true);

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
    float mk, total = 0.00;

    randomPrice(mk, 50.00, 100.00);

    printMenu(1);
    cout << "* Current MK is: " << mk << endl;
    getInt(input, 1, 1, 6);

    cout << "You selected: " << input << endl;
}

void Saturday()
{
    int input;
    float mk, tax, total = 0.00;

    randomPrice(mk, 50.00, 100.00);

    printMenu(2);
    cout << "* Current MK is: " << mk << endl;
    getInt(input, 2, 0, 6, "Add item or press 0 to finish: ");

    while (input != 0)
    {
        switch (input)
        {
        case 1:
            total += mk;
            order.push_back(1);
            break;
        case 2:
            total += 75.00;
            order.push_back(2);
            break;
        case 3:
            total += 89.99;
            order.push_back(3);
            break;
        case 4:
            total += 1.00;
            order.push_back(4);
            break;
        case 5:
            total += 12.00;
            order.push_back(5);
            break;
        case 6:
            total += 20.99;
            order.push_back(6);
            break;
        default:
            cout << errormsg << endl;
            break;
        }

        getInt(input, 2, 0, 6, "Add more or press 0 to finish: ");
    }

    cout << "\n\n";

    printBill(total, 2);
}

void Sunday()
{
    int input;
    float mk, total = 0.00;

    randomPrice(mk, 50.00, 100.00);

    printMenu(3);
    cout << "* Current MK is: " << mk << endl;
    getInt(input, 3, 1, 6);

    cout << "You selected: " << input << endl;
}