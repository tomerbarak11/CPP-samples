#ifndef _IDRAWABLE_H_
#define _IDRAWABLE_H_
#include "Image.h"
#include "Color.h"
#include "IDrawingSurface.h"

class IDrawable
{
	public:
		virtual ~IDrawable(){}
		virtual void draw(Image& a_im,Colors a_color)=0; 
};

#endif
