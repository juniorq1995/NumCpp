// NumCpp.cpp : Defines the entry point for the application.
#pragma once
#ifndef _H_NUMCPP
#define _H_NUMCPP

#include "NumCpp.h"

using namespace std;

NumCpp::~NumCpp()
{

}

NumCpp::NumCpp()
{

}

NumCpp::NumCpp(int num, ...)
{
	/* Initializing arguments to store all values after num */
	va_start(arguments, num);
	/* Sum all the inputs; we still rely on the function caller to tell us how
	 * many there are */
	for (int i = 0; i < num; i++)
	{
		intList.push_back(va_arg(arguments, int));
		length++;
	}
	va_end(arguments);                  // Cleans up the list
	type = IntList;
}

int NumCpp::size()
{
	return length;
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
#endif
