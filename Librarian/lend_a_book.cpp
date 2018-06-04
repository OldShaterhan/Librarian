
#include <iostream>


#include "calendar.h"
#include "files.h"
#include "books.h"
#include "borrowings.h"
#include "readers.h"

using namespace std;

int Borrowings::lend_a_book() {

	if (readers_head->ID == 0)
	{
		cout << "There's no readers at library! Invite somebody!" << endl;
		return 0;
	}
	if (books_head->ID == 0)
	{
		cout << "There's no books at library?! Buy some of them to lend them!" << endl;
		return 0;
	}



	cin.sync(); //clearing stdin buffer
	cout << endl << "Enter reader's ID: ";
	cin >> reader_ID;

	p_readers = readers_head;
	while (1)
	{
		if (p_readers->ID == reader_ID)
			break;
		if (p_readers->next == NULL)
		{
			cout << "No reader with such ID!" << endl;
			delete this;
			return 1;
		}
		p_readers = p_readers->next;
	}
	
	cout << "Enter book's ID: ";
	cin >> book_ID;

	p_books = books_head;
	while (1)
	{
		if (p_books->ID == book_ID)
		{
			if (p_books->borrowed == NULL)
			{
				break;
			}
			else
			{
				cout << "Book is already lent, it's not possible to lend lent book!" << endl;
				delete this;
				return 1;
			}
		}
		if (p_books->next == NULL)
		{
			cout << "No book with such ID!" << endl;
			delete this;
			return 1;
		}
		p_books = p_books->next;
	}

	from_when = today();

	extern struct tm in_30_days;

	char ans;
	while (1)
	{
		cout << "Return date proposal: " << asctime(&in_30_days);
		cout << "Do you agree? (Y/N): ";
		cin.sync();
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			until_when = return_date_proposal();
			break;
		}
		else if (ans == 'n' || ans == 'N')
		{
			while (1)
			{
				cout << "Write return date in format YYYY MM DD: ";
				cin >> until_when.year >> until_when.month >> until_when.day;
				cin.sync();
				if (!check_if_after_return_date(this)) break;
				else cout << "Can't be borrowed to the day in past! Try again." << endl;

			}
			break;
		}
		else
			cout << "Wrong answer. Try again!" << endl;
	}
	return_date = { 0000, 00, 00 };

	ID = last_borrowing->ID + 1;
	cout << "Borrowing ID: " << ID << endl;

	next = NULL; //New borrowing will be the last element of the list 
	if (borrowings_head->ID == 0)
	{
		borrowings_head = this;
		last_borrowing = borrowings_head;
	}
	else
	{
		last_borrowing->next = this;
		last_borrowing = this;
	}

	p_books->borrowed = reader_ID; //if borrowed, value "borrowed" is equal to reader ID.


	cout << "Borrowed correctly." << endl;
	return 1;
}

Borrowings::Borrowings() {
	
}