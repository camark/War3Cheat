// InjectorWar3.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "../../MyTools/MyTools/CLProcess.h"
#include "../../MyTools/MyTools/CLPublic.h"
#include <iostream>
int main()
{
	DWORD dwPid = MyTools::CLProcess::GetPid_For_ProcName(L"war3.exe");
	if (dwPid != NULL)
	{
		std::wcout << "dwPid=" << dwPid << std::endl;
		std::wcout << L"DLLPath=" << MyTools::CLPublic::MakeCurrentPath(L"\\War3Cheat.dll").c_str() << std::endl;
		MyTools::CLProcess::LoadRemoteDLL(dwPid, MyTools::CLPublic::MakeCurrentPath(L"\\War3Cheat.dll").c_str());

	}
    return 0;
}

