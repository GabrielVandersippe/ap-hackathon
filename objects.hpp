#include <string>
#include <iostream>


struct Object {

	int rarity;
	std::string name;
	std::string description;

	Object(int r, std::string n, std::string d) : rarity(r), name(n), description(d) {}

	void show() {
		std::cout << "> ";
		for (int i = 0; i<rarity; i++) std::cout << '*';
		std::cout << " : " << name << std::endl;
	}

};

struct Potion : public Object {

	Potion() : Object(4, "Potion", "Glouglou c'est miam miam") {}
	//Choses
};