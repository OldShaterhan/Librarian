#include <iostream>


#include "calendar.h"
//#include "modes.h"
#include "files.h"
#include "books.h"
#include "main.h"

using namespace std;

Books Books::get_info() {
	cin.sync(); //clearing stdin buffer
	cin.ignore(1000, '\n');
	cout << "Enter a title: ";
	getline(cin, title);
	cout << "Enter an author: ";
	getline(cin, author);
	cout << "Enter the year of publishing: ";
	year = if_int();
	cin.sync();
	cin.ignore(1000, '\n');
	cout << "Enter a publisher: ";
	getline(cin, publisher);
	cout << "Enter the genre: ";
	getline(cin, genre);
	cout << endl;

	return *this;
}

int Books::set_ID() {
	int tmp = last_book->ID + 1;
	cout << "Book ID: " << tmp << endl;
	return tmp;
}

int Books::add() {
	*this = get_info(); //loads data of new reader from user
	ID = set_ID();
	borrowed = 0; //new book can't be borrowed at start
	next = NULL; //New book will be the last element of the list 
	if (books_head->ID == 0)
	{
		books_head = this;
		last_book = books_head;
	}
	else
	{
		last_book->next = this;
		last_book = this;
	}

	cout << "Book added correctly." << endl;
	return 0;
}

Books::Books() {

}