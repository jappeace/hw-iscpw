#include "Tile.h"
namespace jappieklooster{
	Tile::Tile(Point* p){
		init(p);
	}
	Tile::Tile(int x, int y){
		init(new Point(x, y));
	}
	void Tile::init(Point* p){
		_position = p;
	}
	void Tile::SetBottom(Tile* bottom) {
		this->_bottom = bottom;
	}

	Tile* Tile::GetBottom() const {
		return _bottom;
	}

	void Tile::SetRight(Tile* right) {
		this->_right = right;
	}

	Tile* Tile::GetRight() const {
		return _right;
	}

	void Tile::SetLeft(Tile* left) {
		this->_left = left;
	}

	Tile* Tile::GetLeft() const {
		return _left;
	}

	void Tile::SetTop(Tile* top) {
		this->_top = top;
	}

	Tile* Tile::GetTop() const {
		return _top;
	}

    Point* Tile::GetPosition() const {
    	return _position;
    }
}
