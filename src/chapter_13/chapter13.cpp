#include"chapter13.h"
#include<iostream>
#include<math.h>


//GLint newWidth = 600, newHeight =600;
Polyhedron::Polyhedron()
{
}

Polyhedron::~Polyhedron()
{

}

void Polyhedron::init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//设置初始窗口颜色
	
}

void Polyhedron::resetOpenGL()
{
	glutSetWindowTitle("Polyhedron");
}



void Polyhedron::displayFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.1);

	gluLookAt(5.0, 5.0, 5.0, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glScalef(1.5, 2.0, 1.0);
	glutWireCube(1.0);

	glScalef(0.8, 0.5, 0.8);
	glTranslatef(-6.0, -5.0, 0.0);
	glutWireDodecahedron();

	glTranslatef(8.6,8.6,2.0);
	glutWireTetrahedron();

	glTranslatef(-3.0, -1.0, 0.0);
	glutWireOctahedron();

	glScalef(0.8, 0.8, 1.0);
	glTranslatef(4.3, -2.0, 0.5);
	glutWireIcosahedron();

	
	glFlush();

};

void Polyhedron::winReshapeFunc(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glFrustum(-1.0, 1.0, -1.0, 1.0, 2.0, 20.0);

	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
}

void Polyhedron::draw(int argc, char** argv)
{
	initOpenGL(argc, argv);
	init();
	resetOpenGL();
	glutDisplayFunc(this->displayFunction);//绘制函数设置
	glutReshapeFunc(this->winReshapeFunc);
	glutMainLoop();
}



Quadric::Quadric()
{

}

Quadric::~Quadric()
{

}

void Quadric::init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//设置初始窗口颜色
}

void Quadric::resetOpenGL()
{
	glutSetWindowTitle("Quadric Surface ");
}


void  Quadric::winReshapeFunc(GLint newWidth, GLint newHeight)
{
	glViewport(0, 0, newWidth, newHeight);
	glMatrixMode(GL_PROJECTION);
	glOrtho(-2.0, 2.0, -2.0, 2.0, 0.0, 5.0);

	glMatrixMode(GL_MODELVIEW);
	glClear(GL_COLOR_BUFFER_BIT);
	
}

void Quadric::displayFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 0.1);

	gluLookAt(2.0, 2.0, 2.0, 0.0, 0.0, 0.0, 0.0, 0.0, 1.0);

	glPushMatrix();
	glTranslatef(1.0, 1.0, 0.0);
	glutWireSphere(0.75, 8, 6);
	glPopMatrix();


	glPushMatrix();
	glTranslatef(1.0, -0.5, 0.5);
	glutWireCone(0.7, 2.0, 7,6);
	glPopMatrix();

	GLUquadricObj *cylinder;
	glPushMatrix();
	glTranslatef(0.0, 1.2, 0.8);
	cylinder = gluNewQuadric();
	gluQuadricDrawStyle(cylinder, GLU_LINE);
	gluCylinder(cylinder, 0.6, 0.6, 1.5, 6, 4);
	glPopMatrix();

	glFlush();
}

void Quadric::draw(int argc, char** argv)
{
	initOpenGL(argc, argv);
	init();
	resetOpenGL();
	glutDisplayFunc(this->displayFunction);//绘制函数设置
	glutReshapeFunc(this->winReshapeFunc);
	glutMainLoop();
}