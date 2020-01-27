#pragma once
#include <iostream>
#include "Source.cpp"
class Hero
{
public:
	string name;
	int HP;
	int Damage;
	int Speed;
	int Number;


	void heros(string super_name, int super_hp, int super_damage, int super_speed)
	{
		name = super_name;
		HP = super_hp;
		Damage = super_damage;
		Speed = super_speed;

	}

	void get()
	{
		cout << "Hero name - " << name << "\n HP - " << HP << "\n Damage - " << Damage << "\n Speed - " << Speed << endl;

	}

	Hero()
	{}

	Hero(string name, int hero_hp, int hero_damage, int hero_speed)
	{
		this->name = name;
		HP = hero_hp;
		Damage = hero_damage;
		Speed = hero_speed;

	}

};
