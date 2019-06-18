// NumCpp.h : Include file for standard system include files,
// or project specific include files.
// https://webcourses.ucf.edu/courses/1249560/pages/cmake-setting-up-a-library-c++-code-overview?module_item_id=10524230

#pragma once

#include <iostream>
#include <vector>
using namespace std;
// TODO: Reference additional headers your program requires here.
class NumCpp
{
private:
	enum Type { IntList, DoubleList, CharList };
	vector<int> intList;
	vector<vector<int> > intArray;
	Type type;
	int length = 0;
public:
	~NumCpp();
	NumCpp();

	template<typename T>
	NumCpp::NumCpp(T first)
	{
		intList.push_back(first);
	}

	template<typename T, typename ...Args>
	NumCpp::NumCpp(T first, Args... args)
	{
		intList.push_back(first);
		length++;
		NumCpp(args...)
	}

	template<typename T>
	vector<int> arr(initializer_list<T> l)
	{
		const T*       it = l.begin();  // raw pointer!
		const T* const end = l.end();    // raw pointer!

		for (; it != end; ++it)
		{
			length++;
			intList.push_back(*it);
		}

		return intList;
	}

	template<typename T>
	vector<vector<int> > arr(initializer_list<initializer_list<T> > arr)
	{
		const initializer_list<T>* it = arr.begin();  // raw pointer!
		const initializer_list<T>* const end = arr.end();    // raw pointer!

		for (; it != end; ++it)
		{
			vector<T> row;
			const T* rowStart = (*it).begin();
			const T* const rowEnd = (*it).end();
			for (; rowStart != rowEnd; ++rowStart)
			{
				row.push_back(*rowStart);
			}
			intArray.push_back(row);

		}
		return intArray;
	}

	int NumCpp::size();

	NumCpp operator+(NumCpp const &other);
	NumCpp operator-(NumCpp const &other);

	friend ostream &operator<<(ostream &out, NumCpp n);
	friend ostream &operator<<(ostream &out, Type t);

	void NumCpp::append(int num);
	int NumCpp::get(int index);
	Type NumCpp::getType();
	void print();

};