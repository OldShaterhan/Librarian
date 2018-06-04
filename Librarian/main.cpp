#include <iostream>

#include "main.h"
/*
#include "books.h"
#include "borrowings.h"
#include "readers.h"
#include "list.h"
#include "modes.h"
*/
#include "files.h"

using namespace std;

int main() {
	loadReaders();
	loadBooks();
	loadBorrowings();
	cui();
}