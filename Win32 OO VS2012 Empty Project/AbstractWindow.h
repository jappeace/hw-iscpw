#ifndef WIN_H
#define WIN_H

#include <windows.h>
#include "resource.h"
class AbstractWindow
{
protected:
	static HINSTANCE _hInstance;
	HWND  _hWnd;
	
	DWORD _PosX;
	DWORD _PosY;
	DWORD _dwWindowStyle;
	DWORD _dwExWindowStyle;
 	DWORD _dwCreationFlags;
	DWORD _dwCreationHeight;
	DWORD _dwCreationWidth;
	TCHAR * _strWindowTitle;
	HBRUSH _hbrWindowColor;
	HICON  _hIcon;
	HMENU  _hMenu;
	HACCEL _hAccelTable;

public:
	 AbstractWindow();
	 HRESULT Create();
	 int Run();
	 virtual ~AbstractWindow();
	 virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
};

//////////////////////////////////////////////////////////////////
// Static Initialisation
//////////////////////////////////////////////////////////////////
// what about avoid global state? Its imposibble now to open 2 windows...
// I used a singleton to prevent this...
static AbstractWindow * g_abstractWindow		= NULL;
HINSTANCE AbstractWindow::_hInstance = GetModuleHandle(NULL);

//////////////////////////////////////////////////////////////////
// Connectivity WIN32 -> Class (yes class not object)
//////////////////////////////////////////////////////////////////
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return g_abstractWindow->MsgProc(hWnd, uMsg, wParam, lParam);
}
#endif
