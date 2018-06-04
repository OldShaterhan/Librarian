
#include <iostream>


#include "calendar.h"
#include "colors.h"
#include "files.h"
#include "books.h"
#include "borrowings.h"
#include "readers.h"


using namespace std;

int Borrowings::return_book() {

	if (borrowings_head->ID == 0) {
		cout << "No book has been lent!" << endl;
		return 0;
	}

	int reader_ID, book_ID;
	char ans;
	cin.sync(); //clearing stdin buffer
	cout << "Enter reader's ID: ";
	cin >> reader_ID;

	p_readers = readers_head;
	while (1)
	{
		if (p_readers->ID == reader_ID)
			break;
		if (p_readers->next == NULL)
		{
			cout << "No reader with such ID!" << endl;
			return 0;
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
				cout << "Book is not already lent, it's not possible to return not lent book!" << endl;
				return 0;
			}
			else
			{
				break;
			}
		}
		if (p_books->next == NULL)
		{
			cout << "No book with such ID!" << endl;
			return 0;
		}
		p_books = p_books->next;
	}

	if (p_books->borrowed != reader_ID)
	{
		cout << "That reader didn't borrow that book! Check IDs!" << endl;
		return 0;
	}


	p_borrowings = borrowings_head;
	while (1) {
		if (p_borrowings->reader_ID == reader_ID && p_borrowings->book_ID == book_ID && p_borrowings->return_date.year == 0)
		{
			break;
		}
		if (p_borrowings->next == NULL)
		{
			cout << "An error occured. There's no borrowing with that data, however book is set as lent! Please check if book is available. (Y/N): ";
			cin.sync(); //clearing stdin buffer
			cin>>ans;
			while (1)
			{
				if (ans == 'y' || ans == 'Y')
				{
					cout << "OK, returning book..." << endl;
					p_books->borrowed = 0;
					cout << "Done!" << endl;
					break;
				}
				if (ans == 'n' || ans == 'N')
				{
					cout << "Returning to main menu..." << endl;
					return 0;
				}
				cout << "Wrong answer! Try again! " << endl;
			}
		}
		p_borrowings = p_borrowings->next;
	}

	
//	Code that would checking if book returned after time set by until_when

	cout << "Borrowed on " << p_borrowings->from_when.year << " "<< p_borrowings->from_when.month <<" "<< p_borrowings->from_when.day << endl;

	if (p_borrowings->check_if_after_return_date(p_borrowings))
		//if (check_if_after_return_date(p_borrowings))
	{
		set_color_text("red");
		cout << "After the date of return!" << endl;
		set_color_text("white");
	}

	cout << "Confirm return (Y/N): ";
	cin.sync(); //clearing stdin buffer
	cin>>ans;
	while (1)
	{
		if (ans == 'y' || ans == 'Y')
		{
			cout << "OK, returning book..." << endl;
			p_books->borrowed = 0;
			p_borrowings->return_date = today();
			cout << "Done!" << endl;
			return 0;
		}
		if (ans == 'n' || ans == 'N')
		{
			cout << "Returning to main menu..." << endl;
			return 0;
		}
		cout << "Wrong answer! Try again! " << endl;
	}

	return 0;
}

Borrowings::~Borrowings() {

}