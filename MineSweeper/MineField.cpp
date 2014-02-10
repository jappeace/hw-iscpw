#include "MineField.h"

namespace jappieklooster{
	bool MineField::isInMines(Tile* tile){
		return find(_mines->begin(), _mines->end(), tile)!=_mines->end();
	}
	bool MineField::isInvisible(Tile* tile){
		// note the inverse, cause we keep track of the visible mines, better perfomance...
		return find(_visibleMines->begin(), _visibleMines->end(), tile)==_visibleMines->end();
	}
	void MineField::init(Grid* grid){
		_grid = grid;	
		unsigned width = _grid->getSize()->GetWidth();
		unsigned height = _grid->getSize()->GetHeight();
		unsigned mineCount =rand() % ((int)( width*height * 0.3));
				
		_mines = new vector<Tile*>();
		_visibleMines = new vector<Tile*>();
		for(int i = 0; i < mineCount; i++){
			Point p = Point(rand()%width, rand()%height);
			Tile* target = _grid->getTileAt(p);
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
		_grid = NULL;
		_mines = NULL;
	}
	Size* MineField::getSize() const{
		return _grid->getSize();
	}
	void MineField::paint(Graphics* g, Size& mineSize){
		_mineSize = mineSize;
		_graphics = g;
		_grid->traverseTiles(this);
	} 
	void MineField::receiveTile(Tile* tile){
		string str = StrConverter::intToString(this->determinDisplayValue(tile));
		Point* position = new Point(
			tile->GetPosition()->GetX() * _mineSize.GetWidth(), 
			tile->GetPosition()->GetY() * _mineSize.GetHeight()
		);
		this->paintBackgroundColor(tile);	
		_graphics->drawStr(*position, str);

		delete position;
	}


	int MineField::determinDisplayValue(Tile* tile){
		if (isInMines(tile)){
			return 9;
		}
		int result = 0;
		result += countMinesInAdjecentRow(tile->GetTop());
		result += countMinesInAdjecentRow(tile->GetBottom());
		if(tile->GetLeft() && isInMines(tile->GetLeft())){
			result++;
		}
		if(tile->GetRight() && isInMines(tile->GetRight())){
			result++;
		}
		return result;
	}
	int MineField::countMinesInAdjecentRow(Tile* tile){
		int result = 0;
		if(tile == NULL){
			return result;
		}
		if(isInMines(tile)){
			result++;
		}
		if(tile->GetLeft() && isInMines(tile->GetLeft())){
			result++;
		}
		if(tile->GetRight() && isInMines(tile->GetRight())){
			result++;
		}
		return result;
	}

	void MineField::paintBackgroundColor(Tile* tile){
		if(isInvisible(tile)){
			_graphics->setTextBackgroundColor(RGB(0,0,0));
			return;
		}
		if (isInMines(tile)){
			_graphics->setTextBackgroundColor(RGB(255,50,50));
			return;
		}
		_graphics->setTextBackgroundColor(RGB(150,150,255));
	}


}