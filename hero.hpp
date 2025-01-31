#pragma once
#include <iostream>
#include <vector>
#include "objects.hpp"

struct Inventory {
public :
	std::vector<Object> contents;
	int max_size;

	void showInventory() {
		for (int i = 0; i < contents.size(); i++) {
			contents[i].show();
			std::cout << std::endl;
		}
	}

	void add(Object obj) { contents.push_back(obj); }

	void remove(int id) { contents.erase(contents.begin() + id); } //TODO : si l'objet est un "new...", il faut aussi le delete !!!!!!

};

struct Hero {
private:
	char symbol = '@';

	std::string name;

public:
	int max_hp;
	int current_hp;

	int x;
	int y;

	Inventory* inventory;

	Hero(std::string name, int start_x, int start_y) : name(name), current_hp(0), max_hp(5), x(start_x), y(start_y) {
		inventory->max_size = 4;
		inventory->add()

	}
};