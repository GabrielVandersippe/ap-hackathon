#pragma once
#include <iostream>
#include <string>
#include "hero.hpp"

inline bool isdigit(std::string s) {
	int i = 0;
	bool is_digit = true;
	while (s[i] != '\0') {
		is_digit = is_digit && std::isdigit(s[i]);
	}
	return is_digit;
}

inline void openInventory(Hero &hero) {
	bool is_open = true;
	std::string input;

	hero.showInventory();

	std::cout << "\n To get help, type 'help'" << std::endl;

	while (is_open) {

		std::cin >> input;

		if (input == "help") { //TODO : on ne peut plus sortir de help !!!
			std::cout <<
				"To select an item, enter the number next to it. \nTo consume a consumable item, enter 'consume' afterwards." << std::endl;
		}

		if (isdigit(input)) {
			printf("Is digit!");
		}

		is_open = false;
		}
}