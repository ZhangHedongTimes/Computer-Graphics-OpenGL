#include<chapter6.h>
#include<iostream>
#include<vector>

using namespace std;
GLint dataValue[12] = { 420,342,324,310,262,185,190,196,217,240,312,438 };

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//���ó�ʼ������ɫ
	glMatrixMode(GL_PROJECTION);//����ǰ����ָ��ΪͶӰ����
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);////left right,buttom,up (left,buttom),(right,up) ��Ұ��Χ
}

void lineSegment()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 0.4, 0.8);
	glBegin(GL_LINES);
	glVertex2i(380, 15);
	glVertex2i(10, 450);

	glEnd();

	glFlush();
}

void initOpengl(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(350, 300);//���ô���λ��
	glutInitWindowSize(800, 600);//���ô��ڴ�С
	glutCreateWindow("An Example OpenGL Program");//�������ڲ�����

}


int main(int argc, char** argv)
{
	BasicGraphic bg;
	bg.draw(argc,argv);
	
	\\
	return 0;
}