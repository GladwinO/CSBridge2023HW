// gto219_hw10_q2.cpp

#include <iostream>
#include <vector>


int* findMissing(int arr[], int n, int& resArrSize);
int* requestUserArray(int maxNum);
int* creatAscenNumArr(int numVal);

int main()
{
    int numInputVals{ 0 }, missinNumArrSize{0};
    int* inputArray;
    int* missingNumArray;
    
    std::cout << "Please enter the max number of values you will enter: " << std::endl;
    std::cin >> numInputVals;
     
    inputArray = requestUserArray(numInputVals);

    /*for (int i = 0; i < numInputVals; i++)
    {
        std::cout << inputArray[i] << std::endl;
    }*/


    delete[] inputArray;
    inputArray = nullptr;

    //delete[] missingNumArray;
    //missingNumArray = nullptr;

    return 0;
}

int* requestUserArray(int maxNum)
{
    int* userArray = new int[maxNum];

    std::cout << "Please enter a list of " << maxNum << " numbers" << std::endl;
    std::cout << "The " << maxNum << " numbers should range from 0 to " << maxNum << std::endl;
    
    for (int i = 0; i < maxNum; i++)
    {
        std::cin >> userArray[i];
    }

    return userArray;
}

int* findMissing(int arr[], int n, int& resArrSize)
{
    std::vector<int> tempVec;
    int arrIndexPosCount{0};
    
    int* listOfPossNumArr = new int[n + 1];


    return listOfPossNumArr;
}
 
int* creatAscenNumArr(int numVal)
{
    dfdfd
}