#include "stdafx.h"
#include "Menu.h"
#include "FileHandle.h"
using namespace std;
string one, two, three, four, five, six, seven;
FileHandle filehandle;

Menu::Menu()
{
	one = "   ";
	two = "   ";
	three = "   ";
	four = "   ";
	five = "   ";
	six  = "   ";
	seven = "   ";
	index = 1;
}


Menu::~Menu()
{
}

void Menu::GUI() //Graphical interface
{
		Index();
		cout << "   FinanceAPP" << endl << endl;
		cout << one << "Income" << endl;
		cout << two << "Expenses" << endl;
		cout << three << "Save records" << endl;
		cout << four << "All transactions and account balance" << endl;
		cout << five << "Initialize" << endl;
		cout << six << "Remove last added income" << endl;
		cout << seven << "Remove last added expense" << endl;
}

void Menu::CheckChar() //Moving in menu
{
	char in = getch();
	if (in == 72) {
		MoveCurUp();
	}
	if (in == 80) {
		MoveCurDown();
	}
	if (in == 27) {
		exit(0);
	}
	if (in == '\r') {
		switch ( index ) {
		case 1:
			system("cls");
			filehandle.Incomes();
			break;
		case 2:
			system("cls");
			filehandle.Expenses();
			break;
		case 3:
			system("cls");
			filehandle.save();
			system("pause");
			break;
		case 4:
			system("cls");
			cout << "   Finance APP" << endl << endl;
			filehandle.read();
			system("pause");
			break;
		case 5:
			filehandle.Initialize();
			break;
		case 6:
			system("cls");
			filehandle.remove_last_inc();
			system("pause");
			break;
		case 7:
			system("cls");
			filehandle.remove_last_exp();
			system("pause");
			break;
		}
	}
	this_thread::sleep_for(chrono::milliseconds(20));
	system("cls");
}

void Menu::MoveCurUp() //Cursor up
{
	if (index == 1) {
		index = 7;
	}
	else {
		index -= 1;
	}
	
}

void Menu::MoveCurDown() //Cursor down
{
	if (index == 7) {
		index = 1;
	}
	else {
		index += 1;
	}
}

void Menu::Index() //Cursor location checking
{
	if (index == 1) {
		one = "==>";
		seven = "   ";
		two = "   ";
	}
	if (index == 2) {
		two = "==>";
		one = "   ";
		three = "   ";
	}
	if (index == 3) {
		three = "==>";
		two = "   ";
		four = "   ";
	}
	if (index == 4) {
		four = "==>";
		three = "   ";
		five = "   ";
	}
	if (index == 5) {
		five = "==>";
		six = "   ";
		four = "   ";
	}
	if (index == 6) {
		six = "==>";
		seven = "   ";
		five = "   ";
	}
	if (index == 7) {
		seven = "==>";
		six = "   ";
		one = "   ";
	}
}


