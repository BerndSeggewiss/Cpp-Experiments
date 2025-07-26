/*
7. Draw a two-dimensional house seen from the front, with a door, two windows, and a roof with chimney.
Feel free to add details; maybe have some “smoke” come out of the chimney.
*/

#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Graph.h"  
#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Simple_window.h"

static void Excercise7()
{
	// Foundation
	Point top_left{ 100, 100 };
	int WinWidth = 500;
	int WinHeight = 450;
	int RectWidth = 100;
	int RectHeight = 150;
	int rect_x = (WinWidth - RectWidth) / 2;
	int rect_y = (WinHeight - RectHeight) / 2;
	Simple_window win{ top_left, WinWidth, WinHeight, "My House" };
	auto rect = new Graph_lib::Rectangle{ Point{
		rect_x, rect_y}, RectWidth, RectHeight
	};
	rect->set_color(Graph_lib::Color::black);
	win.attach(*rect);
	// Door
	int DoorWidth = 30;
	int DoorHeight = 50;
	int DoorPoint_x = rect_x + 10;
	int DoorPoint_y = rect_y + RectHeight - DoorHeight;
	auto Door = new Graph_lib::Rectangle{
		Point{ DoorPoint_x, DoorPoint_y }, DoorWidth, DoorHeight
	};
	Door->set_color(Graph_lib::Color::black);
	win.attach(*Door);
	int KnobRadius = 3;
	int Knob_x = DoorPoint_x + DoorWidth - 5;
	int Knob_y = DoorPoint_y + DoorHeight / 2;
	auto DoorKnob = new Graph_lib::Circle{
		Point{Knob_x, Knob_y}, KnobRadius
	};
	DoorKnob->set_color(Graph_lib::Color::black);
	DoorKnob->set_fill_color(Graph_lib::Color::black);
	win.attach(*DoorKnob);
	// Roof
	auto poly = new Graph_lib::Polygon;
	poly->add(Point(rect_x, rect_y));
	poly->add(Point(rect_x + RectWidth, rect_y));
	int HeightTriangle = 70;
	poly->add(Point(rect_x + RectWidth / 2, rect_y - HeightTriangle));
	poly->set_color(Graph_lib::Color::red);
	win.attach(*poly);
	// Windows
	int WindowWidth = 30;
	int WindowHeight = 30;
	int WindowYOffset = 30;
	int WindowXOffset = 15;
	// Left Window
	int LeftWindowX = rect_x + WindowXOffset;
	int LeftWindowY = rect_y + WindowYOffset;
	auto LeftWindow = new Graph_lib::Rectangle{
		Point { LeftWindowX, LeftWindowY}, WindowWidth, WindowHeight
	};
	LeftWindow->set_color(Graph_lib::Color::blue);
	win.attach(*LeftWindow);
	// Right Window
	int RightWindowX = rect_x - WindowXOffset + RectWidth - WindowWidth;
	int RightWindowY = rect_y + WindowYOffset;
	auto RightWindow = new Graph_lib::Rectangle{ Point {
		RightWindowX, RightWindowY}, WindowWidth, WindowHeight
	};
	RightWindow->set_color(Graph_lib::Color::blue);
	win.attach(*RightWindow);
	// Chimney
	int gx = rect_x + RectWidth / 2;
	int gy = rect_y - HeightTriangle;
	int vx1 = gx + 10;
	//int y_top = rect_y;
	double m = double(gy - rect_y) / double(gx - (rect_x + RectWidth));
	int y1_intersect = int(m * (vx1 - (rect_x + RectWidth)) + rect_y);
	auto vert_line1 = new Graph_lib::Open_polyline;
	vert_line1->add(Point(vx1, rect_y));
	vert_line1->add(Point(vx1, y1_intersect));
	vert_line1->set_color(Graph_lib::Color::blue);
	int lengthLine1 = std::abs(y1_intersect - rect_y);
	//win.attach(*vert_line1);
	int vx2 = gx + 25;
	int y2_intersect = int(m * (vx2 - (rect_x + RectWidth)) + rect_y);
	auto vert_line2 = new Graph_lib::Open_polyline;
	vert_line2->add(Point(vx2, rect_y));
	vert_line2->add(Point(vx2, y2_intersect));
	vert_line2->set_color(Graph_lib::Color::blue);
	int lengthLine2 = std::abs(y2_intersect - rect_y);
	//win.attach(*vert_line2);
	auto black_line1 = new Graph_lib::Open_polyline;
	black_line1->add(Point(vx1, y1_intersect));
	black_line1->add(Point(vx1, y1_intersect - lengthLine2));
	black_line1->set_color(Graph_lib::Color::black);
	win.attach(*black_line1);
	auto black_line2 = new Graph_lib::Open_polyline;
	black_line2->add(Point(vx2, y2_intersect));
	black_line2->add(Point(vx2, y2_intersect - lengthLine1));
	black_line2->set_color(Graph_lib::Color::black);
	win.attach(*black_line2);
	auto black_line3 = new Graph_lib::Open_polyline;
	black_line3->add(Point(vx1, y1_intersect - lengthLine2));
	black_line3->add(Point(vx2, y2_intersect - lengthLine1));
	black_line3->set_color(Graph_lib::Color::black);
	win.attach(*black_line3);
	// Smoke from chimney
	int SmokeBase_x = (vx1 + vx2) / 2;
	int SmokeBase_y = (y1_intersect - lengthLine2 + y2_intersect - lengthLine1) / 2;
	for (int i = 0; i < 8; i++)
	{
		int dx;
		if (i % 2 == 0)
			dx = -8;
		else
			dx = 8;
		int dy = -5 * i;
		auto smoke = new Graph_lib::Circle{
			Point{ SmokeBase_x + dx, SmokeBase_y + dy }, 10 + i * 2
		};
		smoke->set_color(Graph_lib::Color::black);
		smoke->set_style(Graph_lib::Line_style(
			Graph_lib::Line_style::solid, 1)
		);
		win.attach(*smoke);
	}
	win.wait_for_button();
}

int main()
{
	try
	{
		Excercise7();
	}
	catch (exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}
}