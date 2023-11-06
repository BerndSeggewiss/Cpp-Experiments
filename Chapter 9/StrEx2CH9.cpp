/*
2. Design and implement a ‘Name_pairs’ class holding (name, age)
pairs where name is a string and age is a double. Represent that
as a vector<string> (called name) and a vector<double> (called age) 
member. Provide an input operation read_names() that reads a series
of names. Provide a read_ages() operation that prompts the user for an 
age for each name. Provide a print() operation that prints out the 
(name[i], age[i]) pairs (one per line) in the order determined by the 
name vector. Provide a sort() operation that sorts the name vector in
alphabetical order and reorganizes the age vector to match. Implement 
all ‘operations’ as member functions. Test the class.
*/

#include "std_lib_facilities.h"

class Name_Pairs
{
    public:
        void read_names();
        void read_ages();
        void print_name_age_pairs();
        void sort_name_ages();
    private:
        vector<string> names;
        vector<double> ages;
};


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
        cout << "Age of: " << names[i] << ": ";
        cin >> a;
        ages.push_back(a);
    }
}

void Name_Pairs::print_name_age_pairs()
{
    for (int i = 0; i < names.size(); i++)
    {
        cout << names[i] << ", " << ages[i] << endl;
    }
}

int main()
{
    Name_Pairs namepairs;
    namepairs.read_names();
    namepairs.read_ages();
    namepairs.print_name_age_pairs();
    namepairs.sort_name_ages();
    cout << "Sorted name value pairs: " << endl;
    namepairs.print_name_age_pairs();
}
