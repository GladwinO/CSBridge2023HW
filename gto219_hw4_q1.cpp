/*
Question 1:
Write two versions of a program that reads a positive integer n, and prints the first n even
numbers.
a) In the first, use a while loop.
b) In the second, use a for loop.
Each section should interact with the user exactly as it shows in the following example:
Please enter a positive integer: 3
2
4
6
*/

#include <iostream>
using namespace std;

int main()
{
	int posInt;

	cout << "While loop example" << endl;
	cout << "Please enter a positive integer : ";
	cin >> posInt;

	if (posInt > 0)
	{
		int j = 1;
		while (j <= posInt)
		{
			cout << j * 2 << endl;
			j++;
		}

	}
	else
	{
		cout << "Non-positive number entered!" << endl;
	}


	cout << "For Loop Example" << endl;
	cout << "Please enter a positive integer : ";
	cin >> posInt;

	if (posInt > 0)
	{
		for (int i = 1; i <= posInt; i++)
		{
			cout << i * 2 << endl;
		}
	}
	else
	{
		cout << "Non-positive number entered!" << endl;
	}
}

