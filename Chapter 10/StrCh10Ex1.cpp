#include "std_lib_facilities.h"

void readFile(vector<int>& integers, const string& fname)
{
    ifstream file(fname);
    if (!file)
    {
        cerr << "Can't open file: " << fname << endl;
        return;
    }
    int num;
    while (file >> num)
    {
        integers.push_back(num);
    }
}

int calculateSum(const vector<int>& numbers)
{
    int sum = 0;
    for (int num : numbers)
    {
        sum += num;
    }
    return sum;
}

int main()
{
    cout << "Enter filename: ";
    try 
    {
        string filepath = "C:\\Users\\bernd\\Downloads";
        string filename;
        cin >> filename;
        string fullFilePath = filepath + "\\" + filename;
        vector <int> integerNums;
        readFile(integerNums, fullFilePath);
        int sum = calculateSum(integerNums);
        cout << "The sum of numbers in the File is: " << sum;
    }
    catch (exception& e)
    {
        cerr << "Exception" << e.what() << endl;
    }
}

