// gto219_hw13.cpp

#include <iostream>

class Organism {
private:
    char indicator;
    int rowPos;
    int colPos;

public:
    Organism();
    Organism(int curRowPos, int curColPos);
    Organism(char emptySpaceChar, int curRowPos, int curColPos);
    virtual void move(int curRowPos, int curColPos);
    char getIndic() const;
    int getRowPos() const;
    int getColPos() const;
    void setIndic(char userIndic);
    void setRowPos(int curRowPos);
    void setColPos(int curColPos);
    //virtual void breed()
};

class Ant : public Organism {
public: 
    Ant();
    Ant(int curRowPos, int curColPos);
    Ant(char antRepChar, int curRowPos, int curColPos); // can change the char that reps ant
    //needs virtual fucntion for move
    //need virtual function for breed
};

class Doodlebug : public Organism {
public:
    Doodlebug();
    Doodlebug(int curRowPos, int curColPos);
    Doodlebug(char doodlebugRepChar, int curRowPos, int curColPos);
};


int main()
{
    std::cout << "Hello World!\n";
}





///////////////// Organism Function Definitions //////////////////

Organism::Organism() : indicator('-'), rowPos(0), colPos(0) {
    //deliberately left empty
}

Organism::Organism(int curRowPos, int curColPos) : indicator('-'), rowPos(curRowPos), colPos(curColPos) {
    //deliberately left empty
}

Organism::Organism(char emptySpaceChar, int curRowPos, int curColPos) : indicator(emptySpaceChar), rowPos(curRowPos), colPos(curColPos) {
    //contructor option if the user wants to change the char that represents the empty space
}

void Organism::move(int curRowPos, int curColPos) {
    //currently do nothing 
    //
    //
    //
    //
    //
    //
}

char Organism::getIndic() const {
    return indicator;
}
int Organism::getRowPos() const {
    return rowPos;
}
int Organism::getColPos() const {
    return colPos;
}
void Organism::setIndic(char userIndic) {
    indicator = userIndic;
}
void Organism::setRowPos(int curRowPos) {
    rowPos = curRowPos;
}
void Organism::setColPos(int curColPos) {
    colPos = curColPos;
}


///////////////// Ant Function Definitions ////////////////// 

Ant::Ant() : Organism() {
    setIndic('O');
}
Ant::Ant(int curRowPos, int curColPos) : Organism(curRowPos, curColPos) {
    setIndic('O');
}
Ant::Ant(char antRepChar, int curRowPos, int curColPos) : Organism(antRepChar, curRowPos, curColPos) {
    //deliberately left empty
}




///////////////// Doodlebug Function Definitions //////////////////

Doodlebug::Doodlebug() : Organism() {
    setIndic('X');
}
Doodlebug::Doodlebug(int curRowPos, int curColPos) : Organism(curRowPos, curColPos) {
    setIndic('X');
}
Doodlebug::Doodlebug(char doodlebugRepChar, int curRowPos, int curColPos) : Organism(doodlebugRepChar, curRowPos, curColPos) {
    //deliberately left empty
}