#ifndef WIN_H
#define WIN_H

#include <windows.h>
#include <tchar.h>
#include "resource.h"
#include "Graphics.h"

namespace jappieklooster {
	/** 
	* This class tries to handle all the win32 open window crap.
	* that is initilize a window and capture a event loop.
	
	* Because the event loop expects a function pointer this class is in 
	* practise a singleton. You can initilize more of this class, but the binding
	* from the function pointer to the member function gets overwritten, so the first
	* window's event loop, continues but gets no more messages.
	*/
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

		LPRECT _windowSize;
	public:
		 AbstractWindow();
		 HRESULT Create();
		 int Run();
		 virtual ~AbstractWindow();
		 virtual LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
		 void repaint();
		 /**
		 * This method forces subclasses to implement the onpaint
		 */
		 virtual void onPaint(Graphics* graphics) = 0; // this also makes the class abstract
		 virtual void onCommand(int from, int command) = 0;
	};

}
#endif
