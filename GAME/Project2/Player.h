#pragma once
#include <iostream>
#include "Source.cpp"
class Player
{

public:

	vector<Player>players;
	vector<TeamPart>TeamRed;
	vector<TeamPart>TeamBlue;

	string Name;
	int rank;
	int id;


	Player()
	{}

	Player(string Name, int Rang, int ID)
	{
		this->Name = Name;
		rank = Rang;
		id = ID;
	}



	void stats(string you_Name, int you_rank, int you_id)
	{
		Name = you_Name;
		rank = you_rank;
		id = you_id;
	}

	void set()
	{
		cout << "Player name - " << Name << "\n Rank - " << rank << "\n ID - " << id << endl;
	}

};
