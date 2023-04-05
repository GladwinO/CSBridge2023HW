﻿// gto219_hw12.cpp :

#include <iostream>
#include <vector>

class Money {

private:
    long all_cents;


public:
    friend Money operator +(const Money& amount1, const Money& amount2);
    //Returns the sum of the values of amount1 and amount2.

    friend Money operator -(const Money& amount1, const Money& amount2);
    //Returns amount1 minus amount2.

    friend Money operator -(const Money& amount);
    //Returns the negative of the value of amount.

    friend bool operator ==(const Money& amount1, const Money& amount2);
    //Returns true if amount1 and amount2 have the same value; false otherwise.

    friend bool operator <(const Money& amount1, const Money& amount2);
    //Returns true if amount1 is less than amount2; false otherwise.

    Money(long dollars, int cents);
    //Initializes the object so its value represents an amount with
    //the dollars and cents given by the arguments. If the amount
    //is negative, then both dollars and cents should be negative.

    Money(long dollars);
    //Initializes the object so its value represents $dollars.00.

    Money();
    //Initializes the object so its value represents $0.00.

    double get_value() const;
    //Returns the amount of money recorded in the data portion of the calling
    //object.

    friend std::istream& operator >>(std::istream& ins, Money& amount);
    //Overloads the >> operator so it can be used to input values of type
    //Money. Notation for inputting negative amounts is as in − $100.00.
    //Precondition: If ins is a file input stream, then ins has already been
    //connected to a file.

    friend std::ostream& operator <<(std::ostream& outs, const Money& amount);
    //Overloads the << operator so it can be used to output values of type
    //Money. Precedes each output value of type Money with a dollar sign.
    //Precondition: If outs is a file output stream, then outs has already been
    //connected to a file.

};

int digit_to_int(char c);
//Function declaration for function used in the definition of Money::input:
//Precondition: c is one of the digits '0' through '9'.
//Returns the integer for the digit; for example, digit_to_int ('3') returns 3.




class Check {

private:
    int checkNum;
    Money checkAmount;
    bool isCashed;

public:


    Check(int checkNum, Money checkAmount, bool isCashed);

    Check(int checkNum, Money checkAmount);

    Check(int checkNum);

    Check();

    int getCheckNum() const;
    double getCheckAmount() const;
    bool getIsCashed() const;

    void setCheckNum(int newCheckNum);
    void setCheckAmount(Money newCheckAmount);
    void setIsCashed(bool newIsCashed);
    friend Check operator -(const Check& lhs, Check& rhs);


    friend std::istream& operator >>(std::istream& ins, Check& userInput);
    //friend std::ostream& operator <<(std::ostream& outs, const Check& userInput);

    //I need a copy constructor
};


int main()
{
    int numChecks = 0, numDeposit = 0;
    Check userCheck;
    Money userDeposit, oldUserAccBalance, newUserAccBalance, bankAccBalance;
    std::vector<Check> userChecksVec;
    std::vector<Money> userDepositVec;

    std::cout << "Please enter the number of the check. the check amount, and whether the check has"
        << " been cashed.\nEnter a whole number to represent the check number.\n" <<
        "For the check amount, enter in the format $49.00.\n" <<
        "Enter either a 1 if the check has been cashed or 0 if the check has not been cashed\n"
        << "Example entry: 3 $233.23 1.\n" << 
        "When finished enter 0 $0.00 0 to exit.\n" << std::endl;

    std::cin >> userCheck;
    numChecks++;

    while (userCheck.getCheckNum() != 0 || userCheck.getCheckAmount() != 0 || userCheck.getIsCashed() != 0) {
        userChecksVec.push_back(userCheck);
        std::cin >> userCheck;

        if (userCheck.getCheckNum() != 0 || userCheck.getCheckAmount() != 0 || userCheck.getIsCashed() != 0) {

            numChecks++;
        }
    }
    
    
    /*for (int i = 0; i < numChecks; i++) {
        std::cout << userChecksVec[i].getCheckNum() << " $" << userChecksVec[i].getCheckAmount() <<
            " " << userChecksVec[i].getIsCashed() << std::endl;
    }*/

    /*std::cout << "Please enter all new deposits in the form $45.00.\n" 
        << "When finished please enter $0.00 to exit.\n" << std::endl;

    std::cin >> userDeposit;
    numDeposit++;

    while (userDeposit.get_value() != 0) {
        userDepositVec.push_back(userDeposit);
        std::cin >> userDeposit;

        if (userDeposit.get_value() != 0) {

            numDeposit++;
        }
    }*/

    /*for (int i = 0; i < numDeposit; i++) {
        std::cout << "$" << userDepositVec[i].get_value() << std::endl;
    }*/

    std::cout << "Please enter the old account balance in the form $10.00:" << std::endl;
    std::cin >> oldUserAccBalance;

    std::cout << "Please enter the new account balance in the form $10.00:" << std::endl;
    std::cin >> newUserAccBalance;


    std::cout << userChecksVec[0].getCheckAmount() - userChecksVec[1].getCheckAmount() << std::endl;
    std::cout << oldUserAccBalance - userChecksVec[0].getCheckAmount() << std::endl;
    std::cout << oldUserAccBalance.get_value() - userChecksVec[0].getCheckAmount() << std::endl;
    std::cout << newUserAccBalance - oldUserAccBalance << std::endl;

    std::cout << oldUserAccBalance << " " << oldUserAccBalance.get_value() << std::endl;

    

}


