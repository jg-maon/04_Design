// Win32Project1.cpp : アプリケーションのエントリ ポイントを定義します。
//

#include "stdafx.h"
#include "Win32Project1.h"

#include "Application.h"
#include <crtdbg.h>

using namespace ex04_Design::chapter3;

#define MAX_LOADSTRING 100
int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	// メモリリークチェック
	_CrtSetDbgFlag(_CRTDBG_LEAK_CHECK_DF | _CRTDBG_ALLOC_MEM_DF);
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

	Application application;
	Application::windowParam param = { L"title", L"WindowName" };
	if (!application.Initialize(hInstance, nCmdShow, param))
	{
		return -1;
	}
 	
	return application.MessageLoop();
}

