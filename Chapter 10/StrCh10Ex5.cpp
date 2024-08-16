#include "std_lib_facilities.h"

struct Year
{
    int year;
};

istream& operator >> (istream& is, Year& y)
{
    char ch = 0;
    is >> ch;

    if (ch != '{')
    {
        is.unget();
        is.clear(ios::failbit);
        return is;       
    }

    string type;
    is >> type;

    if (type == "year")
    {
        is >> y.year;
    }

    is >> ch;
    return is;
}

void readDatafromFile(string fileName, vector<Year>& ys) 
{
    string filePath = "C:\\Users\\Win11 Pro\\Downloads";
    string fullFilePath = filePath + "\\" + fileName;
    ifstream ifs(fullFilePath.c_str());

    if (!ifs)
    {
        cerr << "Error opening file: " << fullFilePath << endl;
        return;
    }

    while (true)
    {   
        Year y;
        if (!(ifs >> y))
            break;
        ys.push_back(y);
    }
}

int main()
{
    cout << "Enter input file name: ";
    string name;
    cin >> name;
    vector<Year> ys;
    readDatafromFile(name, ys);

    for (int i = 0; i < ys.size(); i++)
    {
        cout << ys[i].year << endl;
    }
}