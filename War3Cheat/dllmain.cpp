// dllmain.cpp : Defines the entry point for the DLL application.
#include "stdafx.h"
#include "Expr.h"
#include <MyTools/CmdLog.h>
#include <MyTools/Log.h>
#include <MyTools/CLPublic.h>

#define _SELF L"dllmain.cpp"
DWORD WINAPI _WorkThread(LPVOID lParam)
{
	MyTools::CCmdLog::GetInstance().Run(L"War3Cheat", CExpr::GetInstance().GetVec());
	MyTools::CLog::GetInstance().SetClientName(L"War3Cheat", MyTools::CLPublic::MakeCurrentPath(L"\\Logs\\"));
	return 0;
}

BOOL APIENTRY DllMain( HMODULE hModule,
                       DWORD  ul_reason_for_call,
                       LPVOID lpReserved
                     )
{
	static HANDLE hThread = NULL;
    switch (ul_reason_for_call)
    {
    case DLL_PROCESS_ATTACH:
		if (hThread == NULL)
		{
			hThread = ::CreateThread(NULL, NULL, (LPTHREAD_START_ROUTINE)_WorkThread, NULL, NULL, NULL);
		}
		break;
    case DLL_THREAD_ATTACH:
    case DLL_THREAD_DETACH:
    case DLL_PROCESS_DETACH:
        break;
    }
    return TRUE;
}

