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

class TeamPart;

class Player
{

public:

	vector<Player>players;
	vector<TeamPart>TeamRed;
	vector<TeamPart>TeamBlue;

	string Name;
	int rank;
	int id;

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

	Hero(string name, int hero_hp, int hero_damage, int hero_speed)                             //конструктор;
	{
		this->name = name;
		HP = hero_hp;
		Damage = hero_damage;
		Speed = hero_speed;

	}

};


class PlayerManager
{
public:
	friend class Session;

	vector<Player> players;

	void ListPlayers()
	{

		int rank = 100;


		for (int i = 0; i < 10; i++)                                                           //робимо в циклі вектор з 10 елементів з іменами;
		{
			string arr[10] = { "Apollon","Grysha","Vlasuk","Loshara","Ira","Dana","Vanya","Yra","Jeka","Antoxa" };
			Player player = Player(arr[i], rank + rand() % 901, i + 1);
			players.push_back(player);                                                     //Далі просто робимо обєкт player,який дорівнює конструктору Player;
		}                                                                                  //потім заганяємо всі елементи у вектор;



		for (int i = 0; i < players.size(); i++)
		{
			cout << "Name of player - " << players[i].Name << " , Rank - " << players[i].rank << " , ID - " << i << endl;
		}

		cout << endl;


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
			string array[10] = { "Batman" , "Superman" , "Spider-Man" , "Hulk", "Iron Man " , "Captain Ameriсa","Black Panter","Astronaft","Winter Soldier","Flash" };
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

			string array[10] = { "Batman" , "Superman" , "Spider-Man" , "Hulk", "Iron Man " , "Captain Ameriсa","Black Panter","Astronaft","Winter Soldier","Flash" };
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


class TeamPart : Player, Hero, PlayerManager, HeroManager
{
	vector<Player>players;
	vector<Hero>heroes;
	vector<TeamPart>teams;
	vector<TeamPart>TeamBlue;
	vector<TeamPart>TeamRed;
	vector<TeamPart>Winner;
	vector<TeamPart>Looser;


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
	TeamPart() {

	}

	TeamPart(Player& player, Hero& hero)
	{
		this->player = player;
		this->hero = hero;
	}




	void ListPeople(vector<Player>& players, vector<Hero>& heroes)
	{

		for (i = 0;i < 10;i++)
		{
			TeamPart people = TeamPart(players[i], heroes[i]);
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
			TeamPart blue = TeamPart(teams[i].player, teams[i].hero);

			TeamBlue.push_back(blue);
		}

		for (int j = 5;j < 10;j++)
		{

			TeamPart red = TeamPart(teams[j].player, teams[j].hero);

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

				TeamPart winner = TeamBlue[i];

				Winner.push_back(winner);


				TeamPart looser = TeamRed[i];

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

				TeamPart winner = TeamRed[i];

				Winner.push_back(winner);


				TeamPart looser = TeamRed[i];

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

		TeamPart cool;

		cool.ListPeople(up.players, hero.heroes);
	

	system("pause");

	return(0);

}