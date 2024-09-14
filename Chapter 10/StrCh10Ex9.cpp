// StrCh10Ex9.cpp :
// Write a program that takes two files containing sorted 
// whitespace-separated words and merges them, preserving order. 

#include "std_lib_facilities.h"
#include "random"

int main()
{
    string filePath = "C:\\Users\\Win11 Pro\\Downloads";
    string fileName1 = "file1.txt";
    string fileName2 = "file2.txt";
    string fullFilePath1 = filePath + "\\" + fileName1;
    string fullFilePath2 = filePath + "\\" + fileName2;
    ifstream file1(fullFilePath1);
    ifstream file2(fullFilePath2);
    if (!file1.is_open() || !file2.is_open())
    {
        cerr << "One or more of the files could not be opened" << endl;
        return 1;
    }
    vector<string> words1, words2;
    string word;
    while (file1 >> word) {
        words1.push_back(word);
    }
    while (file2 >> word) {
        words2.push_back(word);
    }
    file1.close();
    file2.close();
    vector<string> mergedWords;
    auto it1 = words1.begin();
    auto it2 = words2.begin();
    while (it1 != words1.end() && it2 != words2.end())
    {
        if (*it1 < *it2)
        {
            mergedWords.push_back(*it1);
            ++it1;
        }
        else
        {
            mergedWords.push_back(*it2);
            ++it2;
        }
    }
    for (const auto& word : mergedWords)
    {
        cout << word << " ";
    }
    cout << endl;
    return 0;
}
