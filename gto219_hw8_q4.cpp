// gto219_hw8_q4.cpp 
#include <iostream>
using namespace std;

void randArrNumGen(int arr[], int arrSize);
//void userNumSep(int arr[], int userNum);
//bool pinCheck(int arr[]);

int main()
{
    int arrPin[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
    const int randNumArrSize = 10;
    int randNumArr[randNumArrSize];
    int userNum;
    int userNumArr[randNumArrSize];

    randArrNumGen(randNumArr, randNumArrSize);
    
    cout << "Please enter your PIN according to the following mapping:" << endl;
    cout << "PIN:   0 1 2 3 4 5 6 7 8 9" << endl;


    cout << "NUM:   ";
    for (int i = 0; i < 10; i++)
    {
        cout << randNumArr[i] << " ";
    }

    /*cin >> userNum;
    userNumSep(userNumArr, userNum);
    cout << userNumArr;
    */
}

void randArrNumGen(int arr[], int arrSize)
{
    int randNum;
    int upperLim = 9, lowerLim = 0;

    for (int i = 0; i < arrSize; i++)
    {
        arr[i] = (rand() % (upperLim - lowerLim + 1)) + lowerLim;
    }
    
}

/*void userNumSep(int arr[], int userNum)
{
    int remainder = -1;
    int diviLeft = -1;
    int ind = 0;
    while(diviLeft != 0)
    {
        remainder = userNum % 10;
        arr[ind] = remainder;
        ind++;
        diviLeft = userNum / 10;
    }
}*/



