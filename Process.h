#include "pInc.h"
#pragma once

class Process
{
public:

	Process();
	~Process();

	template <class _R>
	_R readMem(DWORD addr)
	{
		_R x;
		ReadProcessMemory(pHandle, (LPVOID)addr, &x, sizeof(x), 0);
		return x;
	}

	template <class _W>
	_W writeMem(DWORD addr, _W value)
	{
		WriteProcessMemory(pHandle, (LPVOID)addr, &value, sizeof(value), 0);
		return 0;
	}

	uintptr_t getModule(DWORD procId, const char* modName);
	DWORD getProcess(const char* procName);
	HANDLE pHandle;
};

