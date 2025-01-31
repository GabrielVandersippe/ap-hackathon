#pragma once
#include <iostream>
#include <vector>
#include "objects.hpp"

struct Inventory {
	
	std::vector<Object> contents;
	int max_size;

	void showInventory() {
		for (int i = 0; i < contents.size(); i++) {
			contents[i].show();
			std::cout << std::endl;
		}
	}

};

struct Hero {

	char symbol = '@';

	int max_hp;
	int current_hp;

	Inventory* i;
};