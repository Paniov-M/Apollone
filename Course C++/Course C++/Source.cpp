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
		cout << "num1 / num2=" << num1 / num2 << endl;                          //�� �� �� ������� ,���� num2 = 0;


		try
		{
			if (num2 == 0)
				throw 123;                                            //���� num2 = 0,�� ��� ������� ��������� ����� 123 � ���...
		}
		catch (int i)                                                 //...���������� ������ int i;
		{
			cout << "Eror " << i << "- divide by 0 ;" << endl;        //� ������ �� ����� ;
		}

	}

	void Link()
	{
		int value;   //�������� value=8;
		int & ref = value;                                            //���� �� ������ ������ ( ��� ����� �������� ������� ��������������� -&) & ref 
		                                                             //� ���� ���� ��������� �� ����� value;

		cin >> ref;                                                 //����� ������ ref , ��� ��� value ����� �������� ;

		cout << value << " - " << ref << endl;                      //����� ������� ������� �� �� �����;
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
	enum mall { parking = -1, hall, many_shops, roof };             //enum - ��� ���� ��� ���������� �������� (������� ���� ���� �������� int main)
                                                          //��� �� parking = -1 ,�� ��� ��� hall=0, many_shops=1,roof=2;

	int floor;
	bool exit = false;


	while (!exit)                                                //������ ����;
	{
		cout << "Enter floor please - ";                         //������� ����� ,��� ���� �������� ����;
		cin >> floor;

		switch (floor)                                              //������ switch;
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

		cout << "If you want continue to press 0 else if yu want to ending to press 1 - ";      //� � ���� ��� ,�� exit=false �� �� ������� ��� (!false) ������� ,
		                                                                                        //0 �������� ���� ,� 1 ����������.
		cin >> exit;
	}

}

void Work_with_files()
{
	char text[50];                                                   //������ ����� � 50 ���������� ��������;

	ofstream textFile("text1.txt");                                                       //ofstream - ��� ������� ���� (�� ������� ���� text1.txt -����� �� ���� ���������)
	textFile << "Work with the file in c++";                                             //"textFile - �� ����" � � ����� ����� � ���� text1.txt �� �������� �� �������; 
	textFile.close();                                                                   //���� ����� ������� ����;

	ifstream file("text1.txt");                                                         //ifstream-����� ��� ���������� � ����� textFile(text1.txt) � ���� file(text1.txt);
	if (!file.is_open())                                                            //���� ��������� ������ ����� ���� �� ������ �������;
	{
		cout << "Eror!This file is not find !" << endl;
	}

	else
	{
		file.getline(text, 50);                              //�������� ���������� � file � ����� text ���� char;
		cout << text << endl;                               //�������� �� �����;
		file.close();                                     //��������� ����;
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