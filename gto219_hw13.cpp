// gto219_hw13.cpp

#include <iostream>
#include <vector>
#include <string>

class Organism {
private:
    char indicator;
    int rowPos;
    int colPos;
    int numMoves;
    int timeSinceLastEaten;
public:
    Organism();
    Organism(int curRowPos, int curColPos);
    Organism(int curRowPos, int curColPos, int numMoves);
    Organism(int curRowPos, int curColPos, int numMoves, int timeSinceLastEaten);
    Organism(char emptySpaceChar, int curRowPos, int curColPos);
    Organism(const Organism& other);
    char getIndic() const;
    int getRowPos() const;
    int getColPos() const;
    int getNumMoves() const;
    int getTimeLastEaten() const;
    void setIndic(char userIndic);
    void setRowPos(int curRowPos);
    void setColPos(int curColPos);
    void setNumMoves(int curNumMoves);
    virtual void move(Organism* orgArr[][20]);
    virtual void breed(Organism* orgArr[][20]);
    virtual void starve(Organism* orgArr[][20]);
};

class Ant : public Organism {
public:
    Ant();
    Ant(int curRowPos, int curColPos);
    Ant(int curRowPos, int curColPos, int numMoves);
    Ant(int curRowPos, int curColPos, int numMoves, int timeSinceLastEaten);
    Ant(char antRepChar, int curRowPos, int curColPos); // can change the char that reps ant
    virtual void move(Organism* orgArr[][20]);
    virtual void breed(Organism* orgArr[][20]);
};

class Doodlebug : public Organism {
  
public:
    Doodlebug();
    Doodlebug(int curRowPos, int curColPos);
    Doodlebug(int curRowPos, int curColPos, int numMoves, int timeSinceLastEaten);
    Doodlebug(char doodlebugRepChar, int curRowPos, int curColPos);
    //to be used only during the initalization of a doodlebug
    virtual void move(Organism* orgArr[][20]);
    void starve(Organism* orgArr[][20]);
};


int main()
{
    const int numAnts = 100;
    const int numDoodle = 5;
    const int orgTotLen = 20;
    const int orgTotWid = 20;
    int timeSteps = 0;
    std::vector<Ant*> antVec(numAnts);
    std::vector<Doodlebug*> doodleVec(numDoodle);
    Organism* orgArr[orgTotLen][orgTotWid];
    for (int i = 0; i < numAnts; i++) {
        antVec[i] = new Ant;
    }

    for (int i = 0; i < numDoodle; i++) {
        doodleVec[i] = new Doodlebug;
    }

    for (int i = 0; i < orgTotLen; i++) {
        for (int j = 0; j < orgTotWid; j++) {
            orgArr[i][j] = new Organism;

        }

    }

    for (int i = 0; i < numDoodle; i++) {
        int xLoc = rand() % 20;
        int yLoc = rand() % 20;

        if (orgArr[xLoc][yLoc]->getIndic() == '-') {
            doodleVec[i]->setRowPos(xLoc);
            doodleVec[i]->setColPos(yLoc);
            orgArr[xLoc][yLoc] = doodleVec[i];

        }
        else {
            i--;
        }
    }

    for (int i = 0; i < numAnts; i++) {
        int xLoc = rand() % 20;
        int yLoc = rand() % 20;

        if (orgArr[xLoc][yLoc]->getIndic() == '-') {
            antVec[i]->setRowPos(xLoc);
            antVec[i]->setColPos(yLoc);
            orgArr[xLoc][yLoc] = antVec[i];

        }
        else {
            i--;
        }
    }

    std::cout << "Current timesteps: " << timeSteps << std::endl;
    //used to print out the "world"
    for (int i = 0; i < orgTotLen; i++) {
        for (int j = 0; j < orgTotWid; j++) {
            std::cout << orgArr[i][j]->getIndic();
            //will print out the initial list of organism
        }
        std::cout << "\n";
    }

    std::string userInput;
    std::cout << "Press enter to continue...";
    std::getline(std::cin, userInput);
    while (userInput.empty()) {
        for (int i = 0; i < orgTotLen; i++) {
            for (int j = 0; j < orgTotWid; j++) {
                if (orgArr[i][j]->getIndic() == 'X') {
                    if (orgArr[i][j]->getTimeLastEaten() < 3) {
                        orgArr[i][j]->move(orgArr);
                    }
                    else {
                        orgArr[i][j]->starve(orgArr);
                    }

                }
            }
            
        }
        for (int i = 0; i < orgTotLen; i++) {
            for (int j = 0; j < orgTotWid; j++) {
                if (orgArr[i][j]->getIndic() == 'o') {
                    orgArr[i][j]->move(orgArr);
                }
            }

        }
        for (int i = 0; i < orgTotLen; i++) {
            for (int j = 0; j < orgTotWid; j++) {
                std::cout << orgArr[i][j]->getIndic();
                //will print out the initial list of organism
            }
            std::cout << "\n";
        }
        std::cout << "Press enter to continue...";
        std::getline(std::cin, userInput);
    }





}





