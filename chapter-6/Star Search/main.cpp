/*****
 * Author: Glowstudent
 * Program: Star Search
 *****/

#include <iostream>
#include <iomanip>
#include <limits>

using namespace std;

float findLowest(float scores[5])
{
    float lowest = scores[0];
    for (int i = 1; i < 5; i++)
    {
        if (scores[i] < lowest)
        {
            lowest = scores[i];
        }
    }
    return lowest;
}

float findHighest(float scores[5])
{
    float highest = scores[0];
    for (int i = 1; i < 5; i++)
    {
        if (scores[i] > highest)
        {
            highest = scores[i];
        }
    }
    return highest;
}

void getJudgeData(int judgeNum, float &score)
{
    cout << "Enter the score for judge " << judgeNum << ": ";
    cin >> score;

    while (score < 0 || score > 10 || cin.fail())
    {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << endl;
        cout << "Score must be between 0 and 10." << endl;
        cout << "Enter the score for judge " << judgeNum << ": ";
        cin >> score;
    }
}

void calcScore(float scores[5])
{
    float lowest = findLowest(scores);
    float highest = findHighest(scores);
    float total = 0;

    for (int i = 0; i < 5; i++)
    {
        total += scores[i];
    }

    total -= lowest;
    total -= highest;

    cout << setprecision(1) << fixed;
    cout << "The contestant's final score is: " << total / 3 << endl;
}

int main()
{
    float judgeScores[5];

    for (int i = 0; i < 5; i++)
    {
        getJudgeData(i + 1, judgeScores[i]);
    }

    cout << endl;
    calcScore(judgeScores);

    return 0;
}