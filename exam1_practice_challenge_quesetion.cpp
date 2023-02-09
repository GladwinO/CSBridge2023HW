

#include <iostream>
using namespace std;

int main() {
    int input;
    char frame = '#';
    char planks = '$';
    char space = ' ';
    cout << "Enter positive integer: ";
    cin >> input;
    for (int i = 0; i < input; i++) { //rows
        for (int j = 0; j < input; j++) {
            // left or right or top or bottom
            if (j == 0 || j == input - 1 || i == 0 || i == input - 1) {
                cout << frame;
            }
            // left diagonal going right || right diagonal going left
            else if (i == j || i + j == input - 1) {
                cout << planks;
            }
            else {
                cout << space;
            }
        }
        cout << endl;
    }
}

/*
int main()
{
    int userNum, numMidSpaces, numFrontSpaces = 1;

    cout << "Please enter a positve number: ";
    cin >> userNum;

    for (int i = 1; i <= userNum; i++)
    {
        if (i == userNum / userNum || i == userNum)
        {
            for (int j = 0; j < userNum; j++)
            {
                cout << '#';
            }
            
        }

        cout << "\n\n";

        cout << '#';
        if (i > 1 && i < 5)
        {
            for (int k = 0; k <= numFrontSpaces; k++)
            {
                cout << " ";
            }
            cout << '$';
            numFrontSpaces++;

            for(int f = 0; f <)
        }
    }
}*/
