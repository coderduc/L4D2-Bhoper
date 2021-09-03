#include "pInc.h"
#include "Process.h"

class cHacks
{
public:

	static bool Prepare();
	static void Bunnyhop();
	static void Start();

	static DWORD proc, client;
	static bool isRunning;
};