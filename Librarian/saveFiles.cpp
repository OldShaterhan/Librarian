#include <iostream>

#include "files.h"
#include "readers.h"
#include "books.h"
#include "borrowings.h"


using namespace std;

//Readers *readers_head, *p_readers, *last_reader;
extern fstream readers_file;
//char *readers_filename = "data/readers.txt";

//Books *books_head, *p_books, *last_book;
extern fstream books_file;
//char *books_filename = "data/books.txt";

//Borrowings *borrowings_head, *p_borrowings, *last_borrowing;
extern fstream borrowings_file;
//char *borrowings_filename = "data/borrowings.txt";

int saveReaders() {


	readers_file.open("data/readers.txt", ios::out);
	p_readers = readers_head;


	if (readers_head->ID > 0) {
		while(p_readers != NULL)
		{
			readers_file << p_readers->ID << endl;
			readers_file << p_readers->first_name<<endl;
			readers_file << p_readers->surname << endl;
			readers_file << p_readers->street << endl;
			readers_file << p_readers->house_number << endl;
			readers_file << p_readers->postcode << endl;
			readers_file << p_readers->city << endl;
			readers_file << p_readers->birthdate.year<< " "
				<< p_readers->birthdate.month<< " " << p_readers->birthdate.day<<endl;
			readers_file << p_readers->sex << endl;
			readers_file << p_readers->ID_number;
			if (p_readers != last_reader) readers_file << endl;
			p_readers = p_readers->next;
		}
	}
	readers_file.close();
	return 0;
}

int saveBooks() {
	books_file.open("data/books.txt", ios::out);


	if (books_head->ID > 0) {
		p_books = books_head;
		while (p_books != NULL)
		{
			books_file << p_books->ID << endl;
			books_file << p_books->title << endl;
			books_file << p_books->author << endl;
			books_file << p_books->year << endl;
			books_file << p_books->publisher << endl;
			books_file << p_books->genre << endl;
			books_file << p_books->borrowed;
			if (p_books != last_book) books_file << endl;
			p_books = p_books->next;
		}
	}
	books_file.close();
	return 0;
}

int saveBorrowings() {
	borrowings_file.open("data/borrowings.txt", ios::out);

	p_borrowings = borrowings_head;

	if (borrowings_head->ID > 0) {
		while (p_borrowings != NULL)
		{
			borrowings_file << p_borrowings->ID << " ";
			borrowings_file << p_borrowings->reader_ID << " ";
			borrowings_file << p_borrowings->book_ID << " ";
			borrowings_file << p_borrowings->from_when.year << " " <<
				p_borrowings->from_when.month << " " << p_borrowings->from_when.day << " ";
			borrowings_file << p_borrowings->until_when.year << " " <<
				p_borrowings->until_when.month << " " << p_borrowings->until_when.day << " ";
			borrowings_file << p_borrowings->return_date.year << " " <<
				p_borrowings->return_date.month << " " << p_borrowings->return_date.day;

			if (p_borrowings != last_borrowing) borrowings_file << endl;
			p_borrowings = p_borrowings->next;
		}
	}
	borrowings_file.close();
	return 0;
}