// 3. Replace ‘Name_pair::print()’ with a (global) operator << and define == and != for Name_pairs.

#include <iostream>
#include "std_lib_facilities.h"

class Name_Pairs
{
public:
    void read_names();
    void read_ages();
    void print_name_age_pairs();
    void sort_name_ages();
    const vector<string>& getName() const { return names; }
    const vector<double>& getAge() const { return ages; }
private:
    vector<string> names;
    vector<double> ages;
};

ostream& operator << (ostream& os, const Name_Pairs& p)
{
    for (int i = 0; i < p.getName().size(); i++)
    {
        os << '('<< p.getName()[i] << ',' << p.getAge()[i] << ')' << endl;
    }
    return os;
}

void Name_Pairs::sort_name_ages()
{
    vector<string> originalNames = names;
    vector<double> agesSorted;
    sort(names.begin(), names.end());
    for (int i = 0; i < names.size(); i++)
    {
        for (int j = 0; j < names.size(); j++)
        {
            if (names[i] == originalNames[j])
            {
                agesSorted.push_back(ages[j]);
            }
        }
    }
    ages = agesSorted;
}

void Name_Pairs::read_names()
{
    cout << "Put in Names. Finish with 'Q': \n";
    string str;
    while (cin >> str && str != "Q")
    {
        names.push_back(str);
    }
}

void Name_Pairs::read_ages()
{
    cout << "Put in ages of persons. Finish with 'Q': \n";
    double a;
    for (int i = 0; i < names.size(); i++)
    {
        cout << "Age of " << names[i] << ": ";
        cin >> a;
        ages.push_back(a);
    }
}

void Name_Pairs::print_name_age_pairs()
{
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << "," << ages[i] << endl;
    }
}

bool operator == (const Name_Pairs& a, const Name_Pairs& b)
{
    for (int i = 0; i < a.getName().size(); i++)
    {
        if (a.getName()[i] != b.getName()[i])
        {
            return false;
        }
    }
    for (int i = 0; i < a.getAge().size(); i++)
    {
        if (a.getAge()[i] != b.getAge()[i])
        {
            return false;
        }
    }
    return true;
}

bool operator != (const Name_Pairs& a, const Name_Pairs& b)
{
    return !(a == b);
}

int main()
{
    cout << "First Name/Value-Pair:\n";
    Name_Pairs firstNamepairs;
    firstNamepairs.read_names();
    firstNamepairs.read_ages();
    firstNamepairs.print_name_age_pairs();
    firstNamepairs.sort_name_ages();
    cout << "Sorted name value pairs: " << endl;
    firstNamepairs.print_name_age_pairs();
    cout << "First name/age-pairs:\n" << firstNamepairs;
    Name_Pairs secondNamepairs;
    secondNamepairs.read_names();
    secondNamepairs.read_ages();
    secondNamepairs.print_name_age_pairs();
    secondNamepairs.sort_name_ages();
    secondNamepairs.print_name_age_pairs();
    cout << "Sorted name value pairs: " << endl;
    cout << "First name/age-pairs:\n" << secondNamepairs;
    if (firstNamepairs != secondNamepairs)
        cout << "Name Pairs are not identical";
    if (firstNamepairs == secondNamepairs)
        cout << "Name Pairs are identical";
}