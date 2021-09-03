#include "Hacks.h"

Process pro;
DWORD cHacks::proc = NULL,
      cHacks::client = NULL;
bool cHacks::isRunning = false;
struct Signatures
{
	const DWORD dwForceJump = 0x74AA48;
	const DWORD is_inAir = 0x6D6EE0;
}Sig;


void cHacks::Start()
{
	Prepare();
	while (true)
	{
		Bunnyhop();
		Sleep(10);
	}
}

bool cHacks::Prepare()
{
	while (!proc && !client)
	{
		proc = pro.getProcess("left4dead2.exe");
		client = pro.getModule(proc,"client.dll");
		cout << "Waiting for L4D2 process !!!\n";
		Sleep(500);
	}
	system("cls");
	return true;
}

void cHacks::Bunnyhop()
{
	while (true) {
		cout << "F1 - Toggle Bunnyhop !!!\n";
		if (GetAsyncKeyState(VK_F1) & 1) { isRunning = !isRunning; Beep(1000, 800); }
		if (isRunning) {
			if (GetAsyncKeyState(VK_SPACE) < 0) {
				int inAir = pro.readMem<int>(client + Sig.is_inAir);
				if (inAir == 0) {
					pro.writeMem<int>(client + Sig.dwForceJump, 5);
					Sleep(20);
					pro.writeMem<int>(client + Sig.dwForceJump, 4);
				}
			}
		}
		Sleep(1);
	}
}

