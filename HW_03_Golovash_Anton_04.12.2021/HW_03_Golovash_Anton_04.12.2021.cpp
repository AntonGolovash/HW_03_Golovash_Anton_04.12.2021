#include <iostream>
#include <sstream>
#include <string>
#include <ostream>
#include "Set_of_integers.h"
using namespace std;

int main()
{
	int set1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int set2[] = { 1,2,3,4,5,6,7,8,9,10 };
	Set_of_integers set_1(set1);
	Set_of_integers set_2(set2);
	set_1 + 12;
}

