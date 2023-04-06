/*
Question 5:
Write a program that asks the user to input a positive integer n, and prints a textual image of an
hourglass made of 2n lines with asterisks.
For example if n=4, the program should print:
*******
 *****
  ***
   *
   *
  ***
 *****
*******
*/

#include <iostream>
using namespace std;

int main()
{
    int userInput, numRows, rowPos = 0;

    cout << "Please enter a positive number: ";
    cin >> userInput;
    numRows = 2 * userInput;
    int starNum = numRows - 1;
    int starBotNum = numRows - 1;
    int numSpace = 0, numBotSpace = userInput - 1;

    for (int i = 0; i < numRows; i++)
    {
        if (rowPos < userInput)
        {
            for (int j = 0; j < starNum; j++)
            {
                cout << "*";
            }
            cout << "\n";
            starNum -= 2;

            numSpace += 1;

            if (numSpace < userInput)
            {
                for (int k = 0; k < numSpace; k++)
                {
                    cout << " ";
                }
            }
            
            
        }
        else
        {
        
            for (int k = 0; k < numBotSpace; k++)
            {
                cout << " ";
            }
            
            numBotSpace -= 1;


            for (int j = numRows; j > starBotNum; j--)
            {
                cout << "*";
            }
            cout << "\n";
            starBotNum -= 2;


        
        }

        rowPos++;


    }
}

