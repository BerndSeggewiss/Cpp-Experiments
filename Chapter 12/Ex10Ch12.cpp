// No. 10: Draw the file diagram from chapter 12.8 

#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Graph.h"  
#include "..\..\..\OneDrive\Codesammlung\C++\Stroustr Prog - Principles and Practise Using C++\libs\Simple_window.h"

struct CaptionLine
{
    string text;
    Point position;
    bool bold = false;
};

void addLabeldBox(Simple_window& win,
    Point topLeft,
    const int boxWidth,
    const int boxHeight,
    const string& titleText,
    const std::vector<CaptionLine>& captionLines)
{
    const int titleFontSize = 12;
    const int captionFontSize = 12;

    const int titleOffsetY = 5; // above box
    const int captionOffsetX = 5;
    const int captionOffsetY = 20;
    const int lineSpacing = 15;
    // Box
    auto* box = new Graph_lib::Rectangle{ topLeft, boxWidth,  boxHeight };
    box->set_fill_color(Graph_lib::Color::yellow);
    box->set_color(Graph_lib::Color::black);
    // Title over box
    auto* title = new Text{
        Point{topLeft.x, topLeft.y - titleOffsetY},
        titleText
    };
    title->set_font_size(titleFontSize);
    title->set_font(Graph_lib::Font::helvetica_bold);
    title->set_color(Graph_lib::Color::black);
    // Caption in box
    std::vector<Text*> captions;
    for (size_t i = 0; i < captionLines.size(); ++i)
    {
        const auto& line = captionLines[i];
        Point linePos{
            topLeft.x + 10 + captionOffsetX,
            topLeft.y + captionOffsetY + static_cast<int>(i) * lineSpacing
        };
        auto* caption = new Text{ linePos, line.text };
        caption->set_font_size(captionFontSize);
        caption->set_font(line.bold
            ? Graph_lib::Font::helvetica_bold
            : Graph_lib::Font::helvetica);
        caption->set_color(Graph_lib::Color::black);
        captions.push_back(caption);
    }
    win.attach(*box);
    win.attach(*title);
    for (auto* caption : captions)
        win.attach(*caption);
}

void addArrow(Simple_window& win, Point startPosition, Point endPosition)
{
    // Arrow shaft
    auto* shaft = new Graph_lib::Line{ startPosition, endPosition };
    shaft->set_color(Graph_lib::Color::black);
    win.attach(*shaft);
    // Vector from start to end
    const double dx = static_cast<double>(endPosition.x - startPosition.x);
    const double dy = static_cast<double>(endPosition.y - startPosition.y);
    const double length = sqrt(dx * dx + dy * dy);
    // Unit vectors in direction of arrow
    const double ux = dx / length;
    const double uy = dy / length;
    // Coordinate where base of arrowhead starts
    const double height = 10.0;
    const double baseCx = endPosition.x - ux * height;
    const double baseCy = endPosition.y - uy * height;
    // Vertical unit vector (orthogonal to (ux, uy))
    const double px = -uy;
    const double py = ux;
    const double PolygonWidth = 6.0;
    // Two base corners of arrowhead
    Point p1{
        static_cast<int>(baseCx + px * (PolygonWidth / 2.0)),
        static_cast<int>(baseCy + py * (PolygonWidth / 2.0))
    };
    Point p2{
        static_cast<int>(baseCx - px * (PolygonWidth / 2.0)),
        static_cast<int>(baseCy - py * (PolygonWidth / 2.0))
    };
    auto* head = new Graph_lib::Polygon{};
    head->add(endPosition);
    head->add(p1);
    head->add(p2);
    head->set_fill_color(Color::black);
    head->set_color(Color::black);
    win.attach(*head);
}

int main()
{
    using namespace Graph_lib;
    Point top_left{ 500, 100 };
    Simple_window win{ top_left, 600, 400, "Canvas" };
    addLabeldBox(
        win,
        Point{ 30, 50 },
        120,
        35,
        "Point.h",
        {
            CaptionLine{ "struct Point {...};", Point{}, true }
        }
    );
    addLabeldBox(
        win,
        Point{ 30, 130 },
        140,
        55,
        "Graph.h",
        {
            CaptionLine{ "Graphing interace:", Point{}, false },
            CaptionLine{ "struct shape {...};", Point{}, true }
        }
    );
    addLabeldBox(
        win,
        Point{ 200, 10 },
        120,
        35,
        "",
        {
            CaptionLine{ "FLTK headers", Point{}, false }
        }
    );
    addArrow(
        win,
        Point{ 30 + 60, 130 },    //start point
        Point{ 30 + 60, 50 + 35 }
    );
    addArrow(
        win,
        Point{ 30 + 60, 130 },    //start point
        Point{ 200 + 10, 10 + 35 }
    );
    addLabeldBox(
        win,
        Point{ 200 - 5, 110 },
        150,
        55,
        "Window.h",
        {
            CaptionLine{ "// window interface", Point{}, false },
            CaptionLine{ "class Window", Point{}, true },
            CaptionLine{ "...", Point{}, false }
        }
    );
    addArrow(
        win,
        Point{ 195 + 150 / 2, 110 },    //start point
        Point{ 195 + 150 / 2, 10 + 35 }
    );
    addLabeldBox(
        win,
        Point{ 30 + 110, 130 + 85 },
        100,
        30,
        "window.cpp:",
        {
            CaptionLine{ "Window code", Point{}, false }
        }
    );
    addArrow(
        win,
        Point{ 30 + 190, 130 + 85 },    //start point
        Point{ 200 - 5 + 20 + 40, 110 + 55 }
    );
    addLabeldBox(
        win,
        Point{ 30, 260 },
        100,
        30,
        "Graph.cpp:",
        {
            CaptionLine{ "Graph code", Point{}, true }
        }
    );
    addArrow(
        win,
        Point{ 100, 260 },    //start point
        Point{ 100 , 130 + 55 }
    );
    addLabeldBox(
        win,
        Point{ 180, 300 },
        170,
        50,
        "Simple_window.h:",
        {
            CaptionLine{ "// window interface", Point{}, false },
            CaptionLine{ "class Simple_window {...};", Point{}, true }
        }
    );
    addArrow(
        win,
        Point{ 290, 300 },    //start point
        Point{ 290, 110 + 55 }
    );
    win.wait_for_button();
    return 0;
}