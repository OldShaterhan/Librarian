

#include <iostream>


#include "readers.h"
#include "main.h"


using namespace std;

int Readers::update() {
	if (readers_head->ID == 0)
	{
		cout << "There's no readers!" << endl;
		return 0;
	}
	cout<<endl;
	cout << "Enter the ID of reader you want to update: ";
	int ID;
	cin.sync();
	cin >> ID;

	p_readers = readers_head;

	while (1)
	{
		if (p_readers->ID == ID)
			break;
		if (p_readers->next == NULL) {
			cout << "There is no reader with that ID!" << endl;
			return 0;
		}

		p_readers = p_readers->next;
	}
	

	cout << "Actual data of reader with ID: " << ID << endl;
	cout << "First name:\t" << p_readers->first_name << endl;
	cout << "Last name:\t" << p_readers->surname << endl;
	cout << "Street:\t\t" << p_readers->street << endl;
	cout << "House number:\t" << p_readers->house_number << endl;
	cout << "Postcode:\t" << p_readers->postcode << endl;
	cout << "City:\t\t" << p_readers->city << endl;
	cout << "Birthdate:\t" << p_readers->birthdate.year << " " << p_readers->birthdate.month << " " << p_readers->birthdate.day << endl;
	cout << "ID number:\t" << p_readers->ID_number << endl;

	cout << "Confirm that you want to update that reader (Y/N): ";

	cin.sync();

	char ans;
	cin>>ans;
	if (ans == 'y' || ans == 'Y') {


		cout << "Set new data:" << endl;

		*this = get_info();

		cout << endl;

		cout << "Reader updated." << endl;
		return 0; //updated
	}
	return 1; //not updated
}