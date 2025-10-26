/* 8. Draw the Olympic five rings. */

#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Graph.h"  
#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Simple_window.h"
#include <cmath>

int radius = 50, width = 600, height = 400;
int offset_x = 10;
int offset_y = 10;

static void drawOneCircle(Simple_window& win, Point center, int radius, Graph_lib::Color color)
{
	auto circle = new Graph_lib::Circle(center, radius);
	circle->set_color(color);
	circle->set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 6));
	win.attach(*circle);
}

static void drawTopRow(Simple_window& win, Point start, int radius, int spacing)
{
	Graph_lib::Color colors[3] = { Graph_lib::Color::blue, Graph_lib::Color::black, Graph_lib::Color::red };
	for (int i = 0; i < 3; i++)
	{
		Point center{ start.x + spacing / 2 + i * spacing, start.y + offset_y };
		drawOneCircle(win, center, radius, colors[i]);
	}
}

static void drawWhiteDummyCircle(Simple_window& win, Point start, int radius, int spacing)
{
	int xCoordBlue = start.x + spacing / 2;
	int xCoordBlack = start.x + spacing / 2 + spacing;
	int xCoordDummy = (xCoordBlue + xCoordBlack) / 2;
	int yCoordDummy = start.y + offset_y + radius;
	Point centerCoordDummy(xCoordDummy, yCoordDummy);
	drawOneCircle(win, centerCoordDummy, radius, Graph_lib::Color::white);
}

static int circleIntersections(Point c0, int r0, Point c1, int r1, Point& p1, Point& p2)
{
	double dx = c1.x - c0.x;
	double dy = c1.y - c0.y;
	double c = std::sqrt(dx * dx + dy * dy); // Distance between circle centers
	// x: Distance from c0 to the base point along the line connecting the centers
	double x = (std::pow(r0, 2) + std::pow(c, 2) - std::pow(r1, 2)) / (2 * c);
	// y: Perpendicular distance from the base point to the intersection points
	double y = std::sqrt(r0 * r0 - x * x);
	// Calculate unit vectors: ex along the connecting line, ey perpendicular to it
	double ex0 = dx / c;
	double ex1 = dy / c;
	double ey0 = -ex1;
	double ey1 = ex0;
	// Coordinates of the base point on the line connecting the centers
	double xm = c0.x + x * ex0;
	double ym = c0.y + x * ex1;
	// Calculate the two intersection points
	double xs1 = xm + y * ey0;
	double ys1 = ym + y * ey1;
	double xs2 = xm - y * ey0;
	double ys2 = ym - y * ey1;
	p1 = Point(static_cast<int>(std::lround(xs1)), static_cast<int>(std::lround(ys1)));
	p2 = Point(static_cast<int>(std::lround(xs2)), static_cast<int>(std::lround(ys2)));
	return 1;
}

static void drawMarker(Simple_window& win, Point center, Graph_lib::Color color)
{
	auto m = new Graph_lib::Circle(center, 3);
	m->set_color(color);
	m->set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 4));
	win.attach(*m);
}

static void drawArc(Simple_window& win, Point center, int radius, double angle1, double angle2, Graph_lib::Color color)
{
	const int segments = 40;
	double delta = (angle2 - angle1) / segments;
	for (int i = 0; i < segments; ++i)
	{
		double a1 = angle1 + i * delta;
		double a2 = angle1 + (i + 1) * delta;
		int x1 = static_cast<int>(center.x + radius * std::cos(a1));
		int y1 = static_cast<int>(center.y + radius * std::sin(a1));
		int x2 = static_cast<int>(center.x + radius * std::cos(a2));
		int y2 = static_cast<int>(center.y + radius * std::sin(a2));
		auto seg = new Graph_lib::Line(Point(x1, y1), Point(x2, y2));
		seg->set_color(color);
		seg->set_style(Graph_lib::Line_style(Graph_lib::Line_style::solid, 6));
		win.attach(*seg);
	}
}

