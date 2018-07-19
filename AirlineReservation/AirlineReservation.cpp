// AirlineReservation.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <iomanip> 
#include "flight.h"
#include "Reservation.h"
#include "scheduleManager.h"
#include "Utils.h"



using namespace std;
using namespace AirlineReservation;

void displayFlightMenuSelected(ScheduleManager& scheduleManager);
int displayMainMenu();
void displaySearchOptionSelected(ScheduleManager& scheduleManager);
void displayFlights(vector<Flight> & flights);
bool inputDate();
void pauseAndClear();

int main()
{

	Reservation reservation;
	int reservationId; //for looking up ticket to display and check-in
	ScheduleManager scheduleManager;

	int optionSelectedM;
	while (1) {

		int optionSelectedM = displayMainMenu();
		switch (optionSelectedM) {
		case 1:
			displaySearchOptionSelected(scheduleManager);
			break;
		case 2:
			cout << "Reserving Flight" << endl;
			reservation = ScheduleManager::reserveFlight();
			//display the reservation
			reservation.display();
			break;
		case 3:
			cout << "Enter your reservation number to check-in for your flight: " << endl;
			cin >> reservationId;
			scheduleManager.passengerCheckin(reservationId);
			break;
		case 4:
			cout << "OPtion 3 Selected" << endl;
			break;
		case 5:
			cout << "Option 5 Selected" << endl;
			for (int i = 0; i < 5; i++) {
				scheduleManager.dummyFlightInformation();
			}
			displayFlightMenuSelected(scheduleManager);

			break;
		case 6:
			cout << "Enter your reservation number to display your ticket: " << endl;
			cin >> reservationId;

			scheduleManager.displayTicket(reservationId);


			break;
		case 0:
			return 0;
		default:
			cout << "Default Selected" << endl;
			break;
		}

		/*system("CLS");
		cout<< flush;*/

	}
	return 0;
}

int displayMainMenu() {
	int optionSelected;
	cout << "_____________________________________________________________________" << endl << endl;
	cout << "                       K A L'S    A I R L I N E         " << endl;
	cout << "_____________________________________________________________________" << endl << endl << endl;
	cout << "	  1.-Search Flight Schedule" << endl;
	cout << "	  2.-Reserve Flight" << endl;
	cout << "	  3.-Flight Check-In " << endl;
	cout << "	  4.-Search Reservation" << endl;
	cout << "	  5.-Flight Information" << endl;
	cout << "	  6.-Display Ticket" << endl;
	cout << "	  0.-Exit" << endl << endl;
	cout << "_____________________________________________________________________" << endl << endl;
	cout << " Please select an  option >> ";
	cin >> optionSelected;
	return optionSelected;
}


void displayFlightMenuSelected(ScheduleManager& scheduleManager) {
	int flightMenuOption;
	int flightId;
	system("CLS");
	cout << flush;
	while (true) {
		cout << "_____________________________________________________________________" << endl << endl;
		cout << "                       K A L'S    A I R L I N E         " << endl;
		cout << "_____________________________________________________________________" << endl << endl;
		cout << "    F L I G H T  I N F O R M A T I O N       " << endl << endl << endl;


		cout << " 1 - Add Flight  " << endl;
		cout << " 2 - Delete Flight " << endl;
		cout << " 3 - Display All Flights Details" << endl;
		cout << " 0 - To Go Back to Main Menu" << endl;
		cout << "_____________________________________________________________________" << endl << endl;
		cout << " Please Select Option ";
		cin >> flightMenuOption;

		switch (flightMenuOption) {

		case 1:
			scheduleManager.addFlightInformation();
			break;
		case 2:
			cout << "Enter the FlightId" << endl;
			cin >> flightId;
			scheduleManager.deleteFlight(flightId);
			break;
		case 3:
			cout << "Displaying All Flights Information " << endl;
			scheduleManager.displayAllFlights();
			pauseAndClear();
			break;
		case 0:
			system("CLS");
			return;
		default:
			cout << " Enter Correct Option" << endl;
			break;
		}
	}
}

void displaySearchOptionSelected(ScheduleManager& scheduleManager) {
	system("CLS");
	scheduleManager.uploadFlightsFromSource();
	cout << flush;
	cout << "_____________________________________________________________________" << endl << endl;
	cout << "                       K A L'S    A I R L I N E         " << endl;
	cout << "_____________________________________________________________________" << endl << endl;
	cout << "    S E A R C H      F L I G H T         " << endl << endl << endl;

	string departure = "";
	string destination = "";
	string departingDate;
	/*int departingMonth;
	int departingDay;
	int departingYear;
	
	string arrivingTime;
	string anyStr;
	int menuOption;*/

	try {

		cout << "Fying from: >>  ";
		//	getline(cin, departure);
		cin >> departure;
		cout << endl << "Flying to: >>  ";
		//getline(cin, destination);
		cin >> destination;
		/*cout << "Fying from:" << departure;
		cout << "Flying to:" << destination;*/
		cout << endl << "Departing Date(MM/DD/YY):  >>  ";
		//cin >> departingDate;
		if (!inputDate()) {
			/*cout << "Date entered is Invalid";
			cout << "Press 1 to continue";
			cin >> menuOption;*/

			/*switch (menuOption) {
			case 1:

				break;
			case 2:

				break;
			}*/
		}
		else {
			vector<Flight> FlightsFound = scheduleManager.searchFlights(departingDate, Utils::toUpper(departure), Utils::toUpper(destination));
			displayFlights(FlightsFound);
			pauseAndClear();
		}
	}
	catch (const std::logic_error& exception) {
		cerr << "Unable to do the Search: " << exception.what() << endl;
		pauseAndClear();


	}

}

void displayFlights(vector<Flight> &flights) {
	cout << endl << endl;
	cout << "F L I G H T S        " << endl;
	cout << "___________________________________________________________________________________________________________________" << endl << endl;
	cout << setw(8) << "NUMBER" << setw(15) << "DATE" << setw(15) << "DEPART TIME"
		<< setw(15) << "ARRIVAL TIME" << setw(12) << "DEPARTURE" << setw(10) << "ARRIVAL" << setw(20) << "DEPART AIRPORT" << setw(22) << "ARRIVAL AIRPORT\n";
	cout << "___________________________________________________________________________________________________________________" << endl << endl;
	for (const auto& flight : flights) {
		flight.displayFlight();
	}
	cout << endl << "___________________________________________________________________________________________________________________" << endl << endl;
}

bool inputDate() {
	int month;
	int day;
	int year;
	//	try {
	cin >> month; // read the day
	if (std::cin.get() != '/') // make sure there is a slash between DD and MM
	{
		std::cout << "expected / after Month \n";
	}
	std::cin >> day; // read the month
	if (std::cin.get() != '/') // make sure there is a slash between MM and YYYY
	{
		std::cout << "expected / after Day\n";

	}
	std::cin >> year; // read the year


	return Utils::isValidDate(month, day, year);

	//	}
		/*catch (const std::logic_error& exception) {
			cerr << "Unable to do the Search: " << exception.what() << endl;
			cerr << "Press 1 to continue";
		}*/

}

void pauseAndClear() {
	cin.clear();
	system("PAUSE");
	cout << endl <<endl << "Press any key to continue...";
	system("CLS");
}
