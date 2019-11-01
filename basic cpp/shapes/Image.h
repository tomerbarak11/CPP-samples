#ifndef _IMAGE_H_
#define _IMAGE_H_
#define THOUSAND 1000
#include "Point.h"
#include "Color.h"
#include "IDrawingSurface.h"
#include <fstream>
#include <vector>

class Image:IDrawingSurface
{
	public:
		Image(int a_height,int a_width);
		const std::vector <std::vector<Colors> > getMatrix();
		void set(const Point a_p,const Colors a_c);
		void saveToFile(const char* fileName);
		const int getHeight() const;
		const int getWidth() const;
		bool inside(const Point a_point);

		
	private:
		int m_height;
		int m_width;
		std::vector <std::vector<Colors> > m_matrix;
		
};

#endif
