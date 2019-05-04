// NumCpp.h : Include file for standard system include files,
// or project specific include files.
// https://webcourses.ucf.edu/courses/1249560/pages/cmake-setting-up-a-library-c++-code-overview?module_item_id=10524230

#pragma once

#include <iostream>
#include <vector>
#include <stdarg.h>

// TODO: Reference additional headers your program requires here.
class NumCpp
{
private:
	va_list arguments;
	vector<int> intList;
	enum Type {IntList, DoubleList, CharList};
	Type type;

public:
	~NumCpp();
	NumCpp();
	NumCpp(int num, ...);
	void Print();
};