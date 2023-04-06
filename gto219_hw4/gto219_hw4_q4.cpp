/*
Question 4:
Write two versions of a program that reads a sequence of positive integers from the user,
calculates their geometric mean, and print the geometric mean.
Notes:
1. In mathematics, geometric mean of a dataset {??!, ??", ??# …, ??$} containing positive
numbers, is given by: &??! ? ??" ? ??# ??? ??$
! .
For example, the geometric mean of 2, 9 and 12 is equal to 6 (?2 ? 9 ? 12 " = 6).
2. In order to calculate the n-th root of a number, you should call the pow function, located
in the cmath library.
Your two versions should read the integer sequence in two ways:
a) First read the length of the sequence.
For example, an execution would look like:
Please enter the length of the sequence: 3
Please enter your sequence:
1
2
3
The geometric mean is: 1.8171
b) Keep reading the numbers until -1 is entered.
For example, an execution would look like:
Please enter a non-empty sequence of positive integers, each one in a separate line. End your
sequence by typing -1:
1
2
3
-1
The geometric mean is: 1.8171
*/


#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    int userSeqLen, curUserInput;
    double geoSum = 1;
    double geoMean, nthRoot;

    cout << "Please enter the length of the sequence: ";
    cin >> userSeqLen;

    nthRoot = 1.0 / userSeqLen;
    
    cout << "Please enter your sequnce:" << endl;

    for (int i = 0; i < userSeqLen; i++)
    {
        cin >> curUserInput;
        geoSum *= curUserInput;

    }
    geoMean = pow(geoSum, nthRoot);
    cout << setprecision(4);
    cout << fixed;
    cout << "The geometric mean is: " << geoMean << endl;

    ///////////////////////////////////////////////////////////////////////


    int curWhileUserInput, geoWhileSum = 1, seqCounter = 0;
    double geoWhileMean, nthRootWhile;



    cout << "\nPlease enter a non-empty sequence of positive integers, each one in a separate line." <<
        " End your sequence by typing -1:" << endl;

    cin >> curWhileUserInput;

    while (curWhileUserInput != -1)
    {
        
        geoWhileSum *= curWhileUserInput;
        cin >> curWhileUserInput;
        seqCounter++;
    }
    nthRootWhile = 1.0 / seqCounter;
    geoWhileMean = pow(geoWhileSum, nthRootWhile);
    cout << "The geometric mean is: " << geoWhileMean << endl;
}

