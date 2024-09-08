// StrRomanIntClass.cpp :
// Define a Roman_int class for holding Roman numerals (as ints)
// with a << and >>. Provide Roman_int() member that returns the
// int value, so that if r is a Roman_int, we can write cout <<  
// “Roman “ << r << “equals “ << r.as_int() << “\n”.

#include "ch10ex6.h"

int Roman_int::as_int() const
{
    unordered_map<char, int> LetterMap = {
        {'I', 1}, {'V', 5}, {'X', 10}, {'L', 50},
            {'C', 100}, {'D', 500}, {'M', 1000}
    };
    int preValue = 0, total = 0;
    for (auto i = romanVal.rbegin(); i != romanVal.rend(); ++i)
    {
        int value = LetterMap[*i];
        if (value < preValue)
        {
            total -= value;
        }
        else
        {
            total += value;
        }
        preValue = value;
    }
    return total;
}

ostream& operator << (ostream& os, const Roman_int& r)
{
    os << r.romanVal;
    return os;
}

int main()
{
    Roman_int r("IX");
    cout << "Roman: " << r << " equals " << r.as_int() << "\n";
    return 0;
}
