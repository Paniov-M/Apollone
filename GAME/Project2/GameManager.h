#pragma once
#include <iostream>
#include "Source.cpp"
class GameManager : Player, Hero, PlayerManager, HeroManager
{
	vector<Player>players;
	vector<Hero>heroes;
	vector<GameManager>teams;
	vector<GameManager>TeamBlue;
	vector<GameManager>TeamRed;
	vector<GameManager>Winner;
	vector<GameManager>Looser;


public:

	int i;

	int hpBlue = 0;

	int damageBlue = 0;

	int  hpRed = 0;

	int damageRed = 0;

	Player player;
	Hero hero;

	PlayerManager list;

	HeroManager list1;
	GameManager() {

	}

	GameManager(Player& player, Hero& hero)
	{
		this->player = player;
		this->hero = hero;
	}




	void ListPeople(vector<Player>& players, vector<Hero>& heroes)
	{

		for (i = 0;i < 10;i++)
		{
			GameManager people = GameManager(players[i], heroes[i]);
			teams.push_back(people);
		}

		for (i = 0;i < 10;i++)
		{
			cout << teams[i].hero.name << endl;
		}

		cout << endl;

		srand(time(NULL));

		for (i = 0;i < 10;i++)
		{
			random_shuffle(teams.begin(), teams.end());
		}

		for (i = 0;i < 5;i++)
		{
			GameManager blue = GameManager(teams[i].player, teams[i].hero);

			TeamBlue.push_back(blue);
		}

		for (int j = 5;j < 10;j++)
		{

			GameManager red = GameManager(teams[j].player, teams[j].hero);

			TeamRed.push_back(red);
		}

		cout << "########## Team Blue #############" << endl;

		for (i = 0;i < 5;i++)
		{
			cout << TeamBlue[i].hero.name << "----> " << TeamBlue[i].player.Name << endl;
		}

		cout << "########### Team Red #############" << endl;

		for (i = 0;i < 5;i++) {

			cout << TeamRed[i].hero.name << "----> " << TeamRed[i].player.Name << endl;
		}

		cout << endl;
		cout << endl;



		for (i = 0;i < 5;i++)
		{
			hpBlue += TeamBlue[i].hero.HP;
			damageBlue += TeamBlue[i].hero.Damage;

			hpRed += TeamRed[i].hero.HP;
			damageRed += TeamRed[i].hero.Damage;
		}

		if (hpBlue - damageRed > hpRed - damageBlue)
		{

			cout << "Winner - TeamBlue !!!" << endl;

			for (i = 0;i < 5;i++)
			{
				TeamBlue[i].player.rank += 25;
				TeamRed[i].player.rank -= 25;
			}

			for (i = 0; i < 5; i++) {

				GameManager winner = TeamBlue[i];

				Winner.push_back(winner);


				GameManager looser = TeamRed[i];

				Looser.push_back(looser);

			}

			cout << "::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
			for (i = 0;i < 5;i++)
			{
				cout << Winner[i].player.Name << " now rank ---> " << Winner[i].player.rank << endl;

				cout << endl;

			}
			cout << endl;
			cout << "LOOSER:" << endl;
			cout << "::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
			cout << endl;

			for (i = 0;i < 5;i++)
			{


				cout << Looser[i].player.Name << "  " << " fall ---->" << Looser[i].player.rank << endl;


			}

		}


		else if (hpBlue - damageRed < hpRed - damageBlue)
		{
			cout << "Winner - TeamRed !!!" << endl;

			for (i = 0;i < 5;i++)
			{
				TeamBlue[i].player.rank -= 25;
				TeamRed[i].player.rank += 25;
			}

			for (i = 0; i < 5; i++) {

				GameManager winner = TeamRed[i];

				Winner.push_back(winner);


				GameManager looser = TeamRed[i];

				Looser.push_back(looser);

			}

			cout << endl;

			cout << "::::::::::::::::::::::::::::::::::::::::::::::::" << endl;

			for (i = 0;i < 5;i++)
			{
				cout << Winner[i].player.Name << "  " << " now rank ---> " << Winner[i].player.rank << endl;

			}

			cout << endl;

			cout << "LOOSER:" << endl;
			cout << "::::::::::::::::::::::::::::::::::::::::::::::::" << endl;
			cout << endl;
			for (i = 0;i < 5;i++)
			{

				cout << Looser[i].player.Name << "  " << " fall ---->" << Looser[i].player.rank << endl;
				cout << endl;
			}

		}
	}

};