// StrCH11Ex9.cpp : This file contains the 'main' function. Program execution begins and ends there.
// Split the binary program from chapter 11.3.2 into two: one program that converts an
// oridnary text file into binary and one that reads binary and converts it to text. Test
// these programs by comparing a text file with what you get by converting it to binary and
// back.

#include "std_lib.h"

namespace fs = std::experimental::filesystem;
ifstream openInputFile(const string& filePath)
{
	ifstream ifs(filePath, ios::binary);
	if (!ifs)
		error("can't open input file", filePath);
	return ifs;
}

ofstream openOutputFile(const string& filePath)
{
	ofstream ofs(filePath, ios::binary);
	if (!ofs)
		error("Can't open output file ", filePath);
	return ofs;
}

void convertText2binary()
{
	string FilePath = "C:\\Users\\Win11 Pro\\Downloads";
	string FileName = "TextfileCH11Ex9.txt";
	string fullFilePath = FilePath + "\\" + FileName;
	ifstream ifs = openInputFile(fullFilePath);
	string binaryFileName = "BinaryfileCH11Ex9.bin";
	string binaryFilePath = FilePath + "\\" + binaryFileName;
	ofstream ofs = openOutputFile(binaryFilePath);
	cout << "Writing File: " << binaryFilePath << '\n';
	char ch;
	while (ifs.get(ch))
		ofs.write(reinterpret_cast<const char*>(&ch), sizeof(ch));
}

void convertBinary2Text()
{
	string FilePath = "C:\\Users\\Win11 Pro\\Downloads";
	string FileName = "BinaryfileCH11Ex9.bin";
	string fullFilePath = FilePath + "\\" + FileName;
	ifstream ifs = openInputFile(fullFilePath);
	string textFileName = "TextfileCH11Ex9_Copy.txt";
	string textFilePath = FilePath + "\\" + textFileName;
	ofstream ofs = openOutputFile(textFilePath);
	cout << "Writing File: " << textFilePath << '\n';
	char ch;
	while (ifs.get(ch))
		ofs.write(reinterpret_cast<const char*>(&ch), sizeof(ch));
}

int main()
{
	try
	{
		convertText2binary();
		convertBinary2Text();
	}
	catch (exception& e)
	{
		cerr << "exception: " << e.what() << '\n';
		return 1;
	}
}

