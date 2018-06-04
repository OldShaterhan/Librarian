#pragma once
#ifndef Readers_H_
#define Readers_H_

#include <iostream>
#include <string>
#include "calendar.h"

using namespace std;

class Readers
{
public:
	int ID;
	string first_name;
	string surname;
	string street;
	string house_number;
	int postcode;
	string city;
	Date birthdate;
	int sex; //1 male, 0 female
	string ID_number;
	Readers *next; //pointer to the next reader on the list.

	Readers(); //default constructor – it’s empty
	~Readers(); //default destructor – it’s empty

	int reg(); //method to regiter new reader
	int set_ID(); //method that sets new ID
	Readers get_info(); //method that sets readers data given by user

	int update(); //updating reader's data
	int check(); //checking reader's data
	int show_list(); //shows readers list

	int del(); //removing readers

};

extern Readers *readers_head, *p_readers, *last_reader;	//reader_head - first reader on the list
														//p_reader - pointer to one of the readers
														//last_reader - pointer to last reader on the list


#endif

