#pragma once
#include "Point.h"
namespace jappieklooster{
	class Tile
	{
	public:
		Tile(Point position);
		Tile(int x, int y);
		~Tile();
	private:
		Point _position;
	};

}
