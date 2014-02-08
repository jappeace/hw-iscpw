#ifndef Skeleton_H
#define Skeleton_H

#include <cstdlib>
#include "AbstractWindow.h"
#include "resource.h"
#include "Grid.h"
namespace jappieklooster {
class Window : public AbstractWindow
{
public:
	Window();
	~Window();
	void onPaint(Graphics* graphics);
	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
private:
	Grid _mineField;
};

}
#endif