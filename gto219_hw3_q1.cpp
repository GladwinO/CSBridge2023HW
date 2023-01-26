#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    double frtItemPrice, secItemPrice, discItemPrice, taxRate, taxRateDecimal;
    double basePrice, discPromoPrice, clubDiscPrice, taxPrice, totPrice;
    char clubMem;
    const double promotionDisc = 0.5;
    const double clubMemDisc = 0.10;

    cout << "Enter price of first item: ";
    cin >> frtItemPrice; 
    cout << "Enter price of second item: ";
    cin >> secItemPrice; 
    cout << "Does customer have a club card? (Y/N): ";
    cin >> clubMem;
    cout << "Enter tax rate, e.g. 5.5 for 5.5% tax: ";
    cin >> taxRate;
    

    clubMem = tolower(clubMem);
    basePrice = frtItemPrice + secItemPrice;

    if (frtItemPrice <= secItemPrice)
    {
        discItemPrice = frtItemPrice * promotionDisc;
        discPromoPrice = discItemPrice + secItemPrice;
    }
    else if (secItemPrice < frtItemPrice)
    {
        discItemPrice = secItemPrice * promotionDisc;
        discPromoPrice = discItemPrice + frtItemPrice;
    }

    if (clubMem == 'y')
    {
        double discAmount;
        discAmount = discPromoPrice * clubMemDisc;
        clubDiscPrice = discPromoPrice - discAmount;
    }
    else if (clubMem == 'n')
    {
        clubDiscPrice = discPromoPrice;
    }
    else
    {
        cout << "ERROR: You did not enter Y or N.";
       
    }

    taxRateDecimal = taxRate / 100; 
    taxPrice = clubDiscPrice * taxRateDecimal;
    totPrice = clubDiscPrice + taxPrice;


    cout << setprecision(1);
    cout << fixed;
    cout << "Base price: " << basePrice << endl;
    cout << "Price after discounts: " << clubDiscPrice << endl;

    cout << setprecision(5);
    cout << fixed;
    cout << "Total price: " << totPrice << endl;

}