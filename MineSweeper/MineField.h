#pragma once
#include <algorithm>
#include <time.h>
#include "Grid.h"
#include "Graphics.h"
namespace jappieklooster{

	class MineField : IGridTraveller
	{
	public:
		MineField(int width, int height);
		MineField(Grid* g);
		MineField(void);
		~MineField(void);
		void paint(Graphics* g, Size& mineSize);
		void receiveTile(Tile* tile);
        Size* getSize() const;
		int countMinesInAdjecentRow(Tile* tile);
	private:
		Graphics* _graphics;
		Size _mineSize;
		vector<Tile*>* _mines;
		Grid* _grid;
		void init(Grid* g);
		bool isInMines(Tile& tile);
		int determinDisplayValue(Tile* receivedTile);
	};


}