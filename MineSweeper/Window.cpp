#include "Window.h"
namespace jappieklooster {
/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
Window::Window() : _mineField(10,10) {}

Window::~Window()
{
}

/////////////////////////////////////
// Member functions                  //
/////////////////////////////////////

INT_PTR CALLBACK dialogProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam){
	return NULL;
}
void Window::onPaint(Graphics* g){

	const unsigned width = _mineField.getSize()->GetWidth();
	const unsigned height = _mineField.getSize()->GetHeight();
	int cube_width =  (_windowSize->right- _windowSize->left) / width;
	int cube_height = (_windowSize->bottom - _windowSize->top) / height;
	for(int x = 0; x < width; x++){
		for(int y = 0; y < height; y++){
			g->setTextColor(RGB(211,32,111));
			LPCSTR str;
			if(std::rand() % 100 > 70){
				str = "9";
			}else{
				str = "0";
			}
			g->drawStr(Point(x*cube_width, y*cube_height), str);
		}
	}
}

LRESULT Window::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return AbstractWindow::MsgProc(hWnd, uMsg, wParam, lParam);
}


}
