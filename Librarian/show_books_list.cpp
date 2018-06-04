#include <iostream>

#include "books.h"


using namespace std;

int Books::show_list() {
	if (books_head->ID == 0)
	{
		cout << "There's no books!" << endl;
		return 0;
	}
	p_books = books_head;
	cout << "ID \t Title \t\t Author \t Year \t Publisher \t Genre \t Borrowed"<<endl;
	while (p_books)
	{
		cout << p_books->ID << "\t "
			<< p_books->title << "\t\t "
			<< p_books->author << "\t\t "
			<< p_books->year << "\t "
			<< p_books->publisher << "\t "
			<< p_books->genre;
		if (p_books->borrowed == NULL)
		{
			cout << "\tNot borrowed." << endl;
		}
		else
		{
			cout << "\tBorrowed by reader " << p_books->borrowed << endl;
		}
		p_books = p_books->next;
	}
	cout << endl;
	return 1;
}