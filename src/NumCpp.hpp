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
	enum Type { Int, Double, Char };
	enum Structure {Array, List};
	vector<int> intList;
	vector<vector<int> > intArray;
	Type type;
	Structure st;
	int vLength = 0; // for vectors and vectors of array
	int aSize = 0; // for array	
	int sum = 0;
	double getVectorStd();
	double getArrayStd();

 public:
	~NumCpp();
	NumCpp();

	template<typename T>
	NumCpp::NumCpp(T first)
	{
		st = NumCpp::List;
		intList.push_back(first);
	}

	template<typename T, typename ...Args>
	NumCpp::NumCpp(T first, Args... args)
	{
		sum += first;
		intList.push_back(first);
		vLength++;
		NumCpp(args...)
	}

	template<typename T>
	vector<int> arr(initializer_list<T> l)
	{
		st = NumCpp::List;
		const T*       it = l.begin();  // raw pointer!
		const T* const end = l.end();    // raw pointer!

		for (; it != end; ++it)
		{
			vLength++;
			sum += *it;
			intList.push_back(*it);
		}

		return intList;
	}

	template<typename T>
	vector<vector<int> > arr(initializer_list<initializer_list<T> > arr)
	{
		st = NumCpp::Array;
		const initializer_list<T>* it = arr.begin();  // raw pointer!
		const initializer_list<T>* const end = arr.end();    // raw pointer!

		for (; it != end; ++it)
		{
			vector<T> row;
			const T* rowStart = (*it).begin();
			const T* const rowEnd = (*it).end();
			for (; rowStart != rowEnd; ++rowStart)
			{
				aSize++;
				sum += *rowStart;
				row.push_back(*rowStart);
			}
			intArray.push_back(row);
			length = row.size();
		}
		return intArray;
	}


	NumCpp operator+(NumCpp const &other);
	NumCpp operator-(NumCpp const &other);
	NumCpp operator*(NumCpp const &other); // need to implement/test cross multiplication

	friend ostream &operator<<(ostream &out, NumCpp n);
	friend ostream &operator<<(ostream &out, Type t);

	void NumCpp::append(int num);
	int NumCpp::get(int index);
	Type NumCpp::getType();
	void print();
	int NumCpp::getSize();
	double getMean(); // need to implement/test
	int getSum(); // need to implement/test
	int getMedian(); // need to implement/test
	double getStd(); // need to implement/test
	double getDeterminant(); // need to implement/test
	vector<int> zeros(int i); // need to implement/test
	vector<vector<int> > zeros(int i, int j); // need to implement/test
	vector<int> ones(int i); // need to implement/test
	vector<vector<int> > ones(int i, int j); // need to implement/test
	vector<int> random(int i); // need to implement/test
	vector<vector<int> > random(int i, int j); // need to implement/test
	vector<int> arange(int start, int end); // need to implement/test
	vector<int> dot(vector<int>); // need to implement/test
	vector<vector<int> > dot(vector<vector<int> >); // need to implement/test
	vector<int> order(vector<int>) 
	{
		// need to implement/test, works for either matrix or vector
	}
	vector<int> order(vector<vector<int> >)
	{
		// need to implement/test, works for either matrix or vector
	}
};