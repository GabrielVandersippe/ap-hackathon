#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "objects.hpp"
#include "game.hpp"

struct Inventory {
public :
	std::vector<Object> contents;
	int max_size;

	Inventory(int max_size) : max_size(max_size) {}

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

	TypeCase is_over = TypeCase::GROUND;

	int max_hp;
	int current_hp;

	int x;
	int y;

	Inventory* inventory;

	Hero(std::string name, int start_x, int start_y, int inv_max_size = 4) : name(name), current_hp(0), max_hp(5), x(start_x), y(start_y) {
		//inventory->max_size = inv_max_size;
		inventory->add(Weapon(1, (std::string)"Basic Dagger", (std::string)"A worn dagger.\n It is not suited for spreading butter, let alone slaying monsters", 2));
	}

	void consume(int id) {
		Object* obj = &inventory->contents[id];
 		if (!obj->consumable) std::cout << "This object cannot be consumed." << std::endl;
		else {
			/*obj->consume(this);*/
			inventory->remove(id); //Faire compter cela comme une action et pas dans le cas o� on ne consomme rien
			//Id�e: mettre la non-consommation comme effet de la fonction consume mais alors il faut faire savoir qu'on a rien fait.
			
		}
	}
};