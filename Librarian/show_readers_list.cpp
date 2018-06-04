#include <iostream>

#include "readers.h"


using namespace std;

int Readers::show_list() {
	if (readers_head->ID == 0)
	{
		cout << "There's no readers!" << endl;
		return 0;
	}
	p_readers = readers_head;
	while (p_readers)
	{
		cout << p_readers->ID << " "
			<< p_readers->first_name << " "
			<< p_readers->surname << endl;
		p_readers = p_readers->next;
	}
	cout << endl;
	return 0;
}