// StrCH10Ex4b.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Modify the temp_stats.cpp program to test each temperature, converting the Celsius readings to 
// Fahrenheit before putting them into the vector.

#include "std_lib_facilities.h"

struct Reading
{
    int hour;
    double temperature;
    Reading() : hour(0), temperature(0) { }
};

istream& operator>>(istream& ist, Reading& data)
{
    ist >> data.hour >> data.temperature;
    if (!ist)
        return ist;
    return ist;
}

bool compareByTemperature(const Reading& a, const Reading& b)
{
    return a.temperature < b.temperature;
}

double calcMedian(vector<Reading>& readings)
{
    double middle1, middle2, middle;
    sort(readings.begin(), readings.end(), compareByTemperature);
    int n = readings.size();
    if (n % 2 == 0)
    {
        middle1 = readings[n / 2 - 1].temperature;
        middle2 = readings[n / 2].temperature;
        middle = (middle1 + middle2) / 2;
    }
    else
        middle = readings[n / 2].temperature;
    return middle;
}

double calcMean(vector<Reading>& readings)
{
    double sum = 0.0, mean;
    int n = readings.size();
    for (int i = 0; i < n; i++)
    {
        sum += readings[i].temperature;
    }
    mean = sum / n;
    return mean;
}

void evalCelsiusData(vector<Reading>& readings, char ch)
{
    if (ch == 'f')
    {
        cout << "Result: " << endl;
        cout << "Median: " << calcMedian(readings) << " Celsius" << endl;
        cout << "Mean: " << calcMean(readings) << " Celsius" << endl;
    }
    else if (ch == 'c')
    {
        cout << "Result: " << endl;
        cout << "Median: " << calcMedian(readings) << " Fahrenheit" << endl;
        cout << "Mean: " << calcMean(readings) << " Fahrenheit" << endl;
    }
}

void readDataFromFile(vector<Reading>& readings, const string& fname)
{
    ifstream ist(fname.c_str());
    if (!ist) throw runtime_error("Can't open file: " + fname);
    Reading data;
    char ch;
    while (ist >> data)
    {
        ist >> ch;
        if (ch == 'f')
        {
            data.temperature = (data.temperature - 32) * 5.0 / 9.0;
            readings.push_back(data);
        }
        else if (ch == 'c')
        {
            data.temperature = (data.temperature * 9.0 / 5.0) + 32;
            readings.push_back(data);
        }
    }
    evalCelsiusData(readings, ch);
}

int main()
{
    string filepath = "C:\\Users\\bernd\\Downloads";
    string filename = "raw_temps.txt";
    string fullFilePath = filepath + "\\" + filename;
    vector<Reading> readings;
    readDataFromFile(readings, fullFilePath);
}