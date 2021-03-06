#include "Point.h"
namespace jappieklooster{
	Point::Point(): _x(), _y(){}
	Point::Point(int x, int y){
		_x = x;
		_y = y;
	}
	void Point::SetY(double _y) {
		this->_y = _y;
	}

	double Point::GetY() const {
		return _y;
	}

	void Point::SetX(double _x) {
		this->_x = _x;
	}

	double Point::GetX() const {
		return _x;
	}
}
