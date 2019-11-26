#include<iostream>
#include <glut.h> 
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

void drawPoints()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	std::vector<int[2]> points_list(3);
	points_list[0][0] = 650;
	points_list[0][1] = 500;
	points_list[1][0] = 170;
	points_list[1][1] = 150;
	points_list[2][0] = 300;
	points_list[2][1] = 200;
	glPointSize(10);
	glBegin(GL_POINTS);
	for (size_t i = 0; i < points_list.size(); i++)
	{
		glVertex2iv(points_list[i]);
	}


	glEnd();

	glColor3f(1.0, 0.4, 0.8);
	glBegin(GL_LINES);
	glVertex2i(380, 15);
	glVertex2i(10, 450);
	for (int k = 0; k < 12; k++)
	{
		glVertex2i(30 + k * 50, dataValue[k]);
	}
	glEnd();

	glFlush();
}

int main(int argc,char** argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(350, 300);//���ô���λ��
	glutInitWindowSize(800, 600);//���ô��ڴ�С
	glutCreateWindow("An Example OpenGL Program");//�������ڲ�����

	init();//��ʼ���ã�������ʽ������������
	//glutDisplayFunc(lineSegment);//���ƺ�������
	glutDisplayFunc(drawPoints);
	glutMainLoop();
//	cout << " OKKO\n";
	return 0;
}