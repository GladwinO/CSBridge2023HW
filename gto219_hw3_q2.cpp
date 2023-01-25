

#include <iostream>
#include <string>

int main()
{
	std::string userName;
	int gradYear, curYear, yearDif;

	
	std::cout << "Please enter your name: ";
	std::cin >> userName;
	std::cout << "Please enter your graduation year: ";
	std::cin >> gradYear;
	std::cout << "Please enter current year: "; 
	std::cin >> curYear;

	yearDif = gradYear - curYear;

	if (yearDif <= 0)
	{
		std::cout << userName << ", you have Graduated";
	}
	else if (yearDif == 1)
	{
		std::cout << userName << ", you are a Senior";

	}
	else if (yearDif == 2)
	{
		std::cout << userName << ", you are a Junior";
	}
	else if (yearDif == 3)
	{
		std::cout << userName << ", you are a Sophmore";
	}
	else if (yearDif == 4)
	{
		std::cout << userName << ", you are a Freshman";
	}
	else
	{
		std::cout << userName << ", you are not in college yet";
	}

}

