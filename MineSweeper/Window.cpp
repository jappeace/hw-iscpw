#include "Window.h"
namespace jappieklooster {
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


const unsigned width = 10;
const unsigned height = 10;
void onPaint(HDC* hdc, RECT* rect){

	int cube_width =  (rect->right- rect->left) /width;
	int cube_height = (rect->bottom - rect->top) /height;
	for(int x = 0; x < width; x++){
		for(int y = 0; y < height; y++){
			SetTextColor(*hdc, RGB(211,32,111));
			LPCSTR str;
			if(std::rand() % 100 > 70){
				str = "9";
			}else{
				str = "0";
			}

			TextOut(*hdc, x*cube_width, y*cube_height, str, 1);

		}
	}
}
}