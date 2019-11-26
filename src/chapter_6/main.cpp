#include<chapter6.h>
#include<iostream>
#include<vector>

using namespace std;
GLint dataValue[12] = { 420,342,324,310,262,185,190,196,217,240,312,438 };

void init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//设置初始窗口颜色
	glMatrixMode(GL_PROJECTION);//将当前矩阵指定为投影矩阵
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);////left right,buttom,up (left,buttom),(right,up) 视野范围
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
	glutInitWindowPosition(350, 300);//设置窗口位置
	glutInitWindowSize(800, 600);//设置窗口大小
	glutCreateWindow("An Example OpenGL Program");//创建窗口并命名

}


int main(int argc, char** argv)
{
	BasicGraphic bg;
	bg.draw(argc,argv);
	
	\\
	return 0;
}