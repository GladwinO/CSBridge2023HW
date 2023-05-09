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
        while(!isEmpty()) {
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

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
