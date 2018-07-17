// AirlineReservation.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <stdlib.h>
#include <iostream>
#include <string>
#include <sstream>

#include "scheduleManager.h"



using namespace std;
using namespace AirlineReservation;

void displayFlightMenuSelected(ScheduleManager& scheduleManager);

int main()
{

	int optionSelected;
	string departure = "";
	string destination="";
	string departingDate="";
	
	while (true) {

		ScheduleManager sm;
		
		cout << "*********************************************************************" << std::endl;
		cout << "            W E L C O M E     T O   K A L'S    A I R L I N E         " << endl;
		cout << "*********************************************************************" << endl << endl;
		cout << "   Please select an  option:" << endl;
		cout << "	  1.-Search Flight Schedule" << endl;
		cout << "	  2.-Reserve Flight" << endl;
		cout << "	  3.-Check-In " << endl;
		cout << "	  4.-Search Reservation" << endl;
		cout << "	  5.-Flight Information" << endl;
		cout << "	  0.-Exit" << endl;
		cout << "   Please select an  option: ";
		cin >> optionSelected;

		switch (optionSelected) {
		case 1:
			cout << "Fying from: ";
			cin >> departure;
			cout << "Flying to:";		
			cin >> destination;
			cout << "Departing Date: ";
			cin >> departingDate;		
			break;
		case 2:
			cout << "OPtion 2 Selected" << endl;
			break;
		case 3:
			cout << "OPtion 3 Selected" << endl;
			break;
		case 4:
			break;
		case 5:
			cout << "Option 5 Selected" << endl;
			for(int i=0;i<5;i++){
				sm.addFlightInformation();
			}
			displayFlightMenuSelected(sm);
			
		
			break;
		case 0:
			return 0;
			//break;
		default:
			cout << "Default Selected" << endl;
			break;
		}
		
		/*cout<< flush;*/
		//system("CLS");
	}
	
	return 0;
}

void displayFlightMenuSelected(ScheduleManager& scheduleManager) {
	

	int flightMenuOption;
	while (true) {
		cout << " ****************Flight Information ****************" << endl;

		cout << " 1 - Add Flight  " << endl;
		cout << " 2 - Delete Flight " << endl;
		cout << " 3 - Display All Flights Details" << endl;
		cout << " 0 - To Go Back to Main Menu" << endl;
		cout << " Please Select Option ";
		cin >> flightMenuOption;

		switch (flightMenuOption) {

		case 1:
			scheduleManager.addFlightInformation();
			cout << " Added Flight Details" << endl;
			break;
		case 2:
			cout << " Delete Flight " << endl;
			break;
		case 3:
			cout << "Displaying All Flights Information " << endl;
			scheduleManager.displayAllFlights();
			break;
		case 0:
			return;

		default:
			cout << " Enter Correct Option" << endl;
			break;
		}
	}
}
