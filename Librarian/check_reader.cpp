#include <iostream>


#include "readers.h"
#include "books.h"
#include "borrowings.h"
#include "colors.h"


using namespace std;

int Readers::check() {
	if (readers_head->ID == 0)
	{
		cout << "There's no readers!" << endl;
		return 0;
	}
	cout << "Enter the ID of reader you want to check: ";
	int ID;
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
	if (p_readers->ID == ID) {
		cout << "First name:\t" << p_readers->first_name << endl;
		cout << "Last name:\t" << p_readers->surname << endl;
		cout << "Street:\t\t" << p_readers->street << endl;
		cout << "House number:\t" << p_readers->house_number << endl;
		cout << "Postcode:\t" << p_readers->postcode << endl;
		cout << "City:\t\t" << p_readers->city << endl;
		cout << "Birthdate: \t"
			<< p_readers->birthdate.year << " " << p_readers->birthdate.month << " " << p_readers->birthdate.day << endl << endl;

		p_borrowings = borrowings_head;

		cout << "Borrowing ID\tBook ID\t\tBorrowing date\t\tUntil when\tDate of return" << endl;
		while (1)
		{
			if (p_borrowings->reader_ID == ID)
			{
				cout << p_borrowings->ID << "\t\t";
				cout << p_borrowings->book_ID << "\t\t";
				cout << p_borrowings->from_when.year << " " << p_borrowings->from_when.month << " " << p_borrowings->from_when.day << "\t\t";
				cout << p_borrowings->until_when.year << " " << p_borrowings->until_when.month << " " << p_borrowings->until_when.day << "\t";
				if (p_borrowings->check_if_returned_after_date()) {
					set_color_text("red");
					cout << p_borrowings->return_date.year << " " << p_borrowings->return_date.month << " " << p_borrowings->return_date.day;
					cout << "!";
					set_color_text("white");
				}
				else
					cout << p_borrowings->return_date.year << " " << p_borrowings->return_date.month << " " << p_borrowings->return_date.day;

				cout << endl;
			}


			if (p_borrowings->next == NULL)
			{
				break;
			}

			p_borrowings = p_borrowings->next;
		}

		cout << endl;
		return 0; //correct
	}
	return -1;
}