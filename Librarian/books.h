#ifndef Books_H_
#define Books_H_

#include <iostream>
#include <string>

using namespace std;

class Books //structure of books data
{
public:
	int ID;
	string title;
	string author;
	int year;
	string publisher;
	string genre;
	int borrowed;
	Books *next;

	Books();
	~Books();


	Books get_info(); //gets book's data from user
	int set_ID(); //sets ID
	int add(); //adds book

	int update(); //updates book
	int check(); //checks book
	int show_list(); //shows list

	int del(); //removes book
};


extern Books *books_head, *p_books, *last_book;
//Books *books_head, *p_books, *last_book;
//pointer to first element of books list, pointer that goes through the list, pointer to the last book on the list



#endif