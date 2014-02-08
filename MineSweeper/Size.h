/* 
 * File:   Size.h
 * Author: jappie
 *
 * Created on January 31, 2014, 7:26 PM
 */

#ifndef SIZE_H
#define	SIZE_H
namespace jappieklooster {
	class Size {

	private:
		unsigned  _width;
		unsigned  _height;

	public:
		Size(unsigned  width,unsigned  height);
		void SetHeight(unsigned  _height);
		unsigned  GetHeight() const;
		void SetWidth(unsigned  _width);
		unsigned  GetWidth() const;
	};
}
#endif	/* SIZE_H */

