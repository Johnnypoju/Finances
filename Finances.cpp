// Finances.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Menu.h"
#include <Windows.h>

using namespace std;


int main()
{
	SetConsoleOutputCP(1252); //Enabling ä,ö,å.
	SetConsoleCP(1252);
	Menu menu;
	while (1) {
		menu.GUI();
		menu.CheckChar();
	}
	return 0;
}

