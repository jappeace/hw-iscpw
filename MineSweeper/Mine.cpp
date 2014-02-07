#include "Mine.h"

namespace jappieklooster {

Mine::Mine(Point position)
{
	_position = position;
}

Mine::Mine(int x, int y){
	_position = Point(x, y);
}

Mine::~Mine(void)
{
}

}