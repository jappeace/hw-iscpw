#pragma once
#include "Point.h"
namespace jappieklooster{
	class Mine
	{
	public:
		Mine(Point position);
		Mine(int x, int y);
		~Mine();
	private:
		Point _position;
	};

}
