#pragma once
#include <iostream>
#include <vector>
#include <string>
#include "game.hpp"
#include "objects.hpp"

struct Object {

	int rarity;
	std::string name;
	std::string description;
	bool consumable;

	/*void virtual consume (Hero* h) = 0;*/

	Object(int r, std::string n, std::string d, bool consumable) : rarity(r), name(n), description(d), consumable(consumable) {}

	void show() {
		std::cout << "> ";
		for (int i = 0; i < rarity; i++) std::cout << '*';
		std::cout << " : " << name << std::endl;
	}

};

struct Weapon : public Object {

	int damage;

	//void consume(Hero* h) { h->current_hp = 0; }; //TODO : a changer (c'est juste un test)

	Weapon(int r, std::string name, std::string desc, int damage) : Object(r, name, desc, false), damage(damage) {}

};

struct Potion : public Object {

	int healing_power;

	/*void consume(Hero* h) {
		h->current_hp = std::max(h->max_hp, h->current_hp + healing_power);
	}*/

	Potion(int r, std::string name, std::string desc, int healing_power) : Object(r, name, desc, true), healing_power(healing_power) {}

};

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

	int max_hp;
	int current_hp;

	int x;
	int y;

	Inventory* inventory;

	Hero(std::string name, int start_x, int start_y, int inv_max_size = 4) : name(name), current_hp(0), max_hp(5), x(start_x), y(start_y) {
		Inventory inv(inv_max_size);
		inventory = &inv;
		inventory->add(Weapon(1, (std::string)"Basic Dagger", (std::string)"A worn dagger.\n It is not suited for spreading butter, let alone slaying monsters", 2));
	}

	void consume(int id) {
		Object* obj = &inventory->contents[id];
 		if (!obj->consumable) std::cout << "This object cannot be consumed." << std::endl;
		else {
			/*obj->consume(this);*/
			inventory->remove(id); //Faire compter cela comme une action et pas dans le cas o� on ne consomme rien
			//Idee: mettre la non-consommation comme effet de la fonction consume mais alors il faut faire savoir qu'on a rien fait.
			
		}
	}
};

