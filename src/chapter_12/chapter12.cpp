#include"chapter12.h"
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
	glClearColor(1.0, 1.0, 1.0, 0.0);//���ó�ʼ������ɫ
	regHex = glGenLists(1);
	glNewList(regHex, GL_COMPILE);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
	for (k = 0; k < 6; k++)
	{
		hexTheta = TWO_PI * k / 6;
		hexVertex.x = 150 + 100 * cos(hexTheta);
		hexVertex.y = 150 + 100 * sin(hexTheta);
		glVertex2i(hexVertex.x, hexVertex.y);
	}
	glEnd();
	glEndList();
	//glMatrixMode(GL_MODELVIEW);//����ǰ����ָ��ΪͶӰ����
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
	if (rotTheta > 360.0)
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
	glutDisplayFunc(this->displayFunction);//���ƺ�������
	glutMouseFunc(this->mouseFcn);

	glutMainLoop();
}