int main()
{
	try
	{
		Point top_left{ 100, 100 };
		Simple_window win{ top_left, width, height, "Olympic Rings" };
		int spacing = 2 * radius + 10;
		Point top_row_start{ top_left.x + offset_x, top_left.y + offset_y };
		drawTopRow(win, top_row_start, radius, spacing);
		//drawWhiteDummyCircle(win, top_row_start, radius, spacing);

		// Coordinates of centre of circles - test
		int xBlue = top_row_start.x + spacing / 2;
		int yBlue = top_row_start.y + offset_y;
		int xBlack = xBlue + spacing;
		int yBlack = yBlue;
		int xDummy = (xBlue + xBlack) / 2;
		int yDummy = yBlue + radius;

		Point centerBlue(xBlue, yBlue);
		Point centerBlack(xBlack, yBlack);
		Point centerDummy(xDummy, yDummy);

		// Intersections Dummy <-> Black
		Point pBlack1, pBlack2;
		circleIntersections(centerBlack, radius, centerDummy, radius, pBlack1, pBlack2);
		//drawMarker(win, pBlack1, Graph_lib::Color::dark_green);
		//drawMarker(win, pBlack2, Graph_lib::Color::dark_green);

		// Intersections Dummy <-> Blue
		Point pBlue1, pBlue2;
		circleIntersections(centerBlue, radius, centerDummy, radius, pBlue1, pBlue2);
		//drawMarker(win, pBlue1, Graph_lib::Color::dark_green);
		//drawMarker(win, pBlue2, Graph_lib::Color::dark_green);

		double angle1 = std::atan2(pBlack1.y - centerDummy.y, pBlack1.x - centerDummy.x);
		double angle2 = std::atan2(pBlack2.y - centerDummy.y, pBlack2.x - centerDummy.x);
		drawArc(win, centerDummy, radius, angle1, angle2 - 0.1, Graph_lib::Color::yellow);

		double angle3 = std::atan2(pBlack2.y - centerDummy.y, pBlack2.x - centerDummy.x);
		double angle4 = std::atan2(pBlue1.y - centerDummy.y, pBlue1.x - centerDummy.x);
		drawArc(win, centerDummy, radius, angle3 + 0.1, angle4, Graph_lib::Color::yellow);

		double angle5 = std::atan2(pBlue1.y - centerDummy.y, pBlue1.x - centerDummy.x);
		double angle6 = std::atan2(pBlue2.y - centerDummy.y, pBlue2.x - centerDummy.x);
		angle6 += 2 * 3.14159;
		drawArc(win, centerDummy, radius, angle5, angle6 - 0.1, Graph_lib::Color::yellow);

		double angle7 = std::atan2(pBlue2.y - centerDummy.y, pBlue2.x - centerDummy.x);
		double angle8 = std::atan2(pBlack1.y - centerDummy.y, pBlack1.x - centerDummy.x);
		drawArc(win, centerDummy, radius, angle7 + 0.05, angle8, Graph_lib::Color::yellow);

		int xRed = xBlack + spacing;
		Point centerRed(xRed, yBlack);
		int xDummy2 = (xBlack + xRed) / 2;
		int yDummy2 = yDummy;
		Point centerDummy2(xDummy2, yDummy2);
		//drawOneCircle(win, centerDummy2, radius, Graph_lib::Color::white);

		// Intersections circles Dummy2 <-> Red
		Point pRed1, pRed2;
		circleIntersections(centerRed, radius, centerDummy2, radius, pRed1, pRed2);
		//drawMarker(win, pRed1, Graph_lib::Color::dark_green);
		//drawMarker(win, pRed2, Graph_lib::Color::dark_green);

		// Intersections circles Dummy2 <-> Black
		Point pBlack1_D2, pBlack2_D2;
		circleIntersections(centerBlack, radius, centerDummy2, radius, pBlack1_D2, pBlack2_D2);
		//drawMarker(win, pBlack1_D2, Graph_lib::Color::dark_green);
		//drawMarker(win, pBlack2_D2, Graph_lib::Color::dark_green);

		double angle9 = std::atan2(pRed1.y - centerDummy2.y, pRed1.x - centerDummy2.x);
		double angle10 = std::atan2(pRed2.y - centerDummy2.y, pRed2.x - centerDummy2.x);
		drawArc(win, centerDummy2, radius, angle9, angle10 - 0.1, Graph_lib::Color::green);

		double angle11 = std::atan2(pRed2.y - centerDummy2.y, pRed2.x - centerDummy2.x);
		double angle12 = std::atan2(pBlack1.y - centerDummy2.y, pBlack1.x - centerDummy2.x);
		drawArc(win, centerDummy2, radius, angle3 + 0.1, angle4, Graph_lib::Color::green);

		double angle13 = std::atan2(pBlack1_D2.y - centerDummy2.y, pBlack1_D2.x - centerDummy2.x);
		double angle14 = std::atan2(pBlack2_D2.y - centerDummy2.y, pBlack2_D2.x - centerDummy2.x);
		angle14 += 2 * 3.14159;
		drawArc(win, centerDummy2, radius, angle5, angle14 - 0.1, Graph_lib::Color::green);

		double angle15 = std::atan2(pBlack2_D2.y - centerDummy2.y, pBlack2_D2.x - centerDummy2.x);
		double angle16 = std::atan2(pRed1.y - centerDummy2.y, pRed1.x - centerDummy2.x);
		drawArc(win, centerDummy2, radius, angle15 + 0.05, angle16, Graph_lib::Color::green);

		win.wait_for_button();
	}
	catch (exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}
}