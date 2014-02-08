#include "Size.h"
namespace jappieklooster{
	Size::Size(unsigned  width,unsigned  height){
		_width = width;
		_height = height;
	}

	void Size::SetHeight(unsigned  _height) {
		this->_height = _height;
	}

	unsigned  Size::GetHeight() const {
		return _height;
	}

	void Size::SetWidth(unsigned  _width) {
		this->_width = _width;
	}

	unsigned  Size::GetWidth() const {
		return _width;
	}
}
