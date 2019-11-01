#ifndef _SHAPE_H_
#define _SHAPE_H_
#include "Image.h"
#include "Color.h"
#include "Point.h"
#include "IDrawable.h"

class Shape: public IDrawable
{
	public:
		Shape(Point a_point,Colors a_color);
		virtual ~Shape(){}
		virtual void draw(Image& image, Colors color)=0;
		const Point getStartPoint() const;
		const int getStartPointX() const;
		const int getStartPointY() const;
		const Colors getColor() const;

		void setStartPointX(int a_x);
		void setStartPointY(int a_y);
		void setColor(Colors a_color);
		void resetStartPoint();
	private:
		Point m_startPoint;
		Colors m_color;


};

#endif
