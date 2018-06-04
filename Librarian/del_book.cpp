

#include <iostream>


#include "books.h"


using namespace std;

int Books::del() {
	cout << "Enter the ID of book you want to remove: ";
	int ID;
	cin.sync();
	cin >> ID;


	Books *tmp_book;
	tmp_book = new Books;

	p_books = books_head;
	if (ID == books_head->ID) {
		tmp_book = books_head;
	}
	else
	{
		while (1)
		{

			if (p_books->next == NULL) {
				cout << "There is no book with that ID!" << endl;
				return 0;
			}

			if (p_books->next->ID == ID) {
				tmp_book = p_books->next;
				break;
			}

			p_books = p_books->next;
		}
	}

	if (tmp_book->ID == ID) {
		cout << "Title:\t\t" << tmp_book->title << endl;
		cout << "Author:\t\t" << tmp_book->author << endl;
		cout << "Year:\t\t" << tmp_book->year << endl;
		cout << "Publisher:\t" << tmp_book->publisher << endl;
		cout << "Genre:\t\t" << tmp_book->genre << endl;


		cin.sync();
		cout << "Confirm that you want to delete that book (Y/N): ";
		char ans;
		cin >> ans;
		if (ans == 'y' || ans == 'Y') {
			if (tmp_book->borrowed != 0) {
				cout << "Book is already borrowed! Deletion is not possible!" << endl
					<< "Book's return is necessary to remove it." << endl;
				return 1; //incorrect
			}
			if (tmp_book == books_head) { //if first element of the list
				books_head = books_head->next;
				free(tmp_book);
			}
			else {	//if not first element
				if (last_book == tmp_book) //if books is last on the list
				{
					last_book = p_books;
					p_books->next = NULL;
					free(tmp_book);
				}
				else { //if not last
					p_books->next = p_books->next->next;
					free(tmp_book);
				}
			}
			cout << "Deleted correctly!" << endl;
			return 0; //correct - deleted
		}

		cout << "Didn't deleted!" << endl;
		return 1; // incorrect - not deleted
	}
	else return -1;
}

Books::~Books() {

}