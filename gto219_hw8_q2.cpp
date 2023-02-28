// gto219_hw8_q2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(string str);

int main()
{
    string userStr;
    cout << "Please provide a word: ";
    cin >> userStr;

   
   if (isPalindrome(userStr))
   {
       cout << userStr << " is a palindrome";
   }
   else
   {
       cout << userStr << " is not a palindrome";
   }
}

bool isPalindrome(string str)
{
    int strLength = str.length();
    int endStr = strLength - 1;
    string reverseStr;

    for (int i = endStr; i >= 0; i--)
    {
        reverseStr += str[i];
    }
    
    
    if (reverseStr == str)
    {
        return true;
    }
    else
    {
        return false;
    }
}
