// gto219_hw15.cpp 
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

void openInputFile(std::ifstream& inFile);
int charDigitToInt(char digit);

class BarAttendee {
private:
    long amountPaidInCents;
    std::string userFullName;
    long amountOwedInCents;
public:
    BarAttendee();
    BarAttendee(long amountPaidCents, std::string name);
    BarAttendee(int dollars, int cents, std::string name);
    long getAmountPaid();//amount in cents
    std::string getUserFullName();
    long getAmountOwed();//amount in cents
    void setAmountPaid(long amountPaid); //amount in cents
    void setUserFullName(std::string name);
    void setAmountOwed(long amountOwed); //amount in cents
    friend std::istream& operator>>(std::istream& ins, BarAttendee& person);
    //friend std::ostream& operator<<(std::ostream& outs, const BarAttendee& person);
};

int main()
{
    BarAttendee person1;
    /*std::ifstream userFileName;
    openInputFile(userFileName);*/

    std::cin >> person1;



    //userFileName.close();

}


void openInputFile(std::ifstream& inFile) {
    std::string fileName;
    std::cout << "What is the filename? ";
    std::cin >> fileName;
    inFile.open(fileName);
    while (!inFile) {
        std::cout << "FILE FAILED TO OPEN!" << std::endl;
        std::cout << "What is the filename? ";
        std::cin >> fileName;
        inFile.clear();
        inFile.open(fileName);
    }
}

int charDigitToInt(char digit) {
    int digitIntConv = 0;
    digitIntConv = digit - '0';
    return digitIntConv;
}


BarAttendee::BarAttendee() : amountPaidInCents(0), userFullName(""), amountOwedInCents(0) {
    //intentionally left empty
}

BarAttendee::BarAttendee(long amountPaidCents, std::string name = "") : amountPaidInCents(amountPaidCents), userFullName(name), amountOwedInCents(0) {
    //intentionally left empty
}

BarAttendee::BarAttendee(int dollars, int cents, std::string name) : userFullName(""), amountOwedInCents(0) {
    amountPaidInCents = (dollars * 100) + cents;
}

long BarAttendee::getAmountPaid() {
    //amount in cents
    return amountPaidInCents;
}
std::string BarAttendee::getUserFullName() {
    return userFullName;
}
long BarAttendee::getAmountOwed() {
    //amount in cents
    return amountOwedInCents;
}
void BarAttendee::setAmountPaid(long amountPaid) {
    //amount in cents
    amountPaidInCents = amountPaid;
}
void BarAttendee::setUserFullName(std::string name) {
    userFullName = name;
}
void BarAttendee::setAmountOwed(long amountOwed){
    //amount in cents
    amountOwedInCents = amountOwed;
}

std::istream& operator>>(std::istream& ins, BarAttendee& person) {
    int userDollars = 0;
    char punctPoint, digit1, digit2;
    std::string userFullName;
    

    //say to exit the loop must enter a pound sign
    while (ins >> userDollars) {
        std::cout << userDollars;
        if (ins >> punctPoint && punctPoint == '.') {
            std::cout << punctPoint;
            if (ins >> digit1) {
                int intDigit1;
                intDigit1 = charDigitToInt(digit1);
                std::cout << intDigit1;
                if (ins >> digit2) {
                    int intDigit2;
                    intDigit2 = charDigitToInt(digit2);
                    std::cout << intDigit2;
                }
            }

        }
        std::cout << std::endl;
        /*userFileName.ignore(9999, '\t')*/
        if (std::getline(ins, userFullName)) {
            int length = 0;
            std::string tempName;
            int frontWhiteSpaceCounter = 0;
            length = userFullName.length();
            int i = 0;
            while (!isalpha(userFullName[i])) {
                i++;
                frontWhiteSpaceCounter++;


            }
            for (frontWhiteSpaceCounter; frontWhiteSpaceCounter < length; frontWhiteSpaceCounter++) {
                tempName += userFullName[frontWhiteSpaceCounter];

            }
            userFullName = tempName;
        }

        std::cout << userFullName;

    }

    return ins;
}
//friend std::ostream& operator<<(std::ostream& outs, const BarAttendee& person);