#include <iostream>
#include <string>
using namespace std;

int main()
{
	string strDay, strTime, strHour, strMinut, strCallMinut, userEntry;
	int colonLoc;
	int callMinut;
	int hour, minut, hourAddMinut;
	int spaceLoc, startIndexPos, subStrLen; 
	int hourScaleConv;
	double callCost;
	const double monToFriMidDayCharge = 0.40;
	const double monToFriMornorEvenCharge = 0.25;
	const double weekendCharge = 0.25;

	cout << "Please enter the day of the week as: Mo, Tu, We, Th, Fr, Sa, Su" << endl;
	cout << "The time the call started (ex: 13:00)" << endl;
	cout << "The length of the call in minutes.\n With each entry separated by a space" <<endl;
	cout << "Ex: Mo 13:59 45" << endl;
	
	getline(cin >> ws, userEntry);

	
	spaceLoc = userEntry.find(" ");
	strDay = userEntry.substr(0, spaceLoc);

	startIndexPos = spaceLoc + 1;
	spaceLoc = userEntry.find(" ", spaceLoc + 1);
	subStrLen = spaceLoc - startIndexPos;
	strTime = userEntry.substr(startIndexPos, subStrLen);
	

	startIndexPos = spaceLoc + 1;
	strCallMinut = userEntry.substr(startIndexPos);
	

	colonLoc = strTime.find(":");
	strHour = strTime.substr(0, colonLoc);
	strMinut = strTime.substr(colonLoc + 1);

	callMinut = stoi(strCallMinut);
	hour = stoi(strHour);
	minut = stoi(strMinut);
	hourScaleConv = hour * 100; //done to scale hour to thousands 13 -> 1300
	hourAddMinut = hourScaleConv + minut;

	


	if (strDay == "Sa" || strDay == "Su")
	{
		callCost = weekendCharge * callMinut;
		cout << "Total phone call cost: $" << callCost << endl;
	}
	else if (strDay == "Mo" || strDay == "Tu" || strDay == "We" || strDay == "Th" || strDay == "Fr")
	{
		//could use else instead of else if, assuming the user will not input an incorrect input
		if (hourAddMinut >= 800 && hourAddMinut <= 1800)
		{
			callCost = monToFriMidDayCharge * callMinut;
			cout << "Total phone call cost: $" << callCost << endl;
		}
		else
		{
			callCost = monToFriMornorEvenCharge * callMinut;
			cout << "Total phone call cost: $" << callCost << endl;
		}
	}
	else
	{
		cout << "You have entered an incorrect day" << endl;
	}
	

}
