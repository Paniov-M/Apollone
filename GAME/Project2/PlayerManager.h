#pragma once
#include <iostream>
#include "Source.cpp"

class PlayerManager
{
public:
	friend class Session;

	vector<Player> players;

	void ListPlayers()
	{

		int rank = 100;


		for (int i = 0; i < 10; i++)
		{
			string arr[10] = { "Apollon","Grysha","Vlasuk","Loshara","Ira","Dana","Vanya","Yra","Jeka","Antoxa" };
			Player player = Player(arr[i], rank + rand() % 901, i + 1);
			players.push_back(player);
		}



		for (int i = 0; i < players.size(); i++)
		{
			cout << "Name of player - " << players[i].Name << " , Rank - " << players[i].rank << " , ID - " << i << endl;
		}

		cout << endl;
	}
};
