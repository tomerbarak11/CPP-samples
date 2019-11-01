#include "Image.h"
#include "Point.h"
#include "Circle.h"
#include "Color.h"
#include "Shape.h"
#include <iostream>
#include <cmath>

Circle::Circle(Point a_point,int a_radius,Colors a_color)
:Shape(a_point,a_color)
,m_radius(a_radius)
,m_center(a_point)
{
}

void Circle::draw(Image& a_im,Colors a_c)
{
	int x = m_radius;
	int y = 0;	
	int err = 0;
	while(x>=y)
	{
		Point toDraw1(getStartPointX()+x,getStartPointY()+y);
		a_im.set(toDraw1,a_c);
		
		Point toDraw2(getStartPointX()+y,getStartPointY()+x);
		a_im.set(toDraw2,a_c);
		
		Point toDraw3(getStartPointX()-y,getStartPointY()+x);
		a_im.set(toDraw3,a_c);
		
		Point toDraw4(getStartPointX()-x,getStartPointY()+y);
		a_im.set(toDraw4,a_c);
		
		Point toDraw5(getStartPointX()-x,getStartPointY()-y);
		a_im.set(toDraw5,a_c);
		
		Point toDraw6(getStartPointX()-y,getStartPointY()-x);
		a_im.set(toDraw6,a_c);
		
		Point toDraw7(getStartPointX()+y,getStartPointY()-x);
		a_im.set(toDraw7,a_c);
		
		Point toDraw8(getStartPointX()+x,getStartPointY()-y);
		a_im.set(toDraw8,a_c);		
		
		if (err <= 0)
		{
			y += 1;
			err += 2*y + 1;
		}

		if (err > 0)
		{
			x -= 1;
			err -= 2*x + 1;
		}
	}
	
	
	resetStartPoint();
}

const Point Circle::getCenter() const
{
	return m_center;
}

const int Circle::getRadius() const
{
	return m_radius;
}



