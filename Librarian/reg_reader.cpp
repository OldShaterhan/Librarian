#include <iostream>


#include "calendar.h"
//#include "modes.h"
#include "files.h"
#include "readers.h"
#include "main.h"


using namespace std;

Readers Readers::get_info() {
	float x_tmp;
	cin.sync(); //clearing cin buffer
	cin.ignore(1000, '\n'); //sync doesn't work properly
	cout << "Enter the first name: ";
	getline(cin, first_name);
	cout << "Enter the surname: ";
	getline(cin, surname);
	cout << "Enter the street: ";
	getline(cin, street);
	cout << "Enter the house (and flat number): ";
	cin >> house_number;
	cout << "Enter the postcode (skip dashes): ";
	postcode = if_int();

	cin.sync(); //clearing stdin
	cin.ignore(1000, '\n');
	cout << "Enter the city: ";
	getline(cin, city);
	cout << "Enter birthdate in format YYYY (enter) MM (enter) DD: ";
	birthdate.year = if_int();
	birthdate.month = if_int();
	birthdate.day = if_int();

	cout << "Enter the sex (M for male, F or K for female): ";
	char tmp; //tmp string to check sex
	cin.sync(); //clearing stdin
	cin >> tmp;
	if (tmp == 'M' || tmp == 'm') {
		sex = 1;
	}
	else {
		sex = 0;
	}
	cin.sync(); //clearing stdin
	cout << "Enter the ID number (skip spaces): ";
	cin >> ID_number;
	cout << endl;
	return *this;
}

//int Readers::set_ID(Readers *new_reader) {
int Readers::set_ID() {
	cout << "Setting reader ID..." << endl;
//	p_readers = readers_head;
//	while (p_readers->next != NULL)
//	{
//		p_readers = p_readers->next;
//	}
		int tmp = last_reader->ID + 1;
		cout << "Reader ID: " << tmp << endl;
	return tmp;
}

int Readers::reg() {

	*this = get_info(); //loads data of new reader from user
	ID = set_ID();
	next = NULL; //New reader will be the last element of the list 
	if (readers_head->ID==0)
	{
		readers_head = this;
		last_reader = readers_head;
	}
	else
	{
		last_reader->next = this;
		last_reader = this;
	}

	cout << "Registered correctly." << endl << endl;
	return 0;
}

Readers::Readers() {

}