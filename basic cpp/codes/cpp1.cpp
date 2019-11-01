#include <iostream>

class Point
{
public:
	//Point();
	Point(int a_x=0,int a_y=0);
	~Point();
	
	int x() const;
	int y() const;
	void moveTo(int a_x,int a_y);
	void moveBy(int a_dx,int a_dy);
	
	void print() const;
private:
	int m_x;
	int m_y;
};

//CTOR
/*Point::Point()
:m_x(0)
,m_y(0)
{
	std::cout<<"CTOR\n";
}*/

Point::Point(int a_x,int a_y)
:m_x(a_x)
,m_y(a_y)
{
	std::cout<<"CTOR\n";
}

int Point::x() const
{
	return m_x;
}

int Point::y() const
{
	return m_y;
}

void Point::print() const
{
	std::cout << "p1="
			<<"["<<m_x
			<<","<<m_y
			<<"]"
			<<"\n";	
}

//DTOR
Point::~Point()
{
	std::cout<<"DTOR\n";
}

int main(int argc,char *argv[])
{
	std::cout << "before dec\n";
	Point p1;
	std::cout << "after dec\n";
	
	std::cout << "p1=";
	p1.print();
	std::cout <<"\n";
	
	Point p2(3,4);
	p2.print();

}
