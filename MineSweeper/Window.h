#ifndef Skeleton_H
#define Skeleton_H

#include <cstdlib>
#include "AbstractWindow.h"
#include "resource2.h"
#include "MineField.h"
namespace jappieklooster {
	class Window : public AbstractWindow
	{
	public:
		Window();
		~Window();
		void onPaint(Graphics* graphics);
		void onCommand(int from, int command);
		LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
	private:
		MineField* _mineField;
	};

}
#endif
