/*
* Draw a series of regular polygons, one inside the other. The innermost should be
* an equilateral triangle, enclosed by a square, enclosed by a pentagon, etc. For
* the mathematical adept only: let all the points of each N-Polygon touch sides of the
* (N+1)-polygon. Hint the trigonometric functions are found in cmath.
*/

#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Graph.h"  
#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Simple_window.h"  

#ifndef M_PI
#define M_PI 3.14159265358979323846
#endif

vector<Point> drawTriangle(Simple_window& win, Point center, int radius,
	double angleDeg = 0, Color color = Color::red)
{
	vector<Point> points;
	for (int i = 0; i < 3; i++)
	{
		double angleRad = (90.0 + angleDeg + i * 120.0) * M_PI / 180;
		int x = center.x + static_cast<int>(radius * cos(angleRad));
		int y = center.y - static_cast<int>(radius * sin(angleRad));
		points.push_back(Point{ x, y });
		auto* line = new Graph_lib::Line(center, Point{ x, y });
		line->set_color(Color::red);
		line->set_style(Line_style(Line_style::dash, 1));
		win.attach(*line);
	}
	auto* triangle = new Graph_lib::Polygon;
	for (const auto& point : points)
		triangle->add(point);
	triangle->set_color(color);
	win.attach(*triangle);
	return points;
}

vector<Point> drawRectangle(Simple_window& win, const vector<Point>& points)
{
	Point p1 = points[1];
	Point p2 = points[2];
	int dx = p1.x - p2.x;
	int dy = p1.y - p2.y;
	int sideLength = static_cast<int>(sqrt(dx * dx + dy * dy));
	auto* line1 = new Graph_lib::Line(p1, p2);
	line1->set_color(Color::green);
	win.attach(*line1);
	Point p3{ p2.x, p2.y - sideLength };
	auto* line2 = new Graph_lib::Line(p2, p3);
	line2->set_color(Color::green);
	win.attach(*line2);
	Point p4{ p1.x, p1.y - sideLength };
	auto* line3 = new Graph_lib::Line(p3, p4);
	line3->set_color(Color::green);
	win.attach(*line3);
	auto* line4 = new Graph_lib::Line(p4, p1);
	line4->set_color(Color::green);
	win.attach(*line4);
	return points;
}

void drawPentagon(Simple_window& win, Point center, int radius,
	double angleDeg = 0, Color color = Color::blue)
{
	vector<Point> points;
	for (int i = 0; i < 5; i++)
	{
		double angleRad = (90.0 + angleDeg + i * 360/5) * M_PI / 180;
		int x = center.x + static_cast<int>(radius * cos(angleRad));
		int y = center.y - static_cast<int>(radius * sin(angleRad));
		points.push_back(Point{x, y});
		auto* line = new Graph_lib::Line(center, Point{ x, y });
		line->set_color(Color::blue);
		line->set_style(Line_style(Line_style::dash, 1));
		win.attach(*line);
	}
	auto* pentagon = new Graph_lib::Polygon;
	for (const auto& point : points)
		pentagon->add(point);
	pentagon->set_color(color);
	win.attach(*pentagon);
}

int main()
{
	using namespace Graph_lib;
	Point topLeft{ 100, 100 };
	Simple_window win{ topLeft, 400, 400, "Nested Polygons" };
	Point center{ 200, 200 };
	int circumradius = 100;
	int angleInDeg;
	vector<Point> points = drawTriangle(win, center, circumradius);
	points = drawRectangle(win, points);
	drawPentagon(win, center, circumradius * 1.8);
	win.wait_for_button();
}
