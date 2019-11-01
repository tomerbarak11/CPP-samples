#include "mu_test.h"
#include "Image.h"
#include "Vertical.h"
#include "Horizontal.h"
#include "Point.h"
#include "Circle.h"

#define SIZE5 5
#define SIZE100 500
UNIT(create_image)
	Image im(SIZE5,SIZE5);
	im.saveToFile("f1.ppm");
	im.saveToFile("f2.txt");

END_UNIT

UNIT(create_4_lines)
	int verLength=50;
	Image im(SIZE100,SIZE100);
	Point baseZero(0,0);
	Point p1(0,50);
	Point p2(50,0);
	Point p3(100,100);
	int radius=100;
	Vertical ver1(verLength,baseZero,YELLOW);
	ver1.draw(im,YELLOW);
	
	Vertical ver2(verLength,p1,RED);
	ver2.draw(im,RED);

	Horizontal hor1(verLength,baseZero,GREEN);
	hor1.draw(im,GREEN);
	
	Horizontal hor2(verLength,p2,BLUE);
	hor2.draw(im,BLUE);

	Circle cir1(p3,radius,MAGENTA);
	cir1.draw(im,MAGENTA);

	im.saveToFile("f3.ppm");
	im.saveToFile("f4.txt");
END_UNIT

TEST_SUITE(Text Manipulator)
	TEST(create_image)
	TEST(create_4_lines)
END_SUITE
