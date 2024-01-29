// StrDrillCh10.cpp : This file contains the 'main' function. Program execution begins and ends there.
/*
1. Start a program to work with points, discussed in chapter 10.4.Begin by defining the data type Point
that has two coordinate members x and y.
2. Using the code and discussion in chapter 10.4, prompt the user to input seven(x,y) pairs.
As the data is entered, store ist in a vector of Points called original_points.
3. Print the data in original_points to see what it looks like.
4. Open an ofstream and output each point to a file named mydata.txt.On Windows, we suggest
the.txt sufffix to make it easier to look at the dat with an ordinary text editor.
5 Close the ofstream and then open a ifstream for file mydata.txt.Read the data from mydata.txt
and store it in a new vector called processed_points.
6 Print the data elements from both vectors.
7. Comapare the two vectors and print ‘Something’s wrong!’ if the number of elements or the values
of elements differ.
*/

#include "std_lib_facilities.h"

struct Point
{
    int x, y;
    Point() :x(0), y(0) { }
    Point(int x_, int y_) : x(x_), y(y_) { }
};

istream& operator >> (istream& is, Point& p)
{
    int x, y;
    char ch1, ch2, ch3;
    is >> ch1 >> x >> ch2 >> y >> ch3;
    if (!is) return is;
    if (ch1 != '(' || ch2 != ',' || ch3 != ')') // Überprüfen des Formats
    {
        is.clear(ios_base::failbit); // Eingabefehler setzen
        return is;
    }
    p = Point(x, y);
    return is;
}

ostream& operator << (ostream& os, const Point& p)
{
    os << "(" << p.x << ", " << p.y << ")";
    return os;
}

void print_points(const vector<Point>& points)
{
    cout << endl;
    for (const Point& p : points)
    {
        cout << p << "\n";
    }
}

void writePoints2File(const vector<Point>& points, const string& filename)
{
    ofstream ost(filename);
    if (!ost.is_open())
        cerr << "\nCould not open file... ";
    for (int i = 0; i < points.size(); i++)
        ost << points[i] << " " << endl;
    ost.close();
    if (ost.is_open())
        cout << "\nFile open...";
    else
        cout << "\nFile closed...";
}

vector<Point> readPointsfromFile(const vector<Point>& points, const string& filename)
{
    ifstream ist(filename);
    if (!ist.is_open())
        cerr << "\nCould not open file... ";
    Point p;
    vector<Point> processed_points;
    while (ist >> p)
    {
        processed_points.push_back(p);
    }
    return processed_points;
}

int main()
{
    vector<Point> original_points;
    cout << "Put in seven (x,y) pairs: \n";
    Point p;
    for (int i = 0; i < 7; i++)
    {
        cin >> p;
        original_points.push_back(p);
    }
    cout << "Print original points: ";
    print_points(original_points);
    cout << "Save points to file... ";
    string filename = "C:\\Users\\bernd\\Downloads\\myData.txt";
    writePoints2File(original_points, filename);
    cout << "\nPrint processed points: ";
    vector<Point> processed_points;
    processed_points = readPointsfromFile(processed_points, filename);
    print_points(processed_points);
}
