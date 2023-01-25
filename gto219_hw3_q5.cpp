#include <iostream>
using namespace std;

int main()
{
    const double poundToKilo = 0.453592;
    const double inchToMet = 0.0254;
    int userWeightPound, userHeightInch;
    double userWeightKilo, userHeightMeter, BMI;

    cout << "Please enter weight (in pounds): ";
    cin >> userWeightPound;
    cout << "Please enter height (in inches): ";
    cin >> userHeightInch;

    userWeightKilo = userWeightPound * poundToKilo;
    userHeightMeter = userHeightInch * inchToMet;
    BMI = userWeightKilo / (userHeightMeter * userHeightMeter);
    
    if (BMI >= 30)
    {
        cout << "The weight status is: Obese";
    }
    else if (BMI >= 25 && BMI < 30)
    {
        cout << "The weight status is: Overweight";
    }
    else if (BMI >= 18.5 && BMI < 25)
    {
        cout << "The weight status is: Normal";
    }
    else
    {
        cout << "The weight status is: Underweight";
    }


}
