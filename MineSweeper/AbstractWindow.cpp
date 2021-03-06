#include "AbstractWindow.h"


namespace jappieklooster {
//////////////////////////////////////////////////////////////////
// Static Initialisation
//////////////////////////////////////////////////////////////////
// what about avoid global state? Its imposibble now to open 2 windows...
// I used a singleton to prevent this...
static AbstractWindow * g_abstractWindow		= NULL;
HINSTANCE AbstractWindow::_hInstance = GetModuleHandle(NULL);

//////////////////////////////////////////////////////////////////
// Connectivity WIN32 -> Class (yes class not object)
//////////////////////////////////////////////////////////////////
LRESULT CALLBACK WindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	return g_abstractWindow->MsgProc(hWnd, uMsg, wParam, lParam);
}
//////////////////////////////////////////////////////////////////
// Constructors/Destructors
//////////////////////////////////////////////////////////////////
AbstractWindow::AbstractWindow()
{
	g_abstractWindow = this;
	_hWnd = NULL;
	_dwCreationFlags		= 0L;
	_dwWindowStyle		= WS_OVERLAPPEDWINDOW;
	_dwExWindowStyle		= WS_EX_OVERLAPPEDWINDOW;
	_dwCreationFlags		= SW_SHOW;
	_PosX				= CW_USEDEFAULT;	
	_PosY				= CW_USEDEFAULT;	
	_dwCreationWidth		= CW_USEDEFAULT;
	_dwCreationHeight	= CW_USEDEFAULT;
	_hbrWindowColor		= (HBRUSH)(COLOR_WINDOW+1);
	_hIcon				= LoadIcon(_hInstance, (LPCTSTR)IDI_APPLICATION);
	_strWindowTitle		= _T("Win32 OO Skeleton Program...");
	_hMenu				= NULL; 	
}

AbstractWindow::~AbstractWindow()
{
}


//////////////////////////////////////////////////////////////////
// Functions
//////////////////////////////////////////////////////////////////
int AbstractWindow::Run()
{
	MSG msg;

	while (GetMessage(&msg, NULL, 0, 0)) 
	{
		if (!TranslateAccelerator(msg.hwnd, _hAccelTable, &msg)) 
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}

	}	
	return msg.wParam;
}

HRESULT AbstractWindow::Create()
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX); 

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)WindowProcedure;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= _hInstance;
	wcex.hIcon			= _hIcon;
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= _hbrWindowColor;
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDR_MENU1);
	wcex.lpszClassName	= _T("Skeleton");
	wcex.hIconSm		= NULL;

	::RegisterClassEx(&wcex);

	_hWnd = ::CreateWindowEx(_dwExWindowStyle,_T("Skeleton"), _strWindowTitle, _dwWindowStyle,
	  _PosX, _PosY, _dwCreationWidth, _dwCreationHeight, NULL, _hMenu, _hInstance, NULL);

	if (!_hWnd)
	{
	  return FALSE;
	}

	::ShowWindow(_hWnd, _dwCreationFlags);
	::UpdateWindow(_hWnd);

	return TRUE;

}

LRESULT AbstractWindow::MsgProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	PAINTSTRUCT paintStructure;
	Graphics* graphics = NULL;

	if (!_hWnd){
		_hWnd = hWnd;
	}

	switch (uMsg) 
	{
		case WM_COMMAND:
			onCommand(LOWORD(wParam),HIWORD(wParam));
			break;

		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		case WM_PAINT:
			_windowSize = new RECT();
			GetClientRect(hWnd, _windowSize);
			graphics = new Graphics();

			hdc = BeginPaint(hWnd, &paintStructure);
			graphics->setHDC(&hdc);

			onPaint(graphics);

			EndPaint(hWnd, &paintStructure);

			delete _windowSize;
			delete graphics;
			break;

		default:
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
	}
	return 0;
}

void AbstractWindow::repaint(){
	InvalidateRect(_hWnd, 0, TRUE);
}
}