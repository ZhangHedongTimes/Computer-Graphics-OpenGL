#include "OpenGLBase.h"
#include<iostream>


OpenGLBase::OpenGLBase()
{
	winHeight = 600;
	winWidth = 800;
}


OpenGLBase::~OpenGLBase()
{
}

void OpenGLBase::initOpenGL(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	//glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(350, 300);//设置窗口位置
	glutInitWindowSize(winWidth, winHeight);//设置窗口大小
	glutCreateWindow("An Example OpenGL Program");//创建窗口并命名

}
void  OpenGLBase::init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//设置初始窗口颜色
	glMatrixMode(GL_PROJECTION);//将当前矩阵指定为投影矩阵
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);////left right,buttom,up (left,buttom),(right,up) 视野范围
}

void  OpenGLBase::resetOpenGL()
{
	glutSetWindowTitle("HHH");
}

void OpenGLBase::setWH(const GLint w, const GLint h)
{
	winHeight = h;
	winWidth = w;
}
