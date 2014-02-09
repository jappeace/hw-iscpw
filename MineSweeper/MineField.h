#pragma once
#include "Grid.h"
#include "Graphics.h"
namespace jappieklooster{

	class MineField
	{
	public:
		MineField(int width, int height);
		MineField(Grid* g);
		MineField(void);
		~MineField(void);
		void paint(Graphics* g);
	private:
		vector<Tile>* _mines;
		Grid* _grid;
		void init(Grid* g);
		bool isInMines(Tile& tile);
	};


}