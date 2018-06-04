

#include <iostream>


#include "books.h"
#include "main.h"


using namespace std;

int Books::update() {
	if (books_head->ID == 0)
	{
		cout << "There's no books!" << endl;
		return 0;
	}
	cout << endl;
	cout << "Enter the ID of book you want to update: ";
	int ID;
	cin >> ID;

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


	cout << "Actual data of book with ID: " << ID << endl;
	cout << "Title:\t\t" << p_books->title << endl;
	cout << "Author:\t\t" << p_books->author << endl;
	cout << "Year:\t\t" << p_books->year << endl;
	cout << "Publisher:\t" << p_books->publisher << endl;
	cout << "Genre:\t\t" << p_books->genre << endl;
	while (1) {
		cout << "Confirm that you want to update that book (Y/N): ";

		cin.sync();

		char ans;
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {

			cin.sync(); //clearing stdin buffer
			*this = get_info();
			cout << endl;


			cout << "Book updated." << endl;
			return 1; //updated
		}
		else if (ans == 'n' || ans == 'N')
		{
			cout << "Not updated!" << endl;
			return 0; //not updated
		}
		else
			cout << "Wrong answer!" << endl;
	}
}