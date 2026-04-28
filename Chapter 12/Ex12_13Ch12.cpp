// No. 12: A superellipse is a two-dimensional curve defined by the equation |x/a|^m + |y/b|^n = 1 and m, n > 0.
// Write a program that draws "starlike" patterns by connecting points on a superellipse. Take a, b, m, n and N
// as arguments. Select N points points on the superellipse defined by a, b, m and n. Make the points equally
// spaced for some definition of "equal". Connect each of those points (if you like you can make the number of
// points to which to connect a point another argument or just use N-1, i.e., all the other points).
// No. 13: Find a way to add the lines from the previous excerscise. Make some lines one color and other lines
// another color. 

#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Graph.h"  
#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Simple_window.h"
#include <cmath>

const double PI = 3.14159;

struct CurvePoint
{
    double x;
    double y;
};

double sgn(double val)
{
    if (val > 0)
        return 1.0;
    else if (val < 0)
        return -1.0;
    else
        return 0.0;
}

vector<CurvePoint> generateSuperellipse(double a, double b, double m, double n, int N)
{
    vector <CurvePoint> points;
    for (int i = 0; i < N; ++i)
    {
        double t = i * 2.0 * PI / N;
        double x = a * sgn(cos(t)) * pow(abs(cos(t)), 2.0 / m);
        double y = b * sgn(sin(t)) * pow(abs(sin(t)), 2.0 / n);
        points.push_back({ x, y });
    }
    return points;
}

int main()
{
    using namespace Graph_lib;
    double a = 1.0;
    double b = 1.0;
    double m = 2;
    double n = 0.5;
    int N = 16;
    vector<CurvePoint> result = generateSuperellipse(a, b, m, n, N);
    Point top_left{ 100, 100 };
    int WinWidth = 600;
    int WinHeight = 600;
    Simple_window win{ top_left, WinWidth, WinHeight, "Superellipse starlike pattern" };
    int xCenter = WinWidth / 2;
    int yCenter = WinHeight / 2;
    int scale = 200;
    vector <Point> screenPoints;
    for (const auto& p : result)
    {
        screenPoints.push_back(Point(xCenter + static_cast<int>(p.x * scale),
            yCenter - static_cast<int>(p.y * scale)));
    }
    vector<int> ColorPalette =
    {
        Color::red,
        Color::blue,
        Color::dark_green,
        Color::magenta,
        Color::dark_cyan,
        Color::dark_yellow
    };
    Graph_lib::Vector_ref<Graph_lib::Line> starLines;
    Graph_lib::Lines starPattern;
    int ColorIndex = 0;
    int x;
    for (size_t i = 0; i < screenPoints.size(); ++i)
    {
        for (size_t j = i + 1; j < screenPoints.size(); ++j)
        {
            //starPattern.add(screenPoints[i], screenPoints[j]);
            starLines.push_back(new Graph_lib::Line(screenPoints[i], screenPoints[j]));
            ColorIndex++;
            x = ColorIndex % size(ColorPalette);
            starLines[starLines.size() - 1].set_color(ColorPalette[ColorIndex % size(ColorPalette)]);
            win.attach(starLines[starLines.size() - 1]);
        }
    }
    win.attach(starPattern);
    win.wait_for_button();
    return 0;
}