#include<iostream>
#include<math.h>
#include<fstream>
#include<vector>;
using namespace std;

class One 
{

	vector<int>value;
public :

	void Try()
	{
		int num1;
		int num2;

		cout << "Enter num1 -";
		cin >> num1;
		cout << "Enter num2 - ";
		cin >> num2;

		cout << "num1 + num2 = " << num1 + num2 << endl;
		cout << "num1 / num2=" << num1 / num2 << endl;                          //цю дію не зробить ,якщо num2 = 0;


		try
		{
			if (num2 == 0)
				throw 123;                                            //якщо num2 = 0,то при помилці візьметься число 123 і далі...
		}
		catch (int i)                                                 //...вставиться замість int i;
		{
			cout << "Eror " << i << "- divide by 0 ;" << endl;        //і виведе на екран ;
		}

	}

	void Link()
	{
		int value;   //спочатку value=8;
		int & ref = value;                                            //потім ми робимо ссилку ( для цього обязково потрібно використовувати -&) & ref 
		                                                             //і вона буде вказувати на змінну value;

		cin >> ref;                                                 //можна ввести ref , але тоді value також зміниться ;

		cout << value << " - " << ref << endl;                      //також можливо вивести це на екран;
	}
};
struct Date
{
	int year;
};
struct Auto
{
	int speed;
	int wheels;
	string color;

	Date create;

/*	Auto bmw;
	bmw.color = "black";
	bmw.speed = 200;
	bmw.wheels = 4;
	bmw.create.year = 1980;
	cout << bmw.color << endl << bmw.speed << endl << bmw.create.year << endl;*/
};

void Enum()
{
	enum mall { parking = -1, hall, many_shops, roof };             //enum - для того щоб порахувати елементи (повивен бути поза функцією int main)
                                                          //так як parking = -1 ,то далі іде hall=0, many_shops=1,roof=2;

	int floor;
	bool exit = false;


	while (!exit)                                                //робимо цикл;
	{
		cout << "Enter floor please - ";                         //Вводимо цифру ,яка буде означати етажі;
		cin >> floor;

		switch (floor)                                              //робимо switch;
		{

		case parking:
			cout << "You are in the floor -1 . In the parking." << endl;
			break;

		case hall:
			cout << "You are in the floor 0 . In the hall." << endl;
			break;

		case many_shops:
			cout << "You are in the floor 1 . In the many shops." << endl;
			break;

		case roof:
			cout << "You are in the floor 2 . In the roof." << endl;
			break;

		default:cout << "Your floor is not exist!!!" << endl;

		}

		cout << "If you want continue to press 0 else if yu want to ending to press 1 - ";      //і в циклі так ,як exit=false то ми зробили щоб (!false) означаэ ,
		                                                                                        //0 закінчить цикл ,а 1 продовжить.
		cin >> exit;
	}

}

void Work_with_files()
{
	char text[50];                                                   //робимо масив з 50 символьних елементів;

	ofstream textFile("text1.txt");                                                       //ofstream - щоб зробити файл (ми назвали його text1.txt -тобто він буде текстовим)
	textFile << "Work with the file in c++";                                             //"textFile - це обєкт" і в нього тобто у файл text1.txt ми записали це речення; 
	textFile.close();                                                                   //після цього закрили файл;

	ifstream file("text1.txt");                                                         //ifstream-считує всю інформацію з файла textFile(text1.txt) у файл file(text1.txt);
	if (!file.is_open())                                                            //якщо наприклад такого файла немає то виведе помилку;
	{
		cout << "Eror!This file is not find !" << endl;
	}

	else
	{
		file.getline(text, 50);                              //записуємо інформацію з file у масив text типу char;
		cout << text << endl;                               //виводимо на екран;
		file.close();                                     //закриваємо файл;
	}
}

class First
{
protected:
	int value;


	First(int value)
	{
		this->value = value;
		cout << value << endl;
	}
};

class Second : public First
 {
 public:
	Second(int val):  First(val){}
 };

 class Third:public First
 {
 public:

	 Third(int val): First(val){}
 };
int main()
{
	Second(23);
	Third(45);
}