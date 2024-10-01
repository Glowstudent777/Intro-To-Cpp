/*****
 * Author: Glowstudent
 * Pyramid
 *****/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int main()
{
	int layers;

	cout << "How many layers should the pyramid have?: ";
	cin >> layers;

    cout << "Here is your pyramid: ";
    cout << "\n\n";

	for (int i = 1; i <= layers; i++)
	{
		int cnt = i == 1 ? i : i + (i - 1);
		
		cout << setw((layers - i + cnt)) << string(cnt, '*') << endl;
	};

	return 0;
}
