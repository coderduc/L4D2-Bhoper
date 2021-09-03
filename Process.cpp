#include "Process.h"

Process::Process()
{
	pHandle = NULL;
}

Process::~Process()
{
	CloseHandle(pHandle);
}

uintptr_t Process::getModule(DWORD procId, const char* modName)
{
	HANDLE hModule = CreateToolhelp32Snapshot(TH32CS_SNAPMODULE | TH32CS_SNAPMODULE32, procId);
	MODULEENTRY32 mod;
	mod.dwSize = sizeof(MODULEENTRY32);
	do
	{
		if (!_stricmp(mod.szModule, modName))
		{
			CloseHandle(hModule);
			return (DWORD)mod.modBaseAddr;
		}
	} while (Module32Next(hModule, &mod));
	return 0;
}

DWORD Process::getProcess(const char* procName)
{
	DWORD pid = 0;
	HANDLE snapshot = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
	if (snapshot != INVALID_HANDLE_VALUE)
	{
		PROCESSENTRY32 entry;
		entry.dwSize = sizeof(entry);
		do
		{
			if (!_stricmp(entry.szExeFile, procName))
			{
				pid = entry.th32ProcessID;
				CloseHandle(snapshot);
				pHandle = OpenProcess(PROCESS_ALL_ACCESS, false, pid);
			}
		} while (Process32Next(snapshot, &entry));
	}
	return pid;
}
