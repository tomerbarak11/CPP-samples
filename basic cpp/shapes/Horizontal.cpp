#include "Image.h"
#include "Point.h"
#include "Color.h"
#include "Shape.h"
#include "Horizontal.h"
#include <iostream>

Horizontal::Horizontal(int a_length, Point a_point,Colors a_color)
:Shape(a_point,a_color)
,m_length(a_length)
{
}

void Horizontal::draw(Image& a_im,Colors a_c)
{
	for(int i=0;i<getLength();i++)
	{
		a_im.set(getStartPoint(),a_c);
		int y=getStartPointY();		
		setStartPointY(y+1);
	}
	resetStartPoint();
}

const int Horizontal::getLength() const
{
	return m_length;
}
