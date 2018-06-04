
#include <iostream>
#include <fstream>
#include <conio.h>
#include <direct.h> //mkdir
#include <stdlib.h> //exit function

#include "files.h"
#include "readers.h"
#include "books.h"
#include "borrowings.h"
#include "main.h"


using namespace std;

Readers *readers_head, *p_readers, *last_reader;
fstream readers_file;
//char *readers_filename = "data/readers.txt";

Books *books_head, *p_books, *last_book;
fstream books_file;
//char *books_filename = "data/books.txt";

Borrowings *borrowings_head, *p_borrowings, *last_borrowing;
fstream borrowings_file;
//char *borrowings_filename = "data/borrowings.txt";


int loadReaders()
{

	cout << "Loading readers data..." << endl;

	readers_head = new Readers;
//	p_readers = new Readers;
//	last_reader = new Readers;
	last_reader = (p_readers = readers_head);


	if (!readers_head)
	{
		cout << "Out of memory!" << endl;
		free_memory();
		exit(1);
	}

	readers_head->next = NULL;
	readers_head->ID = 0;

	readers_file.open("data/readers.txt", ios::in);

	if (!readers_file.good()) //checking if file isn't accessible, we assume that doesn't exist
	{
		cout << "File doesn't exist. Creating file..." << endl;
		readers_file.open("data/readers.txt", ios::out);  //creating file
		readers_file.close(); //closing file
		cout << "Done!" << endl;
		return 0; //nothing to be loaded - closing function
	}
	else  //if file is accessible, we are loading data to list of Readers
	{
		while (!readers_file.eof())
		{
			
			Readers *new_reader;
			new_reader = new Readers;

			if (!new_reader)
			{
				cout << "Out of memory!" << endl;
				free_memory();
				exit(1);
			}


			readers_file >> new_reader->ID;
			//readers_file.clear();
			//readers_file.sync(); doesn't work as wanted
			readers_file.ignore(1000, '\n');
			getline(readers_file, new_reader->first_name);
			getline(readers_file, new_reader->surname);
			getline(readers_file, new_reader->street);
			readers_file >> new_reader->house_number;
			readers_file >> new_reader->postcode;
			readers_file.ignore(1000, '\n');
			getline(readers_file, new_reader->city);
			readers_file >> new_reader->birthdate.year;
			readers_file >> new_reader->birthdate.month;
			readers_file >> new_reader->birthdate.day;
			readers_file >> new_reader->sex;
			readers_file.ignore(1000, '\n');
			getline(readers_file, new_reader->ID_number);
			new_reader->next = NULL;

			if (readers_head->ID == 0)
			{

				last_reader = (p_readers = (readers_head = new_reader));

			}
			else
			{
				p_readers->next = new_reader;
				p_readers = new_reader;
				last_reader = p_readers;
			}
		}

			
	}
	readers_file.close();
	cout << "Readers loading complete!" << endl;
	return 0;
}


int loadBooks()
{

	cout << "Loading books data..." << endl;

	books_head = new Books;
//	p_books = new Books;
//	last_book = new Books;
	last_book = (p_books = books_head);


	if (!books_head)
	{
		cout << "Out of memory!" << endl;
		free_memory();
		exit(1);
	}

	books_head->next = NULL;
	books_head->ID = 0;

	books_file.open("data/books.txt", ios::in);

	if (!books_file.good()) //checking if file isn't accessible, we assume that doesn't exist
	{
		cout << "File doesn't exist. Creating file..." << endl;
		books_file.open("data/books.txt", ios::out);  //creating file
		books_file.close(); //closing file
		cout << "Done!" << endl;
		return 0; //nothing to be loaded - closing function
	}
	else  //if file is accessible, we are loading data to list of Books
	{
		while (!books_file.eof())
		{

			Books *new_book;
			new_book = new Books;

			if (!new_book)
			{
				cout << "Out of memory!" << endl;
				free_memory();
				exit(1);
			}


			books_file >> new_book->ID;
			books_file.ignore(1000, '\n');
			getline(books_file, new_book->title);
			getline(books_file, new_book->author);
			books_file >> new_book->year;
			books_file.ignore(1000, '\n');
			getline(books_file, new_book->publisher);
			getline(books_file, new_book->genre);
			books_file >> new_book->borrowed;
			new_book->next = NULL;

			if (books_head->ID == 0)
			{

				last_book = (p_books = (books_head = new_book));

			}
			else
			{
				p_books->next = new_book;
				p_books = new_book;
				last_book = p_books;
			}
		}


	}
	books_file.close();
	cout << "Books loading complete!" << endl;
	return 0;
}


int loadBorrowings()
{

	cout << "Loading borrowings data..." << endl;

	borrowings_head = new Borrowings;
//	p_borrowings = new Borrowings;
//	last_borrowing = new Borrowings;
	last_borrowing = (p_borrowings = borrowings_head);


	if (!borrowings_head)
	{
		cout << "Out of memory!" << endl;
		free_memory();
		exit(1);
	}

	borrowings_head->next = NULL;
	borrowings_head->ID = 0;


	borrowings_file.open("data/borrowings.txt", ios::in);

	if (!borrowings_file.good()) //checking if file isn't accessible, we assume that doesn't exist
	{
		cout << "File doesn't exist. Creating file..." << endl;
		borrowings_file.open("data/borrowings.txt", ios::out);  //creating file
		borrowings_file.close(); //closing file
		cout << "Done!" << endl;
		return 0; //nothing to be loaded - closing function
	}
	else  //if file is accessible, we are loading data to list of Borrowings
	{
		while (!borrowings_file.eof())
		{

			Borrowings *new_borrowing;
			new_borrowing = new Borrowings;

			if (!new_borrowing)
			{
				cout << "Out of memory!" << endl;
				free_memory();
				exit(1);
			}

			borrowings_file >> new_borrowing->ID;
			borrowings_file >> new_borrowing->reader_ID;
			borrowings_file >> new_borrowing->book_ID;
			borrowings_file >> new_borrowing->from_when.year >>
				new_borrowing->from_when.month >> new_borrowing->from_when.day;
			borrowings_file >> new_borrowing->until_when.year >>
				new_borrowing->until_when.month >> new_borrowing->until_when.day;
			borrowings_file >> new_borrowing->return_date.year >>
				new_borrowing->return_date.month >> new_borrowing->return_date.day;
			
			new_borrowing->next = NULL;

			if (borrowings_head->ID == 0)
			{

				last_borrowing = (p_borrowings = (borrowings_head = new_borrowing));

			}
			else
			{
				p_borrowings->next = new_borrowing;
				p_borrowings = new_borrowing;
				last_borrowing = p_borrowings;
			}
		}
	}

	borrowings_file.close();
	cout << "Borrowings loading complete!" << endl;
	return 0;
}

