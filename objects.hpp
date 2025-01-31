#pragma once
#include <string>
#include <iostream>
#include <random>

struct Object {

	int rarity;
	std::string name;
	std::string description;
	bool consumable;

	/*void virtual consume (Hero* h) = 0;*/

	Object(int r, std::string n, std::string d, bool consumable) : rarity(r), name(n), description(d), consumable(consumable) {}

	void show() {
		std::cout << "> ";
		for (int i = 0; i<rarity; i++) std::cout << '*';
		std::cout << " : " << name << std::endl;
	}

};

struct Weapon : public Object {

	int damage;

	//void consume(Hero* h) { h->current_hp = 0; }; //TODO : a changer (c'est juste un test)

	Weapon(int r, std::string name, std::string desc,int damage) : Object(r, name, desc, false), damage(damage) {}
	
};

struct Potion : public Object {

	int healing_power; 

	/*void consume(Hero* h) {
		h->current_hp = std::max(h->max_hp, h->current_hp + healing_power);
	}*/

	Potion(int r, std::string name, std::string desc, int healing_power) : Object(r, name, desc, true), healing_power(healing_power) {}
	//Choses
	
};