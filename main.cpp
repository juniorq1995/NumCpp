#include <iostream>
#include "NumCpp.h"

int main() {
	NumCpp test = NumCpp(4,4,3,2,1);
	NumCpp test2 = NumCpp(4, 1, 2, 3, 4);
	NumCpp finalTest = test + test2;
	cout<<finalTest;
	return 0;
};