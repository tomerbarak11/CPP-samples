#ifndef _POINT_H_
#define _POINT_H_

class Point
{
	public:
		Point(int x,int y);
		const int getX() const;
		const int getY() const;
		void setX(int x);
		void setY(int y);
	private:
		int m_x;
		int m_y;
};

#endif
