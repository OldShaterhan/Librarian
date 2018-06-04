

#include <iostream>


#include "books.h"
#include "borrowings.h"
#include "colors.h"
#include "readers.h"


using namespace std;

int Books::check() {
	if (books_head->ID == 0)
	{
		cout << "There's no books!" << endl;
		return 0;
	}
	cout << "Enter the ID of book you want to check: ";
	int ID;
	cin>>ID;
	p_books = books_head;
	while (1)
	{
		if (p_books->ID == ID)
			break;
		if (p_books->next == NULL) {
			cout << "There is no book with that ID!" << endl;
			return 0;
		}

		p_books = p_books->next;
	}
	cout << "Title:\t\t" << p_books->title << endl;
	cout << "Author:\t\t" << p_books->author << endl;
	cout << "Year:\t\t" << p_books->year << endl;
	cout << "Publisher:\t" << p_books->publisher << endl;
	cout << "Genre:\t\t" << p_books->genre << endl;
	cout << "Borrowed:\t";
	if (p_books->borrowed != NULL) {
		p_readers = readers_head;
		while (p_readers->ID != p_books->borrowed)
		{
			if (p_readers->next == NULL)
			{
				cout << "It looks like, we have some error here... (Borrowed by unexisting reader)" << endl;
			}
			p_readers = p_readers->next;
		}
		cout << "YES, by reader with ID: " << p_readers->ID << endl;
	}
	else {
		cout << "NO" << endl;
	}

	p_borrowings = borrowings_head;

	cout << "Borrowing ID\tReader ID\tBorrowing date\t\tUntil when\tDate of return" << endl;
	while (1)
	{
		if (p_borrowings->book_ID == ID)
		{
			cout << p_borrowings->ID <<" \t\t";
			cout << p_borrowings->reader_ID <<" \t\t";
			cout << p_borrowings->from_when.year << " " <<p_borrowings->from_when.month << " " << p_borrowings->from_when.day << "\t\t";
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