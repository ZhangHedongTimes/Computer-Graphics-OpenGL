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
	glutInitWindowPosition(350, 300);//���ô���λ��
	glutInitWindowSize(winWidth, winHeight);//���ô��ڴ�С
	glutCreateWindow("An Example OpenGL Program");//�������ڲ�����

}
void  OpenGLBase::init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//���ó�ʼ������ɫ
	glMatrixMode(GL_PROJECTION);//����ǰ����ָ��ΪͶӰ����
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);////left right,buttom,up (left,buttom),(right,up) ��Ұ��Χ
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
