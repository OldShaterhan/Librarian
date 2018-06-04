#include "colors.h"

#include <string>
#include <Windows.h>

int set_color_text(std::string color) {



	HANDLE hOut;
	hOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (color == "red") SetConsoleTextAttribute(hOut, FOREGROUND_RED | FOREGROUND_INTENSITY);
	else if (color == "white") SetConsoleTextAttribute(hOut, FOREGROUND_GREEN | FOREGROUND_BLUE | FOREGROUND_RED);
	
	return 0;
}