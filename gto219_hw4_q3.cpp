/*
Question 3:
Write a program that reads from the user a positive integer (in a decimal representation), and
prints its binary (base 2) representation.
Your program should interact with the user exactly as it shows in the following example:
Enter decimal number:
76
The binary representation of 76 is 1001100
Implementation Requirements:
1. You are supposed to implement the algorithm that converts to base 2. You should not use
any string or special cout functionalities to make the conversion.
2. You are not allowed to use arrays.
*/

#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int userPosInt, expoCounter = 0;
    int bitDeciTot = 0, bitTot = 0, curDeci = 0;
    const int numBase = 2;
    const int alphanum = 1;
   

    cout << "Enter decimal number:" << endl;
    cin >> userPosInt;
    
    if (userPosInt > 0)
    {
        if (userPosInt == 1)
        {
            expoCounter = 0;
            cout << pow(2, expoCounter) << endl;
        }
        else
        {

            curDeci = userPosInt;
            while (bitDeciTot != userPosInt)
            {
                int j = 0;
                expoCounter = 0;

                while (j <= curDeci)
                {
                    expoCounter++;
                    j = pow(numBase, expoCounter);

                }

                expoCounter -= 1;
                j = pow(numBase, expoCounter);
                bitDeciTot += pow(numBase, expoCounter);
                bitTot += alphanum * pow(10, expoCounter);
                curDeci = userPosInt;
                curDeci -= bitDeciTot;

                //this would also work as a condition for the main while loop: if(curDeci == 0)




            }
            cout << bitTot << endl;

        }
    }
    else
    {
        cout << "Error: Non-Positve Integer Entered!\nPlease enter a positive inetger.";
    }
    


    
}

