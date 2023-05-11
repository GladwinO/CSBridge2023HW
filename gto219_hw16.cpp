// gto219_hw16.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>

template<class T>
class Queue {
private:
    std::vector<T> vecList;
    int startPos = 0;
    int endPos = 0;
public:
    void enqueue(T newitem) {
        vecList.push_back(newitem);
    }
    T dequeue() {
        if (size() > startPos) {
            startPos++;
            return vecList[startPos - 1]
        }
        if (startPos == (size()) {
            clear();
        }
        if (size() == 1) {
            return vecList[startPos];
        }
    }
    T top() {
        return vecList[startPos];
    }
    bool isEmpty() const {
        return vecList.size() == 0;
    }
    int size() {
        return vecList.size();
    }
    void clear() {
        while (!isEmpty()) {
            vecList.pop_back();
        }
    }
};

void openInputFile(std::ifstream& inFile);

int main()
{
    std::ifstream userInputFile;
    openInputFile(userInputFile);
    std::string userInputLine;
    while (std::getline(userInputFile, userInputLine)) {
        std::string begin, pascChars, end;
        char whiteSpacePos = userInputLine.find(' ');
        while (whiteSpacePos != std::string::npos) {

        }

    }

}

void openInputFile(std::ifstream& inFile) {
    std::string fileName;
    std::cout << "What is the filename?" << std::endl;
    std::cin >> fileName;
    inFile.open(fileName);
    while (!inFile) {
        std::cout << "FILE FAILED TO OPEN!" << std::endl;
        std::cout << "What is the filename?" << std::endl;
        std::cin >> fileName;
        inFile.clear();
        inFile.open(fileName);
    }
}
