

#include <iostream>


#include "readers.h"
#include "borrowings.h"


using namespace std;

int Readers::del() {
	if (readers_head->ID == 0)
	{
		cout << "There's no readers!" << endl;
	}
	cout << "Enter the ID of reader you want to remove: ";
	int ID;
	cin.sync();
	cin >> ID;
	p_readers = readers_head;

	Readers *tmp_reader;
	tmp_reader = new Readers;

	if (ID == readers_head->ID) {
		tmp_reader = readers_head;
	}
	else
	{
		while (1)
		{

			if (p_readers->next == NULL) {
				cout << "There is no reader with that ID!" << endl;
				return 0;
			}

			if (p_readers->next->ID == ID) {
				tmp_reader = p_readers->next;
				break;

			}

			p_readers = p_readers->next;
		}
	}
	if (tmp_reader->ID == ID) {
		cout << "First name:\t" << tmp_reader->first_name << endl;
		cout << "Last name:\t" << tmp_reader->surname << endl;
		cout << "Street:\t\t" << tmp_reader->street << endl;
		cout << "House number:\t" << tmp_reader->house_number << endl;
		cout << "Postcode:\t" << tmp_reader->postcode << endl;
		cout << "City:\t\t" << tmp_reader->city << endl;

		cin.sync();
		cout << "Confirm that you want to delete that reader (Y/N): ";
		char ans;
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			p_borrowings = borrowings_head;
			while (1)
			{
				if (p_borrowings->reader_ID == ID && p_borrowings->return_date.year == 0)
				{
					cout << "Reader hasn't returned all books! Not possible to remove him." << endl;
					return 1;
				}
				if (p_borrowings->next == NULL) break;
				p_borrowings = p_borrowings->next;
			}
			if (tmp_reader == readers_head) { //if first element of the list
				readers_head = readers_head->next;
				delete tmp_reader;
			}
			else {	//if not first element
				if (last_reader == tmp_reader) //if readers is last on the list
				{
					last_reader = p_readers;
					p_readers->next = NULL;
					delete tmp_reader;
				}
				else { //if not last
					p_readers->next = p_readers->next->next;
					delete tmp_reader;
				}
			}
			cout << "Deleted correctly!" << endl;
			return 0; //correct - deleted
		}

		
		
		cout << "Not deleted!" << endl;
		return 1; // incorrect - not deleted
	}
	else return -1;
}

Readers::~Readers(){

}