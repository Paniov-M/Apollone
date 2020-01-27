#pragma once
#include <iostream>
#include "Source.cpp"
#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <iterator>
#include <string>
#include <algorithm>
#include <random>
using namespace std;
`

int main()
{
	cout << "=============== HELLO!!! ================" << endl;
	cout << "=================My game.My rules.============== ";
	cout << "+++++++ You are welkome in Jumanji +++++++" << endl;
	cout << endl;


	cout << "%%%%%%%%%%%% MENU %%%%%%%%%%%%%%" << endl;
	cout << "1.Start Game." << endl;
	cout << "2.Settings to players." << endl;
	cout << "3.Settings to heroes." << endl;
	cout << "4.Quit." << endl;

	cout << endl;


	PlayerManager up;

	HeroManager hero;

	up.ListPlayers();

	hero.ListHeroes();

	GameManager cool;

	cool.ListPeople(up.players, hero.heroes);


	system("pause");

	return(0);

}
