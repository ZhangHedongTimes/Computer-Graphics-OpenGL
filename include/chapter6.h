#ifndef CHAPTER6_H
#define CHAPTER6_H
#include"OpenGLBase.h"


///#if _DEBUG
///#pragma comment(lib, "OpenGLBase.lib")
///#endif
///
///#if _RELEASE
///#pragma comment(lib, "OpenGLBase.lib")
///#endif



class BasicGraphic:public OpenGLBase
{
public:
	BasicGraphic();
	~BasicGraphic();

	virtual void init();
	virtual void resetOpenGL();
	virtual void draw();
private:

};




#endif // CHAPTER6_H
