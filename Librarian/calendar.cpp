#include <time.h>


#include "calendar.h"

time_t t = time(0);
struct tm now = *localtime(&t);

Date today() {

	//time_t t = time(0);
	//struct tm *now = localtime(&t);

	int year = now.tm_year + 1900;
	int month = now.tm_mon + 1;
	int day = now.tm_mday;

	Date today{
		year,
		month,
		day
	};
	return today;
}



time_t t2 = time(0) + 30 * 24 * 60 * 60;
struct tm in_30_days = *localtime(&t2);

Date return_date_proposal() {

	int year = in_30_days.tm_year + 1900;
	int month = in_30_days.tm_mon + 1;
	int day = in_30_days.tm_mday;

	Date return_date_proposal{
		year,
		month,
		day
	};
	return return_date_proposal;
}

