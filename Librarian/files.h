#ifndef Files_H_
#define Files_H_
#include <iostream>
#include <fstream>
#include <string>

//#include "books.h"
//#include "borrowings.h"
//#include "readers.h"
//#include "list.h"

//readers file



//extern char *readers_filename; //global variable that stores readers filedata


int loadReaders(); //function that loads readers from file

int saveReaders(); //function that saves readers to file

//books file

//extern char *books_filename; //global variable that stores books filedata

int loadBooks(); //function that loads books from file

int saveBooks(); //function that saves books to file

//borrowings file

//extern char *borrowings_filename; //global variable that stores borrowings filedata

int loadBorrowings(); //function that loads borrowings from file

int saveBorrowings(); //function that saves borrowings to file


#endif