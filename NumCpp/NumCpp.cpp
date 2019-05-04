// NumCpp.cpp : Defines the entry point for the application.
//

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
	}
	va_end(arguments);                  // Cleans up the list

}

void NumCpp::Print()
{
	for (int i = 0; i < intList.size(); i++)
	{
		cout << intList.at(i);
	}
}
