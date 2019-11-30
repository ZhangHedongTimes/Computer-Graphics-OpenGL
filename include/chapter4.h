#pragma once
#include<glut.h>
#include<math.h>
#include<stdlib.h>
namespace Chapter_4 {

const GLdouble Pi = 3.141592653;

GLsizei winWidth = 600, winHeight = 500;
GLuint regHex;
GLint xRaster = 25, yRaster = 150;
GLubyte lable[] = { 'J','a','n','F','e','b','M','a','r','A','p','r','M','a','y','J','u','n','J','u','l','A','u','g','S','e','p','O','c','t','N','o','v','D','e','c' };
GLint dataValue[12] = { 420,342,324,310,262,185,190,196,217,240,312,438 };

void init()
{
	glClearColor(1.0, 1.0, 1.0, 1.0);//设置初始窗口颜色
	glMatrixMode(GL_PROJECTION);//将当前矩阵指定为投影矩阵
	gluOrtho2D(0.0, 600.0, 0.0, 500.0);////left right,buttom,up (left,buttom),(right,up) 视野范围
}
void lineGraph()
{
	GLint month, k;
	GLint x = 30;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(0.0, 0.0, 1.0);

	glBegin(GL_LINE_STRIP);
	for (k = 0; k < 12; k++)
	{
		glVertex2i(x + k * 50, dataValue[k]);
	}
	glEnd();

	glColor3f(1.0, 0.0, 0.0);
	for (k = 0; k < 12; k++)
	{
		glRasterPos2i(xRaster + k * 50, dataValue[k] - 4);
		glutBitmapCharacter(GLUT_BITMAP_9_BY_15, '*');
	}

	glColor3f(0.0, 0.0, 0.0);

	GLint xRaster_temp = 20;
	for (month = 0; month < 12; month++)
	{
		glRasterPos2i(xRaster_temp, yRaster);
		for (k = 3 * month; k < 3 * month + 3; k++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, lable[k]);
		}
		xRaster_temp += 50;
	}
	glColor3f(1.0, 0.0, 0.0);
	for (k = 0; k < 12; k++)
	{
		glRecti(20 + k * 50, 165, 40 + k * 50, dataValue[k]);
	}
	glFlush();
}

void barChart()
{
	GLint month, k;
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	for (k = 0; k < 12; k++)
	{
		glRecti(20 + k * 50, 165, 40 + k * 50, dataValue[k]);
	}
	glColor3f(0.0, 0.0, 0.0);
	GLint xRaster_temp = 20;
	for (month = 0; month < 12; month++)
	{
		glRasterPos2i(xRaster_temp, yRaster);
		for (k = 3 * month; k < 3 * month + 3; k++)
		{
			glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12, lable[k]);
		}
		xRaster_temp += 50;
	}
	glFlush();
}

void winReshapeFcn(GLint newWidth, GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));
	glClear(GL_COLOR_BUFFER_BIT);

	winHeight = newHeight;
	winWidth = newWidth;

}



struct scrPt
{
	GLint x, y;
};

void circleMidpoint(scrPt circCtr, GLint radius)
{


	//glBegin(GL_POLYGON);
	glBegin(GL_LINE_LOOP);
	GLint n = 100;
	for (int i = 0; i < n; i++) {
		glVertex2f(radius*cos(2 * Pi / n * i)+circCtr.x, radius*sin(2 * Pi / n * i)+circCtr.y);
	}
	glEnd();
	glColor3f(0.0, 0.0, 1.0);
}

void pieChart()
{
	scrPt circCtr, piePt;
	GLint radius = winWidth / 4;
	GLdouble sliceAngle, preiousSliceAngle = 0.f;
	GLint k, nSlices = 12;
	GLdouble dataValues[12] = { 10.0,7.f,13.f,5.f,13.f,14.f,3.f,16.f,5.f,3.f,17.f,8.f };
	GLdouble dataSum = 0.0;

	circCtr.x = winWidth / 2;
	circCtr.y = winHeight / 2;
	circleMidpoint(circCtr, radius);

	for (k  = 0; k < nSlices; k++)
	{
		dataSum += dataValues[k];
	}
	for (k = 0; k < nSlices; k++)
	{
		sliceAngle = 2 * Pi*dataValues[k] / dataSum + preiousSliceAngle;
		piePt.x = circCtr.x + radius * cos(sliceAngle);
		piePt.y = circCtr.y + radius * sin(sliceAngle);
		glBegin(GL_LINES);
			glVertex2i(circCtr.x, circCtr.y);
			glVertex2i(piePt.x, piePt.y);
		glEnd();
		preiousSliceAngle = sliceAngle;
	}
}
void displayFcn()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glColor3f(1.0, 0.0, 0.0);
	pieChart();
	glFlush();
}

class screenPt
{
public:
	screenPt();
	~screenPt();
	void setCoords(GLint xCoord, GLint yCoord)
	{
		x = xCoord;
		y = yCoord;
	}
	GLint getx()
	{
		return x;
	}
	GLint gety()
	{
		return y;
	}
private:
	GLint x, y;
};

screenPt::screenPt()
{
	GLint x = y = 0;
}

screenPt::~screenPt()
{
}

static void hex_init()
{
	screenPt hexVertex, circCtr;
	GLdouble theta;
	GLint k;
	circCtr.setCoords(winWidth / 2, winHeight / 2);
	glClearColor(1.0, 1.0, 1.0, 0.0);//设置初始窗口颜色
	regHex = glGenLists(1);
	glNewList(regHex, GL_COMPILE);
	glColor3f(1.0, 0.0, 0.0);
	glBegin(GL_POLYGON);
		for (k = 0; k < 6; k++)
		{
			theta = 2 * Pi*k / 6.0;
			hexVertex.setCoords(circCtr.getx() + 150 * cos(theta), circCtr.gety() + 150 * sin(theta));
			glVertex2i(hexVertex.getx(), hexVertex.gety());
		}
	glEnd();
	glEndList();
}

void regHexagon()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glCallList(regHex);
	glFlush();
}

void winReshapeFcn_Hex(GLint newWidth,GLint newHeight)
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0.0, GLdouble(newWidth), 0.0, GLdouble(newHeight));
	glClear(GL_COLOR_BUFFER_BIT);
}

void runPieGraph_LineGraph(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(350, 300);//设置窗口位置
	glutInitWindowSize(winWidth, winHeight);//设置窗口大小
	glutCreateWindow("An Example OpenGL Program");//创建窗口并命名
	
	init();
#if 1
	glutDisplayFunc(lineGraph);//line graph
#else
	glutDisplayFunc(displayFcn);// pie chart

#endif // 0
	glutReshapeFunc(winReshapeFcn);
	glutMainLoop();
}

void runDrawHexDisplayList(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);//设置窗口位置
	glutInitWindowSize(winWidth, winHeight);//设置窗口大小
	glutCreateWindow("Reshape & Display-List");//创建窗口并命名

	hex_init();
	glutDisplayFunc(regHexagon);
	glutReshapeFunc(winReshapeFcn_Hex);
	glutMainLoop();
}

}