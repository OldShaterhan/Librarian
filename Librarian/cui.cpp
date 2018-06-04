#include <iostream>
#include <windows.h>
#include <conio.h> //for clrscr, but doesn't work

#include "files.h"
#include "readers.h"
#include "books.h"
#include "borrowings.h"
#include "colors.h"
#include "main.h"

using namespace std;

void cui() {
	int mode;
	cin.sync();
	while(1)
	{
		cout
			<<"Welcome to Librarian application! Here you have list of modes:"<<endl
			<< "	1 - Register a new reader"<<endl
			<< "	2 - Update reader's data"<<endl
			<< "	3 - Delete a reader"<<endl
			<< "	4 - Check reader's data and borrowings"<<endl
			<< "	5 - Show readers list"<<endl
			<< "	6 - Add a new book to library"<<endl
			<< "	7 - Update book's data"<<endl
			<< "	8 - Remove a book"<<endl
			<< "	9 - Check information about book and its borrowings"<<endl
			<< "	10 - Show books list"<<endl
			<< "	11 - Lend a book"<<endl
			<< "	12 - Return a book"<<endl
			<< "..."
			<< "	15 - Exit"<<endl<<endl;

		cin>>mode; //needs to be configured while char written.

		switch (mode) { //checks which mode user have choosen and runs it.
			case 1:
			{
				Readers *new_reader;
				new_reader = new Readers;
				if (!new_reader)
				{
					cout << "Out of memory!" << endl;
					break;
				}
				new_reader->reg();
				saveReaders();
			}
			break;

			case 2:
			{
				p_readers->update();
				saveReaders();
			}
			break;

			case 3:
			{
				p_readers->del();
				saveReaders();
			}
			break;

			case 4:
			{
				p_readers->check();
			}
			break;

			case 5:
			{
				p_readers->show_list();
			}
			break;

			case 6:
			{
				Books *new_book;
				new_book = new Books;
				if (!new_book)
				{
					cout << "Out of memory!" << endl;
					break;
				}
				new_book->add();
				saveBooks();
			}
			break;

			case 7:
			{
				p_books->update();
				saveBooks();
			}
			break;

			case 8:
			{
				p_books->del();
				saveBooks();
			}
			break;

			case 9:
			{
				p_books->check();
			}
			break;

			case 10:
			{
				p_books->show_list();
			}
			break;

			case 11:
			{
				Borrowings *new_borrowing;
				new_borrowing = new Borrowings;
				if (!new_borrowing)
				{
					cout << "Out of memory!" << endl;
					break;
				}
				new_borrowing->lend_a_book();
				saveBooks();
				saveBorrowings();
			}
			break;

			case 12:
			{
				p_borrowings->return_book();
				saveBooks();
				saveBorrowings();
			}
			break;

			case 13:
			{
				cout << "text"  << endl;
				set_color_text("red");
				cout << "text" << endl;
				set_color_text("white");
				cout << "text" << endl;

			}
			break;

			case 14:
			{
				system("cls");
			}
			break;

			case 15:
			{
				saveReaders();
				saveBooks();
				saveBorrowings();
				cout << endl << endl <<
					"Thanks for working with Librarian!";

				free_memory();


				exit(0);
			}
			break;

			default:
			{
				//clrscr();
				cout << "You have choosen inproper mode. Try again." << endl << endl;
				cin.sync();
				break;
			}
		}
	}
}