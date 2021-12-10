#include <iostream>
#include <sstream>
#include <string>
#include <ostream>
#include "Set_of_integers.h"
using namespace std;

int main()
{
	int set1[] = { 1,2,3,4,5,6,7,8,9,10 };
	int length_of_set = sizeof(set1)/sizeof(int);
	int set2[] = { 1,2,3,4,5,6,7,8,9,11 };
	Set_of_integers set11(set1, (sizeof(set1) / sizeof(int)));
	Set_of_integers set22(set2, (sizeof(set2) / sizeof(int)));
	//set11 + 12;
	set22 - 6;
}

