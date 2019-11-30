#ifndef CHAPTER6_H
#define CHAPTER6_H
#include"OpenGLBase.h"
#include<vector>
#include <cmath>

class BasicGraphic:public OpenGLBase
{
public:
	BasicGraphic();
	~BasicGraphic();

	virtual void init() ;
	virtual void resetOpenGL();
	virtual void draw(int argc, char** argv);
private:
	static void displayFunction();
	static std::vector<Point2<int>> lineDDA(int x0, int y0, int xEnd, int yEnd);
	static std::vector<Point2<int>> lineBresneham(int x0, int y0, int xEnd, int yEnd);

};




#endif // CHAPTER6_H