///////////////// Organism Function Definitions //////////////////

Organism::Organism() : indicator('-'), rowPos(0), colPos(0), numMoves(0), timeSinceLastEaten(0) {
    //deliberately left empty
}

Organism::Organism(int curRowPos, int curColPos) : indicator('-'), rowPos(curRowPos), colPos(curColPos), numMoves(0), timeSinceLastEaten(0) {
    //deliberately left empty
}

Organism::Organism(char emptySpaceChar, int curRowPos, int curColPos) : indicator(emptySpaceChar), rowPos(curRowPos), colPos(curColPos), numMoves(0), timeSinceLastEaten(0) {
    //contructor option if the user wants to change the char that represents the empty space
}

Organism::Organism(int curRowPos, int curColPos, int numMoves) : indicator('-'), rowPos(curRowPos), colPos(curColPos), numMoves(numMoves), timeSinceLastEaten(0) {
    //deliberately left empty
}

Organism::Organism(int curRowPos, int curColPos, int numMoves, int timeSinceLastEaten) : indicator('-'), rowPos(curRowPos), colPos(curColPos), numMoves(numMoves), timeSinceLastEaten(timeSinceLastEaten) {
    //deliberately left empty
}

Organism::Organism(const Organism& other) : indicator(other.indicator), rowPos(other.rowPos), colPos(other.colPos), numMoves(other.numMoves), timeSinceLastEaten(other.timeSinceLastEaten) {
    //deliberately left empty
}

void Organism::starve(Organism* orgArr[][20]) {
    //does nothing
}

