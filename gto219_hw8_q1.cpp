// gto219_hw8_q1.cpp 

#include <iostream>
using namespace std;

void minArrayInd(int arr[], int arrSize);
int minInArray(int arr[], int arrSize);


int main()
{
	const int arrSize = 20;
	int userArr[arrSize];

	cout << "Please enter 20 intgers separated by a space:" << endl;
	for (int i = 0; i < arrSize; i++)
	{
		cin >> userArr[i];
	}
	
	minArrayInd(userArr, arrSize);
	
}

void minArrayInd(int arr[], int arrSize)
{
	int minNum; 
	minNum = minInArray(arr, arrSize);

	const int locArrSize = sizeof(arr);
	int numLoc[locArrSize];
	int counter = 0;

	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] == minNum)
		{
			numLoc[counter] = i;
			counter++;
		}
	}

	cout << "The minimum value is " << minNum << ", and it is located" <<
		" in the following indices: ";
	for (int i = 0; i < counter; i++)
	{
		cout << numLoc[i] << " ";
	}

}

int minInArray(int arr[], int arrSize)
{
	int currMinNum = arr[0];
	
	for (int i = 0; i < arrSize; i++)
	{
		if (arr[i] <= currMinNum)
		{
			currMinNum = arr[i];
		}
	}
	return currMinNum;
}


