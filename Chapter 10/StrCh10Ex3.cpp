/*Write a program that reads the data from ‘raw_temps.txt’ created in exercise 2 
into a vector and then calculates the mean and median temperature in your data set.*/

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

void readDataFromFile(vector<Reading>& readings, const string& fname)
{
    ifstream ist(fname.c_str());
    if (!ist) throw runtime_error("Can't open file: " + fname);
    Reading data;
    while (ist >> data)
        readings.push_back(data);
}

bool compareByTemperature(const Reading& a, const Reading& b)
{
    return a.temperature < b.temperature;
}

double calcMedian(vector<Reading>& readings)
{
    double middle1, middle2, middle;
    sort( readings.begin(), readings.end(), compareByTemperature);
    int n = readings.size();
    if (n % 2 == 0)
    {
         middle1 = readings[n/2 - 1].temperature;
         middle2 = readings[n/2].temperature;
         middle = (middle1 + middle2) / 2;
    }
    else
        middle = readings[n/2].temperature;
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

int main()
{
    string filepath = "C:\\Users\\bernd\\Downloads";
    string filename = "raw_temps.txt";
    string fullFilePath = filepath + "\\" + filename;
    vector<Reading> readings;
    readDataFromFile(readings, fullFilePath);
    cout << "Result: " << endl;
    cout << "Median: " << calcMedian(readings) << " Degree centigrade" << endl;
    cout << "Mean: " << calcMean(readings) << " Degree centigrade" << endl;
}
