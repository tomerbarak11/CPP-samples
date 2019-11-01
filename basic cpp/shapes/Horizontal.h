#ifndef _HORIZONTAL_H_
#define _HORIZONTAL_H_
#include "Color.h"
#include "Shape.h"

class Horizontal:public Shape
{
	public:
		Horizontal(int a_length,Point a_p,Colors a_color);
		void draw(Image& a_im,Colors a_c);
		const int getLength() const;
	private:
		int m_length;
};
#endif