void Organism::move(Organism* orgArr[][20]) {
   //deliberately left empty
}
void Organism::breed(Organism* orgArr[][20]) {
    //deliberately left empty
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
int Organism::getNumMoves() const {
    return numMoves;
}
int Organism::getTimeLastEaten() const {
    return timeSinceLastEaten;
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
void Organism::setNumMoves(int curNumMoves) {
    numMoves = curNumMoves;
}


///////////////// Ant Function Definitions ////////////////// 

Ant::Ant() : Organism() {
    setIndic('o');
}
Ant::Ant(int curRowPos, int curColPos) : Organism(curRowPos, curColPos) {
    setIndic('o');
}
Ant::Ant(int curRowPos, int curColPos, int numMoves) : Organism(curRowPos, curColPos, numMoves) {
    setIndic('o');
}
Ant::Ant(char antRepChar, int curRowPos, int curColPos) : Organism(antRepChar, curRowPos, curColPos) {
    //deliberately left empty
}
Ant::Ant(int curRowPos, int curColPos, int numMoves, int timeSinceLastEaten) : Organism(curRowPos, curColPos, numMoves, timeSinceLastEaten) {
    setIndic('o');
}

void Ant::move(Organism* orgArr[][20]) {
    int randNum = 0;
    int initX = this->getRowPos();
    int initY = this->getColPos();
    int numMoves = this->getNumMoves();
    numMoves++;
    randNum = (std::rand() % 4) + 1;
    // 1 is up, 2 is down, 3 is left, 4 is right
    switch (randNum) {
    case 1:
        if ((initX - 1) > 0 && (initX - 1) < 20) {
            if (orgArr[initX - 1][initY]->getIndic() == '-') {
                setRowPos(initX - 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Ant(getRowPos(), initY, numMoves);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;


            }
        }
        break;
    case 2:
        if ((initX + 1) > 0 && (initX + 1) < 20) {
            if (orgArr[initX + 1][initY]->getIndic() == '-') {
                setRowPos(initX + 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Ant(getRowPos(), initY, numMoves);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;


            }
        }
        break;
    case 3:
        if ((initY - 1) > 0 && (initY - 1) < 20) {
            if (orgArr[initX][initY - 1]->getIndic() == '-') {
                setColPos(initY - 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Ant(initX, getColPos(), numMoves);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
            }
        }
        break;
    case 4:
        if ((initY + 1) > 0 && (initY + 1) < 20) {
            if (orgArr[initX][initY + 1]->getIndic() == '-') {
                setColPos(initY + 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Ant(initX, getColPos(), numMoves);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
            }
        }
        break;
    }

}
void Ant::breed(Organism* orgArr[][20]) {
    int initX = getRowPos();
    int initY = getRowPos();
    orgArr[initX][initY]->setNumMoves(0);
    
    
    if ((initX - 1) > 0 && (initX - 1) < 20) {
        if (orgArr[initX - 1][initY]->getIndic() == '-') {
            delete orgArr[initX - 1][initY];
            orgArr[initX - 1][initY] = new Ant(initX - 1, initY);


        }
    }
    else if ((initX + 1) > 0 && (initX + 1) < 20) {
        if (orgArr[initX + 1][initY]->getIndic() == '-') {
            delete orgArr[initX + 1][initY];
            orgArr[initX + 1][initY] = new Ant(initX + 1, initY);


        }
    }
    else if ((initY - 1) > 0 && (initY - 1) < 20) {
        if (orgArr[initX][initY - 1]->getIndic() == '-') {
            delete orgArr[initX][initY - 1];
            orgArr[initX][initY - 1] = new Ant(initX, initY - 1);
        }
    }
    else if ((initY + 1) > 0 && (initY + 1) < 20) {
        if (orgArr[initX][initY + 1]->getIndic() == '-') {
            delete orgArr[initX][initY + 1];
            orgArr[initX][initY + 1] = new Ant(initX, initY + 1);
        }
    }
      
 
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
Doodlebug::Doodlebug(int curRowPos, int curColPos, int numMoves, int timeSinceLastEaten) : Organism(curRowPos, curColPos, numMoves, timeSinceLastEaten) {
    setIndic('X');
}

void Doodlebug::move(Organism* orgArr[][20]) {
    int randNum = 0;
    int initX = this->getRowPos();
    int initY = this->getColPos();
    int numMoves = this->getNumMoves();
    int lastEaten = this->getTimeLastEaten();
    numMoves++;
    lastEaten++;
    if (orgArr[initX - 1][initY]->getIndic() == 'o' && orgArr[initX + 1][initY]->getIndic() != 'o' && orgArr[initX][initY - 1]->getIndic() != 'o' && orgArr[initX][initY + 1]->getIndic() != 'o') {
        if ((initX - 1) > 0 && (initX - 1) < 20) {
            setRowPos(initX - 1);
            delete orgArr[getRowPos()][initY];
            orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
            delete orgArr[initX][initY];
            orgArr[initX][initY] = new Organism;

        }

    }
    else if (orgArr[initX + 1][initY]->getIndic() == 'o' && orgArr[initX - 1][initY]->getIndic() != 'o' && orgArr[initX][initY - 1]->getIndic() != 'o' && orgArr[initX][initY + 1]->getIndic() != 'o') {
        if ((initX + 1) > 0 && (initX + 1) < 20) {
            setRowPos(initX + 1);
            delete orgArr[getRowPos()][initY];
            orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
            delete orgArr[initX][initY];
            orgArr[initX][initY] = new Organism;
        }
    }
    else if (orgArr[initX][initY - 1]->getIndic() == 'o' && orgArr[initX - 1][initY]->getIndic() != 'o' && orgArr[initX + 1][initY]->getIndic() != 'o' && orgArr[initX][initY + 1]->getIndic() != 'o') {
        if ((initY - 1) > 0 && (initY - 1) < 20) {
            setColPos(initY - 1);
            delete orgArr[initX][getColPos()];
            orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
            delete orgArr[initX][initY];
            orgArr[initX][initY] = new Organism;
        }
    }
    else if (orgArr[initX][initY + 1]->getIndic() == 'o' && orgArr[initX - 1][initY]->getIndic() != 'o' && orgArr[initX + 1][initY]->getIndic() != 'o' && orgArr[initX][initY - 1]->getIndic() != 'o') {
        if ((initY + 1) > 0 && (initY + 1) < 20) {
            setColPos(initY + 1);
            delete orgArr[initX][getColPos()];
            orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
            delete orgArr[initX][initY];
            orgArr[initX][initY] = new Organism;
        }
    }
    else if (orgArr[initX][initY + 1]->getIndic() == 'o' && orgArr[initX - 1][initY]->getIndic() != 'o' && orgArr[initX + 1][initY]->getIndic() != 'o' && orgArr[initX][initY - 1]->getIndic() != 'o') {
        if ((initY + 1) > 0 && (initY + 1) < 20) {
            setColPos(initY + 1);
            delete orgArr[initX][getColPos()];
            orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
            delete orgArr[initX][initY];
            orgArr[initX][initY] = new Organism;
        }
    }
    else if (orgArr[initX][initY + 1]->getIndic() == 'o' && orgArr[initX - 1][initY]->getIndic() == 'o' && orgArr[initX + 1][initY]->getIndic() != 'o' && orgArr[initX][initY - 1]->getIndic() != 'o') {
        if (((initY + 1) > 0 && (initY + 1) < 20) && ((initX - 1) > 0 && (initX - 1) < 20)) {
            randNum = (std::rand() % 2) + 1;
            //1 is up, 2 is right
            switch (randNum) {
            case 1:
                setRowPos(initX - 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 2:
                setColPos(initY + 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            }

        }
    }
    else if (orgArr[initX][initY - 1]->getIndic() == 'o' && orgArr[initX - 1][initY]->getIndic() == 'o' && orgArr[initX + 1][initY]->getIndic() != 'o' && orgArr[initX][initY + 1]->getIndic() != 'o') {
        if (((initY - 1) > 0 && (initY - 1) < 20) && ((initX - 1) > 0 && (initX - 1) < 20)) {
            randNum = (std::rand() % 2) + 1;
            //1 is up, 2 is left
            switch (randNum) {
            case 1:
                setRowPos(initX - 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 2:
                setColPos(initY - 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            }

        }
    }
    else if (orgArr[initX][initY + 1]->getIndic() != 'o' && orgArr[initX - 1][initY]->getIndic() == 'o' && orgArr[initX + 1][initY]->getIndic() == 'o' && orgArr[initX][initY - 1]->getIndic() != 'o') {
        if (((initX + 1) > 0 && (initX + 1) < 20) && ((initX - 1) > 0 && (initX - 1) < 20)) {
            randNum = (std::rand() % 2) + 1;
            //1 is up, 2 is down
            switch (randNum) {
            case 1:
                setRowPos(initX - 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 2:
                setRowPos(initX + 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            }

        }
    }
    else if (orgArr[initX][initY + 1]->getIndic() != 'o' && orgArr[initX - 1][initY]->getIndic() != 'o' && orgArr[initX + 1][initY]->getIndic() == 'o' && orgArr[initX][initY - 1]->getIndic() == 'o') {
        if (((initX + 1) > 0 && (initX + 1) < 20) && ((initY - 1) > 0 && (initY - 1) < 20)) {
            randNum = (std::rand() % 2) + 1;
            //1 is left, 2 is down
            switch (randNum) {
            case 1:
                setColPos(initY - 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 2:
                setRowPos(initX + 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            }

        }

    }
    else if (orgArr[initX][initY + 1]->getIndic() == 'o' && orgArr[initX - 1][initY]->getIndic() != 'o' && orgArr[initX + 1][initY]->getIndic() == 'o' && orgArr[initX][initY - 1]->getIndic() != 'o') {
        if (((initX + 1) > 0 && (initX + 1) < 20) && ((initY + 1) > 0 && (initY + 1) < 20)) {
            randNum = (std::rand() % 2) + 1;
            //1 is right, 2 is down
            switch (randNum) {
            case 1:
                setColPos(initY + 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 2:
                setRowPos(initX + 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            }

        }

    }
    else if (orgArr[initX][initY + 1]->getIndic() == 'o' && orgArr[initX - 1][initY]->getIndic() != 'o' && orgArr[initX + 1][initY]->getIndic() != 'o' && orgArr[initX][initY - 1]->getIndic() == 'o') {
        if (((initY - 1) > 0 && (initY - 1) < 20) && ((initY + 1) > 0 && (initY + 1) < 20)) {
            randNum = (std::rand() % 2) + 1;
            //1 is right, 2 is left
            switch (randNum) {
            case 1:
                setColPos(initY + 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 2:
                setColPos(initY - 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            }

        }

    }
    else if (orgArr[initX][initY + 1]->getIndic() == 'o' && orgArr[initX - 1][initY]->getIndic() == 'o' && orgArr[initX + 1][initY]->getIndic() != 'o' && orgArr[initX][initY - 1]->getIndic() == 'o') {
        if (((initY - 1) > 0 && (initY - 1) < 20) && ((initY + 1) > 0 && (initY + 1) < 20) && ((initX - 1) > 0 && (initX - 1) < 20)) {
            randNum = (std::rand() % 3) + 1;
            //1 is right, 2 is left, 3 is up
            switch (randNum) {
            case 1:
                setColPos(initY + 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 2:
                setColPos(initY - 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 3:
                setRowPos(initX - 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            }

        }

    }
    else if (orgArr[initX][initY + 1]->getIndic() == 'o' && orgArr[initX - 1][initY]->getIndic() != 'o' && orgArr[initX + 1][initY]->getIndic() == 'o' && orgArr[initX][initY - 1]->getIndic() == 'o') {
        if (((initY - 1) > 0 && (initY - 1) < 20) && ((initY + 1) > 0 && (initY + 1) < 20) && ((initX + 1) > 0 && (initX + 1) < 20)) {
            randNum = (std::rand() % 3) + 1;
            //1 is right, 2 is left, 3 is down
            switch (randNum) {
            case 1:
                setColPos(initY + 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 2:
                setColPos(initY - 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 3:
                setRowPos(initX + 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            }

        }

    }
    else if (orgArr[initX][initY + 1]->getIndic() != 'o' && orgArr[initX - 1][initY]->getIndic() == 'o' && orgArr[initX + 1][initY]->getIndic() == 'o' && orgArr[initX][initY - 1]->getIndic() == 'o') {
        if (((initX + 1) > 0 && (initX + 1) < 20) && ((initX - 1) > 0 && (initX - 1) < 20) && ((initY - 1) > 0 && (initY - 1) < 20)) {
            randNum = (std::rand() % 3) + 1;
            //1 is up, 2 is down, 3 is left
            switch (randNum) {
            case 1:
                setRowPos(initX - 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 2:
                setRowPos(initX + 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 3:
                setColPos(initY - 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            }

        }
    }
    else if (orgArr[initX][initY + 1]->getIndic() == 'o' && orgArr[initX - 1][initY]->getIndic() == 'o' && orgArr[initX + 1][initY]->getIndic() == 'o' && orgArr[initX][initY - 1]->getIndic() != 'o') {
        if (((initX + 1) > 0 && (initX + 1) < 20) && ((initX - 1) > 0 && (initX - 1) < 20) && ((initY + 1) > 0 && (initY + 1) < 20)) {
            randNum = (std::rand() % 3) + 1;
            //1 is up, 2 is down, 3 is right
            switch (randNum) {
            case 1:
                setRowPos(initX - 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 2:
                setRowPos(initX + 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 3:
                setColPos(initY + 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            }

        }
    }
    else if (orgArr[initX][initY + 1]->getIndic() == 'o' && orgArr[initX - 1][initY]->getIndic() == 'o' && orgArr[initX + 1][initY]->getIndic() == 'o' && orgArr[initX][initY - 1]->getIndic() == 'o') {
        if (((initX + 1) > 0 && (initX + 1) < 20) && ((initX - 1) > 0 && (initX - 1) < 20) && ((initY - 1) > 0 && (initY - 1) < 20) && ((initY + 1) > 0 && (initY + 1) < 20)) {
            randNum = (std::rand() % 4) + 1;
            //1 is up, 2 is down, 3 is left, 4 is right
            switch (randNum) {
            case 1:
                setRowPos(initX - 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 2:
                setRowPos(initX + 1);
                delete orgArr[getRowPos()][initY];
                orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 3:
                setColPos(initY - 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            case 4:
                setColPos(initY + 1);
                delete orgArr[initX][getColPos()];
                orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, 0);
                delete orgArr[initX][initY];
                orgArr[initX][initY] = new Organism;
                break;
            }

        }
    }
    else {
        randNum = (std::rand() % 4) + 1;
        // 1 is up, 2 is down, 3 is left, 4 is right
        switch (randNum) {
        case 1:
            if ((initX - 1) > 0 && (initX - 1) < 20) {
                if (orgArr[initX - 1][initY]->getIndic() == '-') {
                    setRowPos(initX - 1);
                    delete orgArr[getRowPos()][initY];
                    orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, lastEaten);
                    delete orgArr[initX][initY];
                    orgArr[initX][initY] = new Organism;


                }
            }
            break;
        case 2:
            if ((initX + 1) > 0 && (initX + 1) < 20) {
                if (orgArr[initX + 1][initY]->getIndic() == '-') {
                    setRowPos(initX + 1);
                    delete orgArr[getRowPos()][initY];
                    orgArr[getRowPos()][initY] = new Doodlebug(getRowPos(), initY, numMoves, lastEaten);
                    delete orgArr[initX][initY];
                    orgArr[initX][initY] = new Organism;


                }
            }
            break;
        case 3:
            if ((initY - 1) > 0 && (initY - 1) < 20) {
                if (orgArr[initX][initY - 1]->getIndic() == '-') {
                    setColPos(initY - 1);
                    delete orgArr[initX][getColPos()];
                    orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, lastEaten);
                    delete orgArr[initX][initY];
                    orgArr[initX][initY] = new Organism;
                }
            }
            break;
        case 4:
            if ((initY + 1) > 0 && (initY + 1) < 20) {
                if (orgArr[initX][initY + 1]->getIndic() == '-') {
                    setColPos(initY + 1);
                    delete orgArr[initX][getColPos()];
                    orgArr[initX][getColPos()] = new Doodlebug(initX, getColPos(), numMoves, lastEaten);
                    delete orgArr[initX][initY];
                    orgArr[initX][initY] = new Organism;
                }
            }
            break;
        }
    }
}
void Doodlebug::starve(Organism* orgArr[][20]) {
    delete orgArr[getRowPos()][getColPos()];
    orgArr[getRowPos()][getColPos()] = new Organism;
}