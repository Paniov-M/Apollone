#pragma once
#include <iostream>
#include "Source.cpp"
class HeroManager
{
public:

	vector<Hero>heroes;

	void  ListHeroes()
	{
		int j;
		int HP = 100;
		int Damage = 120;
		int Speed = 90;


		for (j = 0;j < 10;j++)
		{
			string array[10] = { "Batman" , "Superman" , "Spider-Man" , "Hulk", "Iron Man " , "Captain Ameriña","Black Panter","Astronaft","Winter Soldier","Flash" };
			Hero hero1 = Hero(array[j], HP, Damage, Speed);
			heroes.push_back(hero1);

			HP += 20;
			Damage += 10;
			Speed += 15;
		}

		for (j = 0;j < heroes.size();j++)

		{
			cout << j + 1 << "  ";
			cout << heroes[j].name << " --- " << " HP - " << heroes[j].HP << ",  Damage - " << heroes[j].Damage << ", Speed - " << heroes[j].Speed << endl;
		}
		cout << endl;

	}

};