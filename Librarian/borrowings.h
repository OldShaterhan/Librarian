#pragma once
#ifndef Borrowings_H_
#define Borrowings_H_


#include <iostream>
#include "calendar.h"

class Borrowings //structure that contains information about borrowings
{
public:
	int ID;
	int reader_ID;
	int book_ID;
	Date from_when;
	Date until_when;
	Date return_date;
	Borrowings *next;

	int lend_a_book(); //to lend a book
	int check_if_after_return_date(Borrowings *borrowing);//checks if reader is late
	int check_if_returned_after_date(); //checks if reader was late
	int return_book(); //returns book to library


	Borrowings();
	~Borrowings();
};


extern Borrowings *borrowings_head, *p_borrowings, *last_borrowing;
//pointer to first element of borrowings list, pointer that goes through whole list, last borrowing on the list



#endif