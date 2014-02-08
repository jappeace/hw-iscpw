#ifndef WIN_H
#define WIN_H

#include <windows.h>
#include <tchar.h>
#include "resource.h"

namespace jappieklooster {
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

}
#endif
