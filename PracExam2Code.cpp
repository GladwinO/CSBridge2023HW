// PracExam2Code.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>

//void modArr(int arr[], int arrLen);
int maxZeroLength(int arr[], int arrLen, int arrInd);

int main()
{ 
    int userNumInput = 0;
    std::cout << "Num of numbers: ";
    std::cin >> userNumInput;

    int* userArr = new int[userNumInput];

    std::cout << "Enter " << userNumInput<< " numbers." << std::endl;
    for (int i = 0; i < userNumInput; i++)
    {
        std::cin >> userArr[i];
    }

    std::cout << maxZeroLength(userArr, userNumInput, 0);

    /*modArr(userArr, userNumInput);

    for (int i = 0; i < userNumInput; i++)
    {
        std::cout << userArr[i] << ",";
    }*/




}

//void modArr(int arr[], int arrLen)
//{
//    int i = 0;
//    int counter = 0;
//
//    while (i < arrLen)
//    {
//        if (arr[i] > 0)
//        {
//            arr[counter] = arr[i];
//            counter++;
//        }
//
//        i++;
//    }
//
//    for (int i = counter; i < arrLen; i++)
//    {
//        arr[i] = 0;
//    }
//}


int maxZeroLength(int arr[], int arrLen, int arrInd)
{
    //int maxLen = 0;

    if (arrInd >= arrLen)
    {
        return 0;
    }
    int maxLen = 0;

    while (arrInd < arrLen && arr[arrInd] == 0)
    {
       maxLen++;
       arrInd++;
    }
    arrInd++; //with this here the arrInd will not get stuck 
    //at the non-zero but will also be incremented past the arrLen
    //since the last value in the array is a 0

    return std::max(maxLen, maxZeroLength(arr, arrLen, arrInd));
}

//int maxZeroLength(int nums[], int len, int startIdx) {
//    //base case -->
//    if (startIdx == len) {
//        return 0;
//    }
//    int maxLen = 0;
//    while (startIdx < len && nums[startIdx++] == 0) {
//        maxLen++;
//    }
//    return std::max(maxLen, maxZeroLength(nums, len, startIdx));
//}