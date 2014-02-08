#include "Tile.h"

namespace jappieklooster {

Tile::Tile(Point position)
{
	_position = position;
}

Tile::Tile(int x, int y){
	_position = Point(x, y);
}

Tile::~Tile(void)
{
}

}