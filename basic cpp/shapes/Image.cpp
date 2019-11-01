#include "Image.h"
#include "Color.h"
#include <fstream>
#include <iostream>
#include "IDrawingSurface.h"
static const char* s_BLACK_IN_RGB="0 0 0";
static const char* s_GREEN_IN_RGB="0 255 0";
static const char* s_RED_IN_RGB="255 0 0";
static const char* s_BLUE_IN_RGB="0 0 255";
static const char* s_CYAN_IN_RGB="0 255 255";
static const char* s_MAGENTA_IN_RGB="255 0 255";
static const char* s_YELLOW_IN_RGB="255 255 0";
static const char* s_WHITE_IN_RGB="255 255 255";

static const char* getRGBNumbers(Colors a_color)
{
	switch(a_color)
	{
		case BLACK:
			return s_BLACK_IN_RGB;
		case GREEN:
			return s_GREEN_IN_RGB;
		case RED:
			return s_RED_IN_RGB;
		case BLUE:
			return s_BLUE_IN_RGB;
		case CYAN:
			return s_CYAN_IN_RGB;
		case MAGENTA:
			return s_MAGENTA_IN_RGB;		
		case YELLOW:
			return s_YELLOW_IN_RGB;																		
		case WHITE:
			return s_WHITE_IN_RGB;
		default:
			return s_WHITE_IN_RGB;
	}
}

Image::Image(int a_height,int a_width)
:m_height(a_height)
,m_width(a_width)
,m_matrix(m_height)
{
	for(int i=0;i<m_height;i++)
	{
		m_matrix[i].resize(m_width,BLACK);
	}	
}

const std::vector <std::vector<Colors> > Image::getMatrix()
{
	return m_matrix;
}

const int Image::getHeight() const
{
	return m_height;
}

const int Image::getWidth() const
{
	return m_width;
}

void Image::set(const Point a_p,const Colors a_c)
{
	if(inside(a_p)==true)
	{
		m_matrix[a_p.getX()][a_p.getY()]=a_c;
		return;
	}
	return;
}

void Image::saveToFile(const char* fileName)
{
	std::ofstream fout;	
	fout.open(fileName);
	fout<<"P3\n";
	fout<<m_height;
	fout<<" ";
	fout<<m_width;
	fout<<"\n";
	fout<<"255\n";
	for(int i=0;i<m_height;i++)
	{
		for(int j=0;j<m_width;j++)
		{
			fout<< getRGBNumbers(m_matrix[i][j]);
			if(j!=m_width-1)
			{
				fout<<" ";
			}
		}
		fout<<"\n";		
	}
	fout.close();	
}

bool Image::inside(const Point a_point)
{
	if(a_point.getX()>m_width||a_point.getY()>m_height)
	{
		return false;
	}
	return true;
}
