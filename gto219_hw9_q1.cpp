// gto219_hw9_q1.cpp : 

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void lowerCaseConv(string& userString);
string removePuncNWhiteSpace(const string& userString);
void numUniqueLet(string userString, int arr[]);
void frontNEndWhiteSpaceRemoval(string& userString);
void whiteSpaceLoc(string userString, vector<int>& vector);
void printNumofEachLetter(int arr[]);


int main()
{
	//this code assumes the user is entering text with correct punction


	const int alphaLen = 26;
	bool isAnagram;
	string userString, origUserString;
	int userStringLen;
	int letterCounter[alphaLen] = { 0 };
	vector<int> whiteSpaceLocations;
	int whiteSpaceLocationsLen;
	int numWords; 


	cout << "Please enter a line of text:" << endl;
	getline(cin, userString);


	origUserString = userString;
	lowerCaseConv(userString);
	frontNEndWhiteSpaceRemoval(userString);
	whiteSpaceLoc(userString, whiteSpaceLocations);

	whiteSpaceLocationsLen = whiteSpaceLocations.size();
	numWords = whiteSpaceLocationsLen + 1;


	userString = removePuncNWhiteSpace(userString);
	numUniqueLet(userString, letterCounter);
	
	cout << numWords << "\t words" << "\n\n";

	printNumofEachLetter(letterCounter);


}

void lowerCaseConv(string& userString)
{
	int userStringLen;
	userStringLen = userString.length();
	
	for (int i = 0; i < userStringLen; i++)
	{
		userString[i] = tolower(userString[i]);
	}

}

string removePuncNWhiteSpace(const string& userString)
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
			cout << "Error: character enter but was not accounted for!" << endl;

		}
	}
}

void whiteSpaceLoc(string userString, vector<int>& vector)
{
	int userStringLen = userString.length();
	
	for (int i = 0; i < userStringLen; i++)
	{
		if (isspace(userString[i]))
		{
			vector.push_back(i);
			
		}
	}
}

void frontNEndWhiteSpaceRemoval(string& userString)
{
	int outsideCharLoc[2] = {0, 0};
	int userStringLen = userString.length();

	for (int i = 0; i < userStringLen; i++)
	{
		if (isalpha(userString[i]))
		{
			outsideCharLoc[0] = i;
			break;
		}
	}

	for (int i = userStringLen - 1; i >= 0; i--)
	{
		if (isalpha(userString[i]))
		{
			outsideCharLoc[1] = i;
			break;
		}
	}

	userString = userString.substr(outsideCharLoc[0], outsideCharLoc[1] - outsideCharLoc[0] + 1);

}

void printNumofEachLetter(int arr[])
{
	const int numLettersInAlpha = 26;

	char alphabetArr[] = { 'a', 'b', 'c', 'd','e', 'f', 'g', 'h',
		'i', 'j', 'k','l','m', 'n', 'o', 'p', 'q', 'r', 's', 't',
		'u', 'v', 'w', 'x', 'y', 'z' };
	
	for (int i = 0; i < numLettersInAlpha; i++)
	{
		if (arr[i] != 0)
		{
			cout << arr[i] << "\t " << alphabetArr[i] << "\n\n";
		}
	}

}