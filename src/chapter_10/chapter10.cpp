#include"chapter10.h"
#include<iostream>


Display3D::Display3D()
{
	p0.x = 100.0; p0.y = 50.0; p0.z = 50.0;
	pref.x = 50.0; pref.y = 50.0; pref.z = 0.0;
	pv.x = 0.0; pv.y = 1.0; pv.z = 0.0;
	pmin.x = -40; pmin.y = -60;
	pmax.x = 40; pmax.y = 60;
	dnear = 25.0;
	dfar = 125.0;

}

Display3D::~Display3D()
{

}

void Display3D::init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//设置初始窗口颜色
	glMatrixMode(GL_MODELVIEW);//将当前矩阵指定为投影矩阵
	gluLookAt(p0.x, p0.y, p0.z, pref.x, pref.y, pref.z, pv.x, pv.y, pv.z);
	glMatrixMode(GL_PROJECTION);
	glFrustum(pmin.x, pmax.x, pmin.y, pmax.y, dnear, dfar);
}

void Display3D::resetOpenGL()
{
	glutSetWindowTitle("Display3D");
}


void Display3D::displayFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(0.0, 1.0, 0.0);
	glPolygonMode(GL_FRONT, GL_FILL);
	glPolygonMode(GL_BACK, GL_LINE);
	glBegin(GL_QUADS);
		glVertex3f(0.0, 0.0, 0.0);
		glVertex3f(100.0, 0.0, 0.0);
		glVertex3f(100.0, 100.0, 0.0);
		glVertex3f(0.0, 100.0, 0.0);
	glEnd();

	glFlush();

};

void Display3D::draw(int argc, char** argv)
{

	initOpenGL(argc, argv);
	init();
	resetOpenGL();
	glutDisplayFunc(this->displayFunction);//绘制函数设置
	glutMainLoop();
}

