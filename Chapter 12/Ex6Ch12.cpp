
/*
6. What happens when you draw a Shape that doesn’t fit inside its Window?
What happens if you draw a Window that doesn’t fit on your screen? Write to
programs that illustrate these two phenomena.t of your screen and two-thirds
the width.
*/

#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Graph.h"  
#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Simple_window.h"

int width = 600, height = 400, yOffset = 50, radius = 100;

void showCircle(Simple_window& win, Point center, int radius, Graph_lib::Color color)
{
	auto background = new Graph_lib::Rectangle(Point(0, yOffset), width, height);
	background->set_color(Graph_lib::Color::white);
	background->set_fill_color(Graph_lib::Color::white);
	win.attach(*background);
	auto circle = new Graph_lib::Circle(center, radius);
	circle->set_color(color);
	win.attach(*circle);
	win.wait_for_button();
}

int main()
{
	try
	{
		Point top_left{ 100, 100 };
		Simple_window win{ top_left, width, height, "My Window" };
		showCircle(win, Point(100, 100 + yOffset), radius, Graph_lib::Color::red);
		showCircle(win, Point(-50, 100 + yOffset), radius, Graph_lib::Color::red);
	}
	catch (exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}
}