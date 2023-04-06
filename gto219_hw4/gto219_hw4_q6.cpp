/*
Question 6:
Write a program that asks the user to input a positive integer n, and print all of the numbers
from 1 to n that have more even digits than odd digits.
For example, if n=30, the program should print:
2
4
6
8
20
22
24
26
28

*/

#include <iostream>
using namespace std;

int main()
{
    int userInput, diviInt, numOddInt = 0, numEvenInt = 0; 
    int deciPlac = 10;
    int firDeciPlac;
    
    cout << "Please provide a positive integer: ";
    cin >> userInput;

     for (int i = 1; i <= userInput; i++)
     {
         
         diviInt = i;


         firDeciPlac = i % 10;

         

         if (firDeciPlac % 2 == 0 && firDeciPlac > 0)
         {
             numEvenInt++;
             
         }
         else if (firDeciPlac % 2 != 0 && firDeciPlac > 0)
         {
             numOddInt++;
             
         }


         while (diviInt != 0)
         {
             
             
             diviInt = i / deciPlac;
             

             deciPlac *= 10;
             

             if (diviInt % 2 == 0 and diviInt > 0)
             {
                 numEvenInt++;
             }
             else if (diviInt % 2 != 0 and diviInt > 0)
             {
                 numOddInt++;
             }

            

         }
         deciPlac = 10;
        
         
        
         
         if (numEvenInt > numOddInt)
         {
             cout << i << endl;
         }
         
         numEvenInt = 0;
         numOddInt = 0;
         
     }


 
        

}


