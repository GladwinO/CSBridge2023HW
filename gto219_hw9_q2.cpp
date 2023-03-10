// gto219_hw9_q2.cpp : 

#include <iostream>
#include <string>

using namespace std;

string lowerCaseConv(string userString);
string removePuncNWhiteSpace(string userString);
void numUniqueLet(string userString, int arr[]);
bool anagramFinder(int arr1[], int arr2[]);

int main()
{
	const int alphaLen = 26;
	bool isAnagram;
	string userString1, userString2, origUserString1, origUserString2;
	int userString1Len, userString2Len;
	int letterCounter1[alphaLen] = { 0 }, letterCounter2[alphaLen] = { 0 };


	cout << "Please enter two strings separated by an enter." << endl;
	getline(cin, userString1);
	getline(cin, userString2);

	origUserString1 = userString1;
	origUserString2 = userString2;

	userString1 = removePuncNWhiteSpace(lowerCaseConv(userString1));
	userString2 = removePuncNWhiteSpace(lowerCaseConv(userString2));

	numUniqueLet(userString1, letterCounter1);
	numUniqueLet(userString2, letterCounter2);

	isAnagram = anagramFinder(letterCounter1, letterCounter2);

	if (isAnagram)
	{
		cout << "\n" << origUserString1 << "\nand\n" << origUserString2 << "\nare anagrams!" << endl;
	}
	else
	{
		cout << "\n" << origUserString1 << "\nand\n" << origUserString2 << "\nare not anagrams!" << endl;
	}




	return 0;

}

string lowerCaseConv(string userString)
{
	int userStringLen;
	userStringLen = userString.length();

	for (int i = 0; i < userStringLen; i++)
	{
		userString[i] = tolower(userString[i]);
	}

	return userString;
}

string removePuncNWhiteSpace(string userString)
{
	string newString;
	int counter = 0;
	int userStringLen;
	userStringLen = userString.length();

	for (int i = 0; i < userStringLen; i++)
	{
		if (!ispunct(userString[i]) && !isspace(userString[i]))
		{
			newString.push_back(userString[i]);
			counter++;
		}
	}
	return newString;
}

void numUniqueLet(string userString, int arr[])
{

	int userStringLen;
	userStringLen = userString.length();


	for (int i = 0; i < userStringLen; i++)
	{
		switch (userString[i])
		{
		case 'a':
			arr[0] += 1;
			break;
		case 'b':
			arr[1] += 1;
			break;
		case 'c':
			arr[2] += 1;
			break;
		case 'd':
			arr[3] += 1;
			break;
		case 'e':
			arr[4] += 1;
			break;
		case 'f':
			arr[5] += 1;
			break;
		case 'g':
			arr[6] += 1;
			break;
		case 'h':
			arr[7] += 1;
			break;
		case 'i':
			arr[8] += 1;
			break;
		case 'j':
			arr[9] += 1;
			break;
		case 'k':
			arr[10] += 1;
			break;
		case 'l':
			arr[11] += 1;
			break;
		case 'm':
			arr[12] += 1;
			break;
		case 'n':
			arr[13] += 1;
			break;
		case 'o':
			arr[14] += 1;
			break;
		case 'p':
			arr[15] += 1;
			break;
		case 'q':
			arr[16] += 1;
			break;
		case 'r':
			arr[17] += 1;
			break;
		case 's':
			arr[18] += 1;
			break;
		case 't':
			arr[19] += 1;
			break;
		case 'u':
			arr[20] += 1;
			break;
		case 'v':
			arr[21] += 1;
			break;
		case 'w':
			arr[22] += 1;
			break;
		case 'x':
			arr[23] += 1;
			break;
		case 'y':
			arr[24] += 1;
			break;
		case 'z':
			arr[25] += 1;
			break;
		default:
			cout << "Error: character entered was a number or was not accounted for!" << endl;

		}
	}
}


bool anagramFinder(int arr1[], int arr2[])
{
	const int arrLen = 26;
	bool returnVal;

	for (int i = 0; i < arrLen; i++)
	{
		if (arr1[i] == arr2[i])
		{
			returnVal = true;
		}
		else
		{
			return false;
			//the return exits the for loop and function
		}
	}
	return returnVal;
}