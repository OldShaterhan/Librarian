#include <iostream>


#include "readers.h"
#include "books.h"
#include "borrowings.h"


using namespace std;

void free_memory() {
	while (readers_head) {
		p_readers = readers_head->next;
		delete readers_head;
		readers_head = p_readers;
	}

	while (books_head) {
		p_books = books_head->next;
		delete books_head;
		books_head = p_books;
	}

	while (borrowings_head) {
		p_borrowings = borrowings_head->next;
		delete borrowings_head;
		borrowings_head = p_borrowings;
	}
}