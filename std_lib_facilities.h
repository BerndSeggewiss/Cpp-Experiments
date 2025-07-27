#ifndef STD_LIB_FACILITIES_H
#define STD_LIB_FACILITIES_H

#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <list>
#include <forward_list>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <array>
#include <regex>
#include <random>
#include <stdexcept>

using namespace std;

// Simple error function
inline void error(const string& s)
{
    throw runtime_error(s);
}

inline void error(const string& s, const string& s2)
{
    error(s + s2);
}

#endif // STD_LIB_FACILITIES_H