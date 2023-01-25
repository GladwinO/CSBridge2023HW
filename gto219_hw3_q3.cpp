

#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main()
{
    double userA, userB, userC;
    double discrim, userBSqua, addQuadNum, subtQuadNum, quadDenom;
    double solu1, solu2;

    cout << setprecision(2);
    cout << fixed;


    cout << "Please enter value of a: ";
    cin >> userA;
    cout << "Please enter value of b: ";
    cin >> userB;
    cout << "Please enter value of c: ";
    cin >> userC;
    
    userBSqua = userB * userB;
    discrim = userBSqua - (4.0 * userA * userC);
    addQuadNum = -userB + sqrt(discrim);
    subtQuadNum = -userB - sqrt(discrim);
    quadDenom = 2 * userA;


    // if the discrim is greater than or equal to 0 it has a real solution
    //if discrim is greater than 0 the quadratic has two solutions
    //if discrim is equal to 0 the quadratic has 1 solution 

   

    if (userA != 0 && discrim >= 0)
    {
        if (discrim > 0)
        {
            solu1 = addQuadNum / quadDenom;
            solu2 = subtQuadNum / quadDenom;

            cout << "This equation has two real solutions: x = " << solu1
                << " and x = " << solu2 << endl;
        }
        else
        {
            //when discrim = 0 1both solutions from the quadratic are the same number
            solu1 = addQuadNum / quadDenom;

            cout << "This equation has one real solution x = " << solu1 <<  endl;
        }
    }
    else if (userA != 0 && discrim < 0)
    {
        cout << "This equation has no real solutions" << endl;
    }
    else if (userA == 0 && userB == 0 && userC != 0)
    {
        cout << "This equation has no solutions" << endl;
    }
    else if (userA == 0 && userB == 0 && userC == 0)
    {
        cout << "This equation has infinite solutions" << endl;
    }
    

    
   
}

