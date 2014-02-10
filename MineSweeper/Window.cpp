#include "Window.h"
namespace jappieklooster {
const int fieldWidth = 20;
const int fieldHeight = 20;
/////////////////////////////////////
// Constructors / Destructors      //
/////////////////////////////////////
Window::Window() {
	srand (time(NULL)); // because randomness needs to be initilized...
	_mineField = new MineField(fieldWidth,fieldHeight);
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
	switch(from){
	case ID_FILE_NEWGAME:
		delete _mineField;
		_mineField = new MineField(fieldHeight,fieldWidth);
		this->repaint();
		break;
	case ID_HELP_ABOUT:
		MessageBox(
			_hWnd,
			// message:
			"Copyright Jappie Klooster, Program version: Awesome",
			// title:
			"Licensed under GPL v3",
			MB_OK | MB_ICONEXCLAMATION
		);
		break;
	case ID_FILE_EXIT:
		PostQuitMessage(0);
		break;
	}
}
LRESULT Window::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return AbstractWindow::MsgProc(hWnd, uMsg, wParam, lParam);
}


}
