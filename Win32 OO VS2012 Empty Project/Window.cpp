#include "Window.h"
/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
Window::Window()
{
	
}

Window::~Window()
{
}

/////////////////////////////////////
// Member functions                  //
/////////////////////////////////////

INT_PTR CALLBACK dialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	return NULL;
}
LRESULT Window::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
		HINSTANCE h;
	switch(uMsg){
	case WM_MENUCOMMAND:
		DialogBox(h,MAKEINTRESOURCE(IDD_DIALOG1),NULL,dialogProc);
		break;
	}

	return AbstractWindow::MsgProc(hWnd, uMsg, wParam, lParam);
}

