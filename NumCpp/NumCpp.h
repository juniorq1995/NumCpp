// NumCpp.h : Include file for standard system include files,
// or project specific include files.
// https://webcourses.ucf.edu/courses/1249560/pages/cmake-setting-up-a-library-c++-code-overview?module_item_id=10524230

#pragma once

#include <iostream>
#include <vector>
#include <stdarg.h>
using namespace std;
// TODO: Reference additional headers your program requires here.
class NumCpp
{
private:
	enum Type { IntList, DoubleList, CharList };
	va_list arguments;
	vector<int> intList;
	Type type;
	int length = 0;
public:
	~NumCpp();
	NumCpp();
	NumCpp(int num, ...);
	int NumCpp::size();
	NumCpp operator+(NumCpp const &other);
	friend ostream &operator<<(ostream &out, NumCpp n);
	void append(int num);
	int NumCpp::get(int index);
	Type NumCpp::getType();
	void print();

};