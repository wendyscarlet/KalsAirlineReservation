// AirlineReservation.cpp : Defines the entry point for the console application.
//
#include "stdafx.h"
#include <iostream>
#include <string>
#include <sstream>
#include "flight.h"
#include "Passenger.h"
#include "scheduleManager.h"
#include <vector>
using namespace std;


int main()
{

	int optionSelected;
	string departure = "";
	string destination = "";
	string departingDate = "";
	int pid=-1;
	string pfname, plname, paddress, pcity, pstate, pzipcode, pphonenumber, pemailaddress;
	Passenger p;
	Flight f;
	vector<Flight> AllFlights;
	vector<Passenger> AllPassengers;

	while (1) {
		std::cout << "*********************************************************************" << std::endl;
		cout << "            W E L C O M E     T O   K A L'S    A I R L I N E         " << endl;
		cout << "*********************************************************************" << endl << endl;
		cout << "   Please select an  option:" << endl;
		cout << "	  1.-Search Flight Schedule" << endl;
		cout << "	  2.-Reserve Flight" << endl;
		cout << "	  3.-Check-In " << endl;
		cout << "	  4.-Search Reservation" << endl;
		cout << "	  0.-Exit" << endl;
		cout << "   Please select an  option: ";
		cin >> optionSelected;

		switch(optionSelected) {
		case 1:
			cout << "Flying from: ";
			cin >> departure;
			cout << "Flying to:";
			cin >> destination;
			cout << "Departing Date: ";
			cin >> departingDate;
			break;
		case 2:
			cout << "Reserving Flight" << endl;
			int selectedFlightID;
			
			//select a flight
			cout << "Make selection by FlightID";
			cin >> selectedFlightID;

			f= FileHelper::retrieveFlight(selectedFlightID); //need this method

			//display flight chosen by user
			cout << "You chose Flight ";
			f.display();
			cout << endl;
			
			//need to writecode out how to choose seat. i thot we were using a hashmap datamember for flight
			//however it is done, i need it here

			//get user details to create passenger;
			cout << "Let us get your personal details" << endl;
			cout << "Enter First Name: "; cin >> pfname;
			cout << "Enter Last Name: "; cin >> plname;
			cout << "Enter Address: "; cin >> paddress;
			cout << " Enter City"; cin >> pcity;
			cout << " Enter State"; cin >> pstate;
			cout << "Enter Zipcode"; cin >> pzipcode;
			cout << "Enter Phone Number"; cin >> pphonenumber;
			cout << "Enter email Address"; cin >> pemailaddress;
			
			//call retrieveAllPassengers and get the last passenger ID used 
			AllPassengers = FileHelper::retrieveAllPassengers(); //need this method
			pid = AllPassengers.size() + 1;

			//add user input into Passenger object
			p.setID(pid); p.setFirstName(pfname); p.setLastName(plname); p.setAddress(paddress);
			p.setCity(pcity); p.setState(pstate); p.setZipCode(pzipcode); p.setPhoneNumber(pphonenumber); 
			p.setEmailAddress(pemailaddress);

			//write new passenger to file  how is add being written
			p = FileHelper::addPassenger(p); //need this method

			//reserved flight object with passenger object
			int reserveID = ScheduleManager::reserveFlight(p, f);
			break;
		case 3:
			cout << "OPtion 3 Selected" << endl;
			break;
		case 0:
			break;
		default:
			cout << "Default Selected" << endl;
			break;
		}
		
		/*cout<< flush;*/

	}

	return 0;
}
