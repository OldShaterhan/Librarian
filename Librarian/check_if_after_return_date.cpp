
#include <iostream>

#include "borrowings.h"
#include "calendar.h"


using namespace std;

int Borrowings::check_if_after_return_date(Borrowings *borrowing) {
	Date today_is;
	today_is = today();

	if (today_is.year > borrowing->until_when.year ||
		(today_is.year == borrowing->until_when.year && today_is.month > borrowing->until_when.month) ||
		(today_is.year == borrowing->until_when.year && today_is.month == borrowing->until_when.month && today_is.day > borrowing->until_when.day))
	{
		return 1; //true - trying return after date or false for checking if until_when date is before today's day 
	}
	return 0; //false - not trying return after date or true for checking if until_when date is after today's day
}

/*int check_if_before_today() {
	Date today_is;
	today_is = today();

	if (today_is.year > p_borrowings->until_when.year ||
		(today_is.year == p_borrowings->until_when.year && today_is.month > p_borrowings->until_when.month) ||
		(today_is.year == p_borrowings->until_when.year && today_is.month == p_borrowings->until_when.month && today_is.day > p_borrowings->until_when.day))
	{
		return 1; //true - trying to set return's date before today
	}
	return 0; //false - not trying to set return's date before today
}*/

int Borrowings::check_if_returned_after_date() {

	if (p_borrowings->return_date.year == 0) return check_if_after_return_date(p_borrowings);

	if (p_borrowings->return_date.year > p_borrowings->until_when.year ||
		(p_borrowings->return_date.year == p_borrowings->until_when.year && p_borrowings->return_date.month > p_borrowings->until_when.month) ||
		(p_borrowings->return_date.year == p_borrowings->until_when.year && p_borrowings->return_date.month == p_borrowings->until_when.month && p_borrowings->return_date.day > p_borrowings->until_when.day))
	{
		return 1; //true - book has been returned after deadline
	}
	return 0; //false - book hasn't been returned after deadline
}