#pragma once
#include <iostream>
#include "Source.cpp"
class AboutPlayer
{

	vector<Player>players;

public:

	void ChangeName()
	{
		string Name1;
		int choice;

		cout << "Do you wanna change your current name(1-no ,2 -yes )";
		cin >> choice;

		if (choice == 1)
		{
			cout << "OK" << endl;
		}
		else if (choice == 2)
		{
			cout << "Enter new name please -";
			cin >> Name1;
			cout << "Ok.Your new name is -" << Name1 << endl;
		}

	}

	void AddPlayer()
	{
		int g;
		cout << "Do you wanna to add a player (1-no;2-yes) : ";
		cin >> g;

		if (g == 1)
		{
			cout << "OK.Lets go." << endl;
		}
		else if (g == 2)
		{
			int i = players.size() - 1;
			int id = players[i].id;
			string name = "Name";
			players.emplace_back(Player(name, 20, id + 1));
			cout << " You add a new player : " << endl;
			cout << "Now your name - " << name << ", Rank - " << 20 << ", ID - " << id << endl;
		}
	}

	void RemotePlayer()
	{
		int e;
		cout << "Do you want remote player (1-no;2-yes) : ";
		cin >> e;

		cout << endl;

		if (e == 1)
		{
			cout << "Ok.It is fine." << endl;
		}

		else if (e == 2)
		{
			int ID;
			cout << "To remote player you shoud enter ID of this player : ";
			cin >> ID;
			players.erase(players.begin() + ID);
			cout << "Player (" << ID << ") - was remote ;  " << endl;
		}

	}

	void GetPlayerByName()
	{

		string name2;

		cout << "Enter name of player which you want to search ? : ";
		cin >> name2;
		for (int i = 0; i < players.size(); i++)
		{

			if (name2 == players[i].Name)
			{
				cout << "Your player - " << players[i].Name << ", Rank - " << players[i].rank << ", ID - " << players[i].id << endl;
				goto other;
			}
		}

		cout << "Your player not exist " << endl;
	other:
		cout << endl;
	}

	void GetPlayerById()
	{
		int name3;

		cout << "Enter ID of player which you want to search ? : ";
		cin >> name3;
		for (int i = 0; i < players.size(); i++)
		{

			if (name3 == players[i].id)
			{
				cout << "Your player - " << players[i].Name << ", Rank - " << players[i].rank << ", ID - " << players[i].id << endl;
				goto other;
			}
		}

		cout << "Your player not exist " << endl;
	other:
		cout << endl;
	}
};