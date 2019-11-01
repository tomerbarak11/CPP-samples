#ifndef _CIRCLE_H_
#define _CIRCLE_H_
#include "Color.h"
#include "Shape.h"

class Circle:public Shape
{
	public:
		Circle(Point a_point,int a_radius,Colors a_color);
		void draw(Image& a_im,Colors a_c);
		const Point getCenter() const;
		const int getRadius() const;

	private:
		int m_radius;
		Point m_center;
};
#endif
