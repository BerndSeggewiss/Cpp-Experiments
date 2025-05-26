/*
1. Get an empty ‘Simple_Window’ with the size 600 by 400 and a label My window compiled, linked, and run.
2. Now add the examples from chapter 12 one by one, testing between each added subsection example.
3. Go through and make one minor change(e.g., in color, in location, or in number of points) to each of the subsection examples.
*/

#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Graph.h"  
#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Simple_window.h"  

int main()
{
	try
	{
		Point top_left{ 100, 100 };
		Simple_window win{ top_left, 600, 400, "My Window" };

		Graph_lib::Polygon poly;
		poly.add(Point(300, 200));
		poly.add(Point(350, 100));
		poly.add(Point(400, 200));
		poly.set_color(Color::blue); // Color: blue
		win.attach(poly);
		win.wait_for_button();

		Axis xa(Axis::x, Point(20, 300), 280, 10, "axis");
		xa.set_color(Color::dark_green); // Color: dark_green
		win.attach(xa);
		win.set_label("Canvas #2");
		win.wait_for_button();

		Axis ya(Axis::y, Point(20, 300), 280, 5, "yaxis"); // 5 notches
		ya.set_color(Color::cyan);
		ya.label.set_color(Color::dark_red);
		win.attach(ya);
		win.set_label("Canvas #3");
		win.wait_for_button();

		Function sine(sin, 0, 100, Point(20, 150), 1000, 50, 50);
		sine.set_color(Color::magenta); // Color: magenta
		win.attach(sine);
		win.set_label("Canvas #4");
		win.wait_for_button();

		Graph_lib::Rectangle r(Point(200, 200), 120, 60); // Change: Width, height
		win.attach(r);
		win.set_label("Canvas #6");
		win.wait_for_button();

		Closed_polyline polyRectangle;
		polyRectangle.add(Point(100, 50));
		polyRectangle.add(Point(200, 50));
		polyRectangle.add(Point(200, 100));
		polyRectangle.add(Point(100, 100));
		polyRectangle.add(Point(150, 110));
		win.attach(polyRectangle);
		win.set_label("Canvas #7");
		win.wait_for_button();

		r.set_fill_color(Color::yellow);
		poly.set_style(Line_style(Line_style::dash, 4));
		polyRectangle.set_style(Line_style(Line_style::dot, 2)); // Chnaged: dot
		polyRectangle.set_fill_color(Color::green);
		win.set_label("Canvas #8");
		win.wait_for_button();

		Text t(Point(150, 150), "Hello Canvas");
		win.attach(t);
		win.set_label("Canvas #9");
		win.wait_for_button();

		t.set_font(Font::courier_bold); // courier_bold
		t.set_font_size(20);
		win.set_label("Canvas #10");
		win.wait_for_button();

		string imagePath = "C:\\Users\\Win11 Pro\\OneDrive\\Codesammlung\\C++\\Stroustr Prog - Principles and Practise Using C++\\pictures\\";
		string fullImagePath1 = imagePath + "planes.jpg";
		Image im1(Point(120, 50), fullImagePath1); //New position
		win.attach(im1);
		win.set_label("Canvas #11");
		win.wait_for_button();

		im1.move(80, 150);	//Changed: move
		win.set_label("Canvas #12");
		win.wait_for_button();

		Circle c(Point(100, 200), 50);
		c.set_color(Color::dark_cyan);	// Changed: Color
		Graph_lib::Ellipse e(Point(100, 200), 75, 25);
		e.set_color(Color::dark_cyan); // Changed: Color
		Mark m(Point(100, 200), 'x');
		ostringstream oss;
		oss << "screen size: " << x_max() << "*" << y_max()
			<< "; window size: " << win.x_max() << "*" << win.y_max();
		Text sizes(Point(100, 20), oss.str());
		string fullImagePath2 = imagePath + "snow_cpp.jpg";
		Image cal(Point(225, 225), fullImagePath2);
		cal.set_mask(Point(40, 40), 200, 150);
		win.attach(c);
		win.attach(m);
		win.attach(e);
		win.attach(sizes);
		win.attach(cal);
		win.set_label("Canvas #13");
		win.wait_for_button();
	}
	catch (exception& e)
	{
		cerr << "exception: " << e.what() << endl;
	}
}