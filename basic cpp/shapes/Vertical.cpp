#include "Image.h"
#include "Point.h"
#include "Vertical.h"
#include "Color.h"
#include "Shape.h"
#include <iostream>

Vertical::Vertical(int a_length,Point a_point,Colors a_color)
:Shape(a_point,a_color)
,m_length(a_length)
{
}

void Vertical::draw(Image& a_im, Colors a_c)
{
	for(int i=0;i<getLength();i++)
	{
		a_im.set(getStartPoint(),a_c);
		int x=getStartPointX();		
		setStartPointX(x+1);		
	}
	resetStartPoint();
}

const int Vertical::getLength() const
{
	return m_length;
}
