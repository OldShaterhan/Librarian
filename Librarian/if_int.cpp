#include <iostream>
#include "main.h"

int if_int()
{
	float variable;
	while (1) {
		std::cin >> variable;
		if (floorf(variable) != variable)
			std::cout << "You have entered not integer!" << std::endl;
		else
			break;
	}
	return floorf(variable);
}