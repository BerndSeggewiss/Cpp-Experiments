/*
	1. Draw a rectangle as a Rectangle and as a Polygon. Make the lines of the Polygon red
	and the lines of the Rectangle blue.
	2. Draw a 100-by-30 Rectangle and place the text “Howdy!” inside it.
	3. Draw your initials 150 pixel high. Use a thick line. Draw each initial in a different color.
	4. Draw a 3-by-3 tic-tac-toe board of alternating white and red squares.
	5. Draw a red 1/4 -inch frame around a rectangle that is three-quarters the height of your screen and two-thirds the width.
*/

#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Graph.h"  
#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Simple_window.h"

static void Exercise1(Simple_window& win)
{
	auto rect = new Graph_lib::Rectangle(Point(10, 70), 100, 50);
	rect->set_color(Graph_lib::Color::blue);
	win.attach(*rect);
	auto poly = new Graph_lib::Polygon;
	poly->add(Point(50, 200));
	poly->add(Point(150, 200));
	poly->add(Point(150, 250));
	poly->add(Point(50, 250));
	poly->set_color(Graph_lib::Color::red);
	win.attach(*poly);
	win.wait_for_button();
}

static void Exercise2(Simple_window& win)
{
	auto namedReactangle = new Graph_lib::Rectangle(Point(10, 160), 70, 50);
	namedReactangle->set_color(Graph_lib::Color::green);
	win.attach(*namedReactangle);
	auto t = new Graph_lib::Text(Point(15, 185), "Howdy!");
	win.attach(*t);
	win.wait_for_button();
}

static void Exercise3(Simple_window& win)
{
	auto myInitialsFirst = new Graph_lib::Text(Point(50, 40), "B");
	myInitialsFirst->set_color(Graph_lib::Color::yellow);
	myInitialsFirst->set_font(Graph_lib::Font::helvetica_bold);
	myInitialsFirst->set_font_size(50);
	win.attach(*myInitialsFirst);
	auto myInitialsLast = new Graph_lib::Text(Point(50 + 55, 40), "S");
	myInitialsLast->set_color(Graph_lib::Color::black);
	myInitialsLast->set_font(Graph_lib::Font::helvetica_bold);
	myInitialsLast->set_font_size(50);
	win.attach(*myInitialsLast);
	win.wait_for_button();
}

static void Exercise4(Simple_window& win)
{
	int startX = 120, startY = 70, size = 30;
	for (int row = 0; row < 3; ++row)
	{
		for (int col = 0; col < 3; ++col)
		{
			auto rect = new Graph_lib::Rectangle(Point(startX + col * size, startY + row * size), size, size);
			if ((row + col) % 2 == 0)
			{
				rect->set_color(Graph_lib::Color::white);
				rect->set_fill_color(Graph_lib::Color::white);
			}
			else
			{
				rect->set_color(Graph_lib::Color::red);
				rect->set_fill_color(Graph_lib::Color::red);
			}
			win.attach(*rect);
		}
	}
	win.wait_for_button();
}

static void Exercise5(Simple_window& win)
{
	int screenWidth = Fl::w();
	int screenHeight = Fl::h();
	// Umrechnung: 1/4 inch = 0.25 * 96 = 24 Pixel (bei 96 DPI)
	int frameWidth = 24;
	int rectWidth = screenWidth * 2 / 3;
	int rectHeight = screenHeight * 3 / 4;
	auto outerRect = new Graph_lib::Rectangle(Point(0, 0), rectWidth + 2 * frameWidth, rectHeight + 2 * frameWidth);
	outerRect->set_color(Graph_lib::Color::red);
	outerRect->set_fill_color(Graph_lib::Color::red);
	win.attach(*outerRect);
	auto innerRect = new Graph_lib::Rectangle(Point(frameWidth, frameWidth), rectWidth, rectHeight);
	innerRect->set_color(Graph_lib::Color::white);
	innerRect->set_fill_color(Graph_lib::Color::white);
	win.attach(*innerRect);
	win.wait_for_button();
}

int main()
{
	try
	{
		Point top_left{ 100, 100 };
		Simple_window win{ top_left, 600, 400, "My Window" };
		Exercise1(win);
		Exercise2(win);
		Exercise3(win);
		Exercise4(win);
		Exercise5(win);
	}
	catch (exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}
}