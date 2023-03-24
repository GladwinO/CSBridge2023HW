// gto219_hw11_q1.cpp :

#include <iostream>

void printTriangle(int n);
void printOpositeTriangles(int n);
void printRuler(int n);

int main()
{
    int userNum;
    std::cout << "Please enter a number: ";
    std::cin >> userNum;
    std::cout << std::endl;
    //printTriangle(numLines);
    //printOpositeTriangles(numLines);
    printRuler(userNum);

}

void printTriangle(int n)
{
    if (n == 1)
    {
        std::cout << '*' << std::endl;
    }
    else
    {
        printTriangle(n - 1);
        for (int i = 0; i < n; i++)
        {
            std::cout << '*';
        }
        std::cout << "\n";
    }
   
}

void printOpositeTriangles(int n)
{
    if (n == 1)
    {
        std::cout << "*\n*" << std::endl;
        
    }
    else
    {
        for (int i = 0; i < n; i++)
        {
            std::cout << '*';
        }
        std::cout << "\n";
        printOpositeTriangles(n - 1);
        for (int i = 0; i < n; i++)
        {
            std::cout << '*';
        }
        std::cout << "\n";
    }
}

void printRuler(int n)
{
    if (n == 1)
    {
        std::cout << "-" << std::endl;
    }
    else
    {
        printRuler(n - 1);
        for (int i = 0; i < n; i++)
        {
            std::cout << "- ";
        }
        std::cout << "\n";
        if (n > 1)
        {
            printRuler(n / 2);
        }
    }
}
