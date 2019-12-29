#ifndef CHAPTER13_H
#define CHAPTER13_H
#include"OpenGLBase.h"
#include<vector>


const double TWO_PI = 6.2831853;
class Polyhedron :public OpenGLBase
{
public:
	Polyhedron();
	~Polyhedron();

	virtual void init() ;
	virtual void resetOpenGL();
	virtual void draw(int argc, char** argv);
private:
	static void winReshapeFunc(GLint newWidth, GLint newHeight);
	static void displayFunction();

};
class Quadric:public OpenGLBase
{
public:
	Quadric();
	~Quadric();

	virtual void init();
	virtual void resetOpenGL();
	virtual void draw(int argc, char** argv);
private:
	static void winReshapeFunc(GLint newWidth, GLint newHeight);
	static void displayFunction();

};



#endif // CHAPTER13_H
