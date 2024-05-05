// StrCh10Ex4a.cpp : This file contains the 'main' function. Program execution begins and ends there.

// Write a program that creates a file of data in the form of temperature
// Reading type defined in chapter 10.5. For testing, fill the file with
// at least 50 “temperature readings”. Call the file it creates raw_temps.txt.
// Modify the program to include a suffix c for celsius and f for fahrenheit.

#include "std_lib_facilities.h"
#include <random>

struct Reading
{
    int hour;
    double temperature;
    char scale;
};

void writeFile(vector<Reading>& data, const string& fname)
{
    ofstream ost(fname.c_str());
    if (!ost) error("Can't open output file");
    for (const Reading& r : data)
        ost << r.hour << ' ' << r.temperature << r.scale << endl;
}

ostream& operator<<(ostream& os, const Reading& r)
{
    return os << r.hour << ' ' << r.temperature;
}

const char fahrenheit = 'f';
const char celsius = 'c';

Reading makeTemperatureValues()
{
    random_device rand;
    default_random_engine eng{ rand() };
    uniform_real_distribution<double> urd(0, 1);
    double x = 20.0 * urd(eng);
    static int t = 0;
    t++;
    char s;
    s = fahrenheit;
    return Reading{ t, x , s };
}

int main()
{
    vector<Reading> readings;
    for (int i = 0; i < 51; i++)
    {
        readings.push_back(makeTemperatureValues());
    }
    string filepath = "C:\\Users\\bernd\\Downloads";
    string filename = "raw_temps.txt";
    string fullFilePath = filepath + "\\" + filename;
    writeFile(readings, fullFilePath);
    for (const Reading& r : readings)
    {
        cout << "Hour: " << r.hour << ", Temperature: " <<
            r.temperature << r.scale << endl;
    }
}
