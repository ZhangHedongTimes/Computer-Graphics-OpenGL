#ifndef CHAPTER10_H
#define CHAPTER10_H
#include"OpenGLBase.h"
#include<vector>

class Display3D:public OpenGLBase
{
public:
	Display3D();
	~Display3D();

	virtual void init() ;
	virtual void resetOpenGL();
	virtual void draw(int argc, char** argv);
private:
	static void displayFunction();


	Point3<GLfloat> p0;//viewing-coordinate origin
	Point3<GLfloat> pref;//look at point
	Point3<GLfloat> pv;//view-up vector
	Point2<GLfloat> pmin;
	Point2<GLfloat> pmax;
	GLfloat dnear;
	GLfloat dfar;
};




#endif // CHAPTER10_H
