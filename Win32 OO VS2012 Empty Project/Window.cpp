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

void function(){

}
LRESULT Window::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
		HINSTANCE h;
		DLGPROC p;
	switch(uMsg){
	case WM_MENUCOMMAND:
		DialogBox(h,MAKEINTRESOURCE(IDD_DIALOG1),NULL,p);
		break;
	}

	return AbstractWindow::MsgProc(hWnd, uMsg, wParam, lParam);
}

