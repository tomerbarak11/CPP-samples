#ifndef IDRAWINGSURFACE_H
#define IDRAWINGSURFACE_H
#include "Point.h"
#include "Color.h"

class IDrawingSurface
{
	public:
		~IDrawingSurface(){}
		virtual bool inside(Point a_point)=0;
		virtual void set(const Point a_point,Colors a_color)=0;
};

#endif
