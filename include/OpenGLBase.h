#pragma once
#include<glut.h>
const GLdouble Pi = 3.141592653;


template<typename T>
struct Point4
{
	Point4()
	{

	}
	Point4(T _x, T _y, T _z, T _w) :x(_x), y(_y), z(_z), w(_w)
	{

	}
	T x, y, z,w;
};

template<typename T> 
struct Point3
{
	Point3()
	{

	}
	Point3(T _x, T _y, T _z) :x(_x), y(_y), z(_z)
	{

	}
	T x, y, z;
};


template<typename T>
struct Point2
{
	Point2()
	{

	}
	Point2(T _x, T _y) :x(_x), y(_y)
	{

	}
	T x, y;
};

class OpenGLBase
{
public:
	OpenGLBase();
	~OpenGLBase();
	void initOpenGL(int argc, char** argv);
	void setWH(const GLint w, const GLint h);
	virtual void init();
	virtual void resetOpenGL();
	virtual void draw(int argc, char** argv)=0;

private:
	GLint winWidth;
	GLint winHeight;

};

