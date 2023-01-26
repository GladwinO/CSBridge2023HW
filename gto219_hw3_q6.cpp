#include <iostream>
#include <string>
using namespace std;

int main()
{
	string day, time, strHour, strMinut;
	int colonLoc;
	int callMinut;
	int hour, minut, hourAddMinut;
	double callCost;
	const double monToFriMidDayCharge = 0.40;
	const double monToFriMornorEvenCharge = 0.25;
	const double weekendCharge = 0.25;

	cout << "Please enter the day of the week as: \nMo \nTu \nWe \nTh \nFr \nSa \nSu\n";
	cin >> day;
	cout << "Please enter the time the call started (ex: 13:00): ";
	cin >> time;
	cout << "Please enter the length of the call in minutes: ";
	cin >> callMinut;


	colonLoc = time.find(":");
	strHour = time.substr(0, colonLoc);
	strMinut = time.substr(colonLoc + 1);

	hour = stoi(strHour);
	minut = stoi(strMinut);
	hourAddMinut = hour + minut;


	if (day == "Sa" || day == "Su")
	{
		callCost = weekendCharge * callMinut;
		cout << "Total phone call cost: $" << callCost << endl;
	}
	else
	{
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

}
