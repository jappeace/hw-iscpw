#ifndef Skeleton_H
#define Skeleton_H

#include "AbstractWindow.h"
#include "resource.h"
class Window : public AbstractWindow
{
public:
	Window();
	~Window();

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
};

#endif
