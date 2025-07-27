// Write a program that produces the sum of all the numbers in a file of whitespace-separated integers.

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
        string filename;
        cin >> filename;
        vector <int> integerNums;
        readFile(integerNums, filename);
        int sum = calculateSum(integerNums);
        cout << "The sum of numbers in the File is: " << sum;
    }
    catch (exception& e)
    {
        cerr << "Exception: " << e.what() << endl;
    }
}

