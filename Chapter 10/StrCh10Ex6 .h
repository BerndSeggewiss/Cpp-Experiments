#include "std_lib_facilities.h"


class Roman_int
{
public:
    Roman_int(const string& roman) : romanVal(roman) {}
    int as_int() const;
    friend ostream& operator << (std::ostream& os, const Roman_int& r);

private:
    string romanVal;
};
