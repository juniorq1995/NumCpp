// NumCpp.cpp : Defines the entry point for the application.
#pragma once
#ifndef _H_NUMCPP
#define _H_NUMCPP

#include "NumCpp.hpp"

NumCpp::~NumCpp()
{
}

NumCpp::NumCpp()
{
}

int NumCpp::getSize()
{
	return vLength; // implement for array
}

NumCpp NumCpp::operator+(NumCpp const &other)
{
	if (length != other.length) 
	{
		cout << "ERROR, operands must be of same LENGTH and TYPE";
		//return;
	}
	NumCpp newList = NumCpp();

	for (int i = 0; i < other.length; i++)
	{
		newList.append(other.intList.at(i) + intList.at(i));
	}
	return newList;
}

NumCpp NumCpp::operator-(NumCpp const &other)
{
	if (length != other.length)
	{
		cout << "ERROR, operands must be of same LENGTH and TYPE";
		//return;
	}
	NumCpp newList = NumCpp();

	for (int i = 0; i < other.length; i++)
	{
		newList.append(other.intList.at(i) - intList.at(i));
	}
	return newList;
}


ostream &operator<<(ostream & out, NumCpp n)
{
	out << n.get(0);
	for (int i = 1; i < n.size(); i++)
	{
		out << "," << n.get(i);
	}
	out << endl;
	return out;
}

ostream &operator<<(ostream &out, NumCpp::Type t)
{
	if (t == NumCpp::Int)
	{
		out << "Int";
	}
	else if (t == NumCpp::Double)
	{
		out << "Double";
	}
	else 
	{
		out << "Char";
	}
	return out;
}

void NumCpp::append(int num)
{
	intList.push_back(num);
	length++;
}

int NumCpp::get(int index)
{
	return intList.at(index);
}

NumCpp::Type NumCpp::getType()
{
	return type;
}

void NumCpp::print()
{
	cout << intList.at(0);
	for (int i = 1; i < intList.size(); i++)
	{
		cout <<","<< intList.at(i);
	}
	cout << endl;
}

int NumCpp::getSum()
{
	return sum;
} 


double NumCpp::getMean()
{
	return getSum() / getSize();
}

int NumCpp::getMedian()
{
	vector<int> tempVector;
	int tempSize;
	if (st == Array)
	{
		tempVector = this->order(intArray);
		tempSize = aSize;
	}
	if (st == List)
	{
		tempVector = this->order(intList);
		tempSize = vLength;
	}
	if (vLength % 2 == 0)
		return (tempVector.at(tempSize / 2) + tempVector.at(tempSize / 2)) / 2;
	else
		return tempVector.at(tempSize / 2 + 1);
}

double NumCpp::getVectorStd()
{
	double tempMean = getMean();
	double total = 0.0;
	for (int i = 0; i < vLength; i++)
	{
		total += pow(intList[i] - tempMean, 2.0);
	}
	return sqrt(total/ aSize);
}

double NumCpp::getArrayStd()
{
	double tempMean = getMean();
	double total = 0.0;
	for (int i = 0; i < vLength; i++)
	{
		for (int j = 0; j < aSize; j++)
		{
			total += pow(intArray[i][j] - tempMean, 2.0);
		}
	}
	return sqrt(total / aSize);
}

double NumCpp::getStd()
{
	if (st == Array) return getArrayStd();
	if (st == List) return getVectorStd();
	/*
	1. Work out the Mean(the simple average of the numbers)
	2. Then for each number: subtract the Mean and square the result
	3. Then work out the mean of those squared differences.
	4. Take the square root of that and we are done!
	*/

}
#endif
