#ifndef Calendar_H_
#define Calendar_H_
#include <iostream>

#include <time.h>

struct Date {
	int year;
	int month;
	int day;
};

//Date stringToDate(string sdate);

//string dateToString(Date date);

Date today(); //function that returns todays date structure
Date return_date_proposal(); //function that returns proposal date of book's return deadline (30 days from today) as structure

#endif