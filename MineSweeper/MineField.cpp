#include "MineField.h"

namespace jappieklooster{
	bool MineField::isInMines(Tile& tile){
		return find(_mines->begin(), _mines->end(), tile)!=_mines->end();
	}
	void MineField::init(Grid* grid){
		_grid = grid;	
		unsigned width = _grid->getSize()->GetWidth();
		unsigned height = _grid->getSize()->GetHeight();
		unsigned mineCount =rand() % (int)( width*height * 0.3);
				
		_mines = new vector<Tile>(mineCount);

		for(int i = 0; i < mineCount; i++){
			Point p = Point(rand()%width, rand()%height);
			Tile target = *_grid->getTileAt(p);
			if(isInMines(target)){
				i--;	
			}else{
				_mines->push_back(target);
			}
		}

	}
	MineField::MineField(int width, int height){
		init(new Grid(width, height));
	}
	MineField::MineField(Grid* grid){
		init(grid);
	}
	MineField::MineField(void) {
		init(new Grid());
	}


	MineField::~MineField(void) {
		if(_grid){
			delete _grid;
		}
		if(_mines){
			delete _mines;
		}
	}

}