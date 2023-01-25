

#include <iostream>
using namespace std;

int main()
{
    const int FlOOR_ROUND = 1;
    const int CEILING_ROUND = 2;
    const int ROUND = 3;

    double userRealNum;
    int userChoice;
    double roundLowerLim, roundUpperLim;

    cout << "Please enter a Real number: " << endl;
    cin >> userRealNum;

    roundLowerLim = int(userRealNum) + .50;
    

    cout << "Choose your rounding method:\n" <<
        "1.Floor round\n" << "2.Ceiling round\n" <<
        "3.Round to the nearest whole number" << endl;
    cin >> userChoice;

    
    

    switch (userChoice)
    {
    case 1:

        //floor only wants the 1's place of the userRealNum
        cout << int(userRealNum);
        break;

    case 2:

        //ceiling will round to the next highest whole number if the decimal place != 00
        if (userRealNum > int(userRealNum))
        {
            userRealNum = int(userRealNum) + 1;
            cout << userRealNum;
        }
        else
        {
            cout << userRealNum;
        }
        break;

    case 3:

        //nearest whole number will round down if decimal < .5 and up if decimal >= .5
        if (userRealNum >= roundLowerLim)
        {
            userRealNum = int(userRealNum) + 1;
            cout << userRealNum;
        }
        else
        {
            cout << int(userRealNum);
        }
        break;

    default:

        cout << "Please choose a number from the available options.";
        break;
    }
}

