#ifndef CHAPTER12_H
#define CHAPTER12_H
#include"OpenGLBase.h"
#include<vector>


const double TWO_PI = 6.2831853;
class Animation :public OpenGLBase
{
public:
	Animation();
	~Animation();

	virtual void init() ;
	virtual void resetOpenGL();
	virtual void draw(int argc, char** argv);
private:
	static void displayFunction();
	static void rotateHex();
	static void mouseFcn(GLint button, GLint action, GLint x, GLint y);


};




#endif // CHAPTER12_H
