#include "Image.h"
#include "Color.h"
#include "Point.h"
#include "Shape.h"
#include "IDrawable.h"

Shape::Shape(Point a_point,Colors a_color)
:m_startPoint(a_point)
,m_color(a_color)
{
}

const Point Shape::getStartPoint() const
{
	return m_startPoint;
}

const int Shape::getStartPointX() const
{
	return m_startPoint.getX();
}

const int Shape::getStartPointY() const
{
	return m_startPoint.getY();
}

void Shape::setStartPointX(int a_x)
{
	return m_startPoint.setX(a_x);
}

void Shape::setStartPointY(int a_y)
{
	return m_startPoint.setY(a_y);
}

const Colors Shape::getColor() const
{
	return m_color;
}

void Shape::setColor(Colors a_color)
{
	m_color=a_color;
}

void Shape::resetStartPoint()
{
	setStartPointX(0);
	setStartPointY(0);
}
