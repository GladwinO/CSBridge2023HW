// gto219_hw10_q1.cpp 

#include <iostream>
#include <string>
#include <vector>



std::string* createWordsArray(std::string sentence, int& outWordsArrSize);
std::vector<int> findSpaceLoc(const std::string userString);

int main()
{
    //this code assumes that there are not any spaces at the beginning or end of the sentence.

    int numInputWords{ 0 };
    std::string inputString;
    std::string* inputWordsArray = nullptr;

    std::cout << "Please enter a sentence:" << std::endl;
    std::getline(std::cin, inputString);

    inputWordsArray = createWordsArray(inputString, numInputWords);

    std::cout << "There are " << numInputWords << " words in this sentence.\n"
        "These " << numInputWords << " words are listed below:" << std::endl;
    for (int i = 0; i < numInputWords; i++)
    {
        std::cout << inputWordsArray[i] << std::endl;
    }

    delete[] inputWordsArray;
    inputWordsArray = nullptr;
    return 0;
}

std::string* createWordsArray(std::string sentence, int& outWordsArrSize)
{
    std::vector<int> spaceLoc = findSpaceLoc(sentence);
    outWordsArrSize = spaceLoc.size() + 1;
    std::string* wordsArray = new std::string[outWordsArrSize];
    int startPos = 0;
    

    for (int i = 0; i < outWordsArrSize; i++)
    {
        if (i < outWordsArrSize - 1)
        {
            int subStrLen = spaceLoc[i] - startPos;
            wordsArray[i] = sentence.substr(startPos, subStrLen);
            startPos = spaceLoc[i] + 1;
        }
        else
        {
            wordsArray[i] = sentence.substr(startPos);
        }
        
    }

    return wordsArray;
}

std::vector<int> findSpaceLoc(const std::string userString)
{
    std::vector<int> spaceLoc;
    int spacePos = userString.find(' ');

    while (spacePos != std::string::npos)
    {
        spaceLoc.push_back(spacePos);
        spacePos = userString.find(' ', spacePos + 1);
    }
 
    return spaceLoc;
}


