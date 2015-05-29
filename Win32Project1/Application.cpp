#include "stdafx.h"
#include "Application.h"

#include "Resource.h"

using namespace ex04_Design::chapter3;

HINSTANCE Application::s_hInstance = nullptr;

Application::Application()
{}

Application::~Application()
{}


bool Application::Initialize(HINSTANCE hInstance, int nCmdShow, windowParam& param)
{
	// グローバル文字列を初期化しています。
	LoadString(hInstance, IDS_APP_TITLE, param.szTitle, sizeof(param.szTitle)/sizeof(param.szTitle[0]));
	LoadString(hInstance, IDC_WIN32PROJECT1, param.windowClassName, sizeof(param.windowClassName)/sizeof(param.windowClassName[0]));

	s_hInstance = hInstance;

	_RegisterClass(param);

	// アプリケーションの初期化を実行します:
	if (!_InitInstance(nCmdShow, param))
	{
		return false;
	}
	return true;
}


int Application::MessageLoop()
{

	MSG msg;
	HACCEL hAccelTable = LoadAccelerators(s_hInstance, MAKEINTRESOURCE(IDC_WIN32PROJECT1));

	// メイン メッセージ ループ:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}
	return (int)msg.wParam;

}

LRESULT CALLBACK Application::WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;

	switch (message)
	{
	case WM_COMMAND:
		wmId = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// 選択されたメニューの解析:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(s_hInstance, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, &Application::_About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: 描画コードをここに追加してください...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_KEYDOWN:
		break;
	case WM_KEYUP:
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}



bool Application::_InitInstance(int nCmdShow, const windowParam& param)
{
	HWND hWnd;

	hWnd = CreateWindow(param.windowClassName, param.szTitle, WS_OVERLAPPEDWINDOW,
						CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, s_hInstance, NULL);

	if (!hWnd)
	{
		return false;
	}

	ShowWindow(hWnd, nCmdShow);
	UpdateWindow(hWnd);

	return true;
}


bool Application::_RegisterClass(const windowParam& param)
{

	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = Application::WndProc;
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = s_hInstance;
	wcex.hIcon = LoadIcon(s_hInstance, MAKEINTRESOURCE(IDI_WIN32PROJECT1));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = MAKEINTRESOURCE(IDC_WIN32PROJECT1);
	wcex.lpszClassName = param.windowClassName;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	RegisterClassEx(&wcex);

	return true;
}


INT_PTR CALLBACK Application::_About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}