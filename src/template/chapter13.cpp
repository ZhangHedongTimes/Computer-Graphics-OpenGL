#include"chapter13.h"
#include<iostream>
#include<math.h>


GLfloat rotTheta;
GLuint regHex;
Animation::Animation()
{
	rotTheta = 0.0;
}

Animation::~Animation()
{

}

void Animation::init()
{
	Point2<GLint> hexVertex;
	GLdouble hexTheta;
	GLint k;
	glClearColor(1.0, 1.0, 1.0, 0.0);//设置初始窗口颜色
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);////left right,buttom,up (left,buttom),(right,up) 视野范围
	regHex = glGenLists(1);
	glNewList(regHex, GL_COMPILE);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (k = 0; k < 6; k++)
	{
		hexTheta = TWO_PI * k / 6;
		hexVertex.x = 350 + 100 * cos(hexTheta);
		hexVertex.y = 350 + 100 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);
	}
	glEnd();
	glEndList();
	//glMatrixMode(GL_MODELVIEW);//将当前矩阵指定为投影矩阵
	//gluLookAt(p0.x, p0.y, p0.z, pref.x, pref.y, pref.z, pv.x, pv.y, pv.z);
	//glMatrixMode(GL_PROJECTION);
	//glFrustum(pmin.x, pmax.x, pmin.y, pmax.y, dnear, dfar);
}

void Animation::resetOpenGL()
{
	glutSetWindowTitle("Animation");
}

void  Animation::rotateHex()
{
	rotTheta += 3.0;
	while(rotTheta > 360.0)
		rotTheta -= 360.0;
	glutPostRedisplay();
}

void Animation::mouseFcn(GLint button,GLint action,GLint x,GLint y)
{
	switch (button)
	{
	case GLUT_MIDDLE_BUTTON:
		if (action == GLUT_DOWN)
			glutIdleFunc(rotateHex);
		break;
	case GLUT_RIGHT_BUTTON:
		if(action == GLUT_DOWN)
			glutIdleFunc(NULL);
		break;
	default:
		break;
	}
	printf("%d  %f\n", button, rotTheta);
}

void Animation::displayFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glPushMatrix();
	glRotatef(rotTheta, 0.0, 0.0, 1.0);


	glCallList(regHex);
	glPopMatrix();
	glutSwapBuffers();
	
	glFlush();

};

void Animation::draw(int argc, char** argv)
{

	initOpenGL(argc, argv);
	init();
	resetOpenGL();
	glutDisplayFunc(this->displayFunction);//绘制函数设置
	glutMouseFunc(this->mouseFcn);
	glutMainLoop();
}

