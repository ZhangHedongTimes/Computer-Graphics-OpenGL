#pragma once
#include<glut.h>
class OpenGLBase
{
public:
	OpenGLBase();
	~OpenGLBase();
	void initOpenGL(int argc, char** argv);

	virtual void init();
	virtual void resetOpenGL();
	virtual void draw()=0;

private:

};

