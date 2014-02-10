#include "Window.h"
namespace jappieklooster {
/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
Window::Window() {
	srand (time(NULL)); // because randomness needs to be initilized...
	_mineField = new MineField(10,10);
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
void Window::onPaint(Graphics* g){
	_mineField->paint(g,
		// calculate the size of the individual mines
		Size(
			(_windowSize->right  - _windowSize->left)	/ _mineField->getSize()->GetWidth(),
			(_windowSize->bottom - _windowSize->top)	/ _mineField->getSize()->GetHeight()
		)
	);
}

void Window::onCommand(int from, int command){
	if(ID_FILE_NEWGAME == from){
		delete _mineField;
		_mineField = new MineField(10,10);
		this->repaint();
	}
}
LRESULT Window::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return AbstractWindow::MsgProc(hWnd, uMsg, wParam, lParam);
}


}
