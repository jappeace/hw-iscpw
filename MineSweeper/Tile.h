/* 
 * File:   Tile.h
 * Author: jappie
 *
 * Created on January 31, 2014, 11:16 AM
 */

#ifndef TILE_H
#define	TILE_H
#include "Point.h"
namespace jappieklooster {
	class Tile {
	public:
		Tile(Point* p);
		Tile(int x, int y);
		void SetBottom(Tile* bottom);
		Tile* GetBottom() const;
		void SetRight(Tile* right);
		Tile* GetRight() const;
		void SetLeft(Tile* left);
		Tile* GetLeft() const;
		void SetTop(Tile* top);
		Tile* GetTop() const;
        Point* GetPosition() const;
	private:
		void init(Point* p);
		Point* _position;
		Tile* _top;
		Tile* _left;
		Tile* _right;
		Tile* _bottom;
	};
}
#endif	/* TILE_H */

