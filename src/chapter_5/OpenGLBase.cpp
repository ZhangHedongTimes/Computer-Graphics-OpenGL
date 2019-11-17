#include "OpenGLBase.h"



OpenGLBase::OpenGLBase()
{
}


OpenGLBase::~OpenGLBase()
{
}

void OpenGLBase::initOpenGL(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(350, 300);//设置窗口位置
	glutInitWindowSize(800, 600);//设置窗口大小
}
void  OpenGLBase::init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//设置初始窗口颜色
	glMatrixMode(GL_PROJECTION);//将当前矩阵指定为投影矩阵
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);////left right,buttom,up (left,buttom),(right,up) 视野范围
	glutCreateWindow("An Example OpenGL Program");//创建窗口并命名
}

void  OpenGLBase::resetOpenGL()
{
	glutSetWindowTitle("HHH");
}
