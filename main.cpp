#include "Hacks.h"

Process pr;
cHacks cH;

void ConsoleSettings()
{
	SetConsoleTitleA("L4D2 Bhoper v1.2");
	HANDLE hHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hHandle, 14);
	system("cls");
	cout << "F1 - Toggle Bunnyhop !!!\n";
}

int main()
{
	//Settings for console
	ConsoleSettings();
	//Starting cheat
	cH.Start();
	//System
	system("pause");
	return 0;
}