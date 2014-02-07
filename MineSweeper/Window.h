#ifndef Skeleton_H
#define Skeleton_H

#include <cstdlib>
#include "AbstractWindow.h"
#include "resource.h"
namespace jappieklooster {
class Window : public AbstractWindow
{
public:
	Window();
	~Window();

	LRESULT MsgProc(HWND, UINT, WPARAM, LPARAM);
};

}
#endif