Check operator -(const Check& lhs, Check& rhs) {
    Check temp;
    temp.checkAmount = lhs.checkAmount - rhs.checkAmount;
    return temp;
}

int Check::getCheckNum() const {
    return checkNum;
}

double Check::getCheckAmount() const {
    return checkAmount.get_value();
}

bool Check::getIsCashed() const {
    return isCashed;
}

void Check::setCheckNum(int newCheckNum) {
    if (newCheckNum != checkNum && newCheckNum >= 0) {
        checkNum = newCheckNum;
    }
}
void Check::setCheckAmount(Money newCheckAmount) {
    if (newCheckAmount.get_value() != checkAmount.get_value() && newCheckAmount.get_value() >= 0) {
        checkAmount = newCheckAmount;
    }
}
void Check::setIsCashed(bool newIsCashed) {
    if (newIsCashed != isCashed) {
        isCashed = newIsCashed;
    }
}

Check::Check(int checkNum, Money checkAmount, bool isCashed) : checkNum(checkNum), checkAmount(checkAmount), isCashed(isCashed) {
    //Body intentionally blank.
}   //I am currently worried about what this constructor is actually doing with 
    // the Money variable when it accepts a value

Check::Check(int checkNum, Money checkAmount) : checkNum(checkNum), checkAmount(checkAmount), isCashed(false) {
    //Body intentionally blank.
}

Check::Check(int checkNum) : checkNum(checkNum), checkAmount(0), isCashed(false) {
    //Body intentionally blank.
}

Check::Check() : checkNum(0), checkAmount(0), isCashed(false) {
    //Body intentionally blank.
}

std::istream& operator >>(std::istream& ins, Check& userInput) {
    int userCheckNum;
    Money userCheckAmount;
    bool userIsCashed;

    ins >> userCheckNum >> userCheckAmount >> userIsCashed;

    if (userCheckNum < 0) {
        std::cout << "An incorrect check number value was entered. This program will now exit.";
        exit(1);
    }

    userInput.checkNum = userCheckNum;
    userInput.checkAmount = userCheckAmount;
    userInput.isCashed = userIsCashed;


    return ins;
}

/*std::ostream& operator <<(std::ostream& outs, const Check& userInput) {
    outs << userInput.checkNum;
    outs << userInput.checkAmount;
    outs << userInput.isCashed;

    return outs;
}*/















































Money operator +(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents + amount2.all_cents;
    return temp;

}

Money operator -(const Money& amount1, const Money& amount2) {
    Money temp;
    temp.all_cents = amount1.all_cents - amount2.all_cents;
    return temp;
}

Money operator -(const Money& amount) {
    Money temp;
    temp.all_cents = -amount.all_cents;
    return temp;
}

bool operator ==(const Money& amount1, const Money& amount2) {
    return (amount1.all_cents == amount2.all_cents);
}

bool operator <(const Money& amount1, const Money& amount2)
{
    return (amount1.all_cents < amount2.all_cents);
}

Money::Money(long dollars, int cents)
{
    if (dollars * cents < 0) //If one is negative and one is positive
    {
        std::cout << "Error illegal form for money input\n";
        std::exit(1);

    }
    all_cents = dollars * 100 + cents;

}

Money::Money(long dollars) : all_cents(dollars * 100) {
    //Body intentionally blank.
}

Money::Money() : all_cents(0) {
    //Body intentionally blank.
}

double Money::get_value() const {
    return (all_cents * 0.01);
}

std::istream& operator >>(std::istream& ins, Money& amount) {
    char one_char, decimal_point, digit1, digit2;
    //digits for the amount of cents
    long dollars;
    int cents;
    bool negative;//set to true if input is negative.

    ins >> one_char;
    if (one_char == '-') {
        negative = true;
        ins >> one_char; //read '$'
    }
    else {
        negative = false;
        //if input is legal, then one_char == '$'
    }
    ins >> dollars >> decimal_point >> digit1 >> digit2;


    if (one_char != '$' || decimal_point != '.'
        || !isdigit(digit1) || !isdigit(digit2)) {

        std::cout << "Error illegal form for money input\n";
        std::exit(1);
    }

    cents = digit_to_int(digit1) * 10 + digit_to_int(digit2);

    amount.all_cents = dollars * 100 + cents;
    if (negative) {
        amount.all_cents = -amount.all_cents;
    }

    return ins;
}

std::ostream& operator <<(std::ostream& outs, const Money& amount) {
    long positive_cents, dollars, cents;
    positive_cents = labs(amount.all_cents);
    dollars = positive_cents / 100;
    cents = positive_cents % 100;

    if (amount.all_cents < 0) {
        outs << "-$" << dollars << '.';
    }
    else {
        outs << "$" << dollars << '.';
    }

    if (cents < 10) {
        outs << '0';
    }
    outs << cents;

    return outs;
}




int digit_to_int(char c)
{
    return (static_cast<int>(c) - static_cast<int>('0'));
}
