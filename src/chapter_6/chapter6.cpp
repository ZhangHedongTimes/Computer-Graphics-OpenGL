#include"chapter6.h"
#include<iostream>


BasicGraphic::BasicGraphic()
{
}

BasicGraphic::~BasicGraphic()
{

}

void BasicGraphic::init()
{
	glClearColor(1.0, 1.0, 1.0, 0.0);//设置初始窗口颜色
	glMatrixMode(GL_PROJECTION);//将当前矩阵指定为投影矩阵
	gluOrtho2D(0.0, 800.0, 0.0, 800.0);////left right,buttom,up (left,buttom),(right,up) 视野范围
}

void BasicGraphic::resetOpenGL()
{
	glutSetWindowTitle("BasicGraphic");
}


void BasicGraphic::displayFunction()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glColor3f(1.0, 0.4, 0.8);
	glBegin(GL_LINE_LOOP);
	GLint n = 100;
	for (int i = 0; i < n; i++) {
		glVertex2f(100 * cos(2 * Pi / n * i) + 350, 100 * sin(2 * Pi / n * i) + 350);
	}
	glEnd();



	//std::vector<Point2<int>> line_point_list = lineDDA(100, 100, 400, 400);
	std::vector<Point2<int>> line_point_list = lineBresneham(100, 100, 400, 400);
	glPointSize(4);
	glBegin(GL_POINTS);
	for (auto p : line_point_list)
		glVertex2i(p.x, p.y);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glLineWidth(2);
	glBegin(GL_LINES);
	glVertex2i(100, 100);
	glVertex2i(400, 400);
	glEnd();

	glFlush();

};

void BasicGraphic::draw(int argc, char** argv)
{

	initOpenGL(argc, argv);
	init();
	resetOpenGL();
	glutDisplayFunc(this->displayFunction);//绘制函数设置
	glutMainLoop();
}


std::vector<Point2<int>>   BasicGraphic::lineDDA(int x0, int y0, int xEnd, int yEnd)
{
	int dx = xEnd - x0, dy = yEnd - y0, steps, k;
	float xIncrement, yIncrement, x = x0, y = y0;
	if (fabs(dx) > fabs(dy))
		steps = fabs(dx);
	else
		steps = fabs(dy);
	xIncrement = float(dx) / float(steps);
	yIncrement = float(dy) / float(steps);

	std::vector<Point2<int>> line_point_list;
	line_point_list.push_back(Point2<int>(round(x), round(y)));
	for (k = 0; k < steps; k++) {
		x += xIncrement;
		y += yIncrement;
		line_point_list.push_back(Point2<int>(round(x), round(y)));
	}
	return line_point_list;
}

std::vector<Point2<int>>  BasicGraphic::lineBresneham(int x0, int y0, int xEnd, int yEnd)
{

	//only for Slope in (0,1)
	std::vector<Point2<int>> line_point_list;
	int dx = abs(xEnd - x0), dy = abs(yEnd - y0);
	int p = 2 * dy - dx;
	int twoDy = 2 * dy, twoDyMinusDx = 2 * (dx - dy);
	int x, y;
	if (x0 > xEnd) {
		x = xEnd;
		y = yEnd;
		xEnd = x0;
	}
	else
	{
		x = x0;
		y = y0;
	}
	line_point_list.push_back(Point2<int>(x, y));
	while (x<xEnd)
	{
		x++;
		if (p < 0)
			p += twoDy;
		else {
			y++;
			p += twoDyMinusDx;
		}
		line_point_list.push_back(Point2<int>(x, y));
	}


	return line_point_list;
}