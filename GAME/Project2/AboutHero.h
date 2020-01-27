#pragma once
#include <iostream>
#include "Source.cpp"
class AboutHero
{
	vector<Hero>heroes;

public:

	void AddHero()
	{
		int k;
		cout << "Do you wanna to add a player (1-no;2-yes) : ";
		cin >> k;

		if (k == 1)
		{
			cout << "OK.Lets go." << endl;
		}
		else if (k == 2)
		{

			string name1;
			int hp;
			int damage;
			int speed;
			int number;
			cout << "Enter hero name please : ";
			cin >> name1;
			cout << "Enter HP of hero : ";
			cin >> hp;
			cout << "Enter damage : ";
			cin >> damage;
			cout << "Enter speed : ";
			cin >> speed;
			heroes.emplace_back(Hero(name1, hp, damage, speed));
			cout << "Okey. You create a new hero : " << endl;
			cout << " Now hero name - " << name1 << ", HP - " << hp << ",  Damage - " << damage << ", and speed - " << speed << endl;
			cout << endl;
		}
	}

	void RemoteHero()
	{
		int f, h, j;

		cout << "Do you really want remote a hero ? (1-no;2-yes) : ";
		cin >> f;

		if (f == 1)
		{
			cout << "Okey.Lets go to game " << endl;
			cout << endl;
		}

		else if (f == 2)
		{
			cout << "Enter number of hero please : ";
			cin >> h;
			heroes.erase(heroes.begin() + h);
			cout << "Hero (" << h << ") - was remote ;  " << endl;
		}

		for (j = 0; j < heroes.size();j++)
		{
			cout << heroes[j].name << endl;
		}
	}

	void GetHeroByName()
	{

		int j;
		int HP = 100;
		int Damage = 120;
		int Speed = 90;

		for (j = 0;j < 10;j++)
		{
			HP += 20;
			Damage += 10;
			Speed += 15;

			string array[10] = { "Batman" , "Superman" , "Spider-Man" , "Hulk", "Iron Man " , "Captain Ameriña","Black Panter","Astronaft","Winter Soldier","Flash" };
			Hero hero1 = Hero(array[j], HP, Damage, Speed);
			heroes.push_back(hero1);
		}



		string name4;

		cout << "Enter name of hero which you want to search ? : ";
		cin >> name4;



		for (int i = 0; i < heroes.size(); i++)
		{

			if (name4 == heroes[i].name)
			{

				cout << "Your player - " << heroes[i].name << ", HP - " << heroes[i].HP << ", Damage - " << heroes[i].Damage << ", Speed - " << heroes[i].Speed << endl;
				break;
			}

		}

	}


};