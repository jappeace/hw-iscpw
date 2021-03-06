#include "Graphics.h"
namespace jappieklooster{

	Graphics::Graphics(void)
	{
	}


	Graphics::~Graphics(void)
	{
		// don't delete hdc, because this object dit not create it
	}

	void Graphics::setHDC(HDC* hdc){
		_hdc = hdc;
	}
	
	void Graphics::drawStr(Point& position, string str){
		this->drawStr(position,str.c_str(), str.length());
	}
	void Graphics::drawStr(Point& position, const char* str, int length){
		TextOut(*_hdc, position.GetX(), position.GetY(), str, length);
	}
	void Graphics::setTextColor(COLORREF color){
		SetTextColor(*_hdc, color);
	}
	void Graphics::setTextBackgroundColor(COLORREF color){
		SetBkColor(*_hdc, color);
	}
}