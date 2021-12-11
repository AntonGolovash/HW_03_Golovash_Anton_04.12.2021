#include <iostream>
#include <sstream>
#include <string>
#include <ostream>
#include "Set_of_integers.h"
using namespace std;

int main()
{
	setlocale(LC_ALL, "ru");
	int set1[] = { 1,2,3,8,5,9,12,74,63 };
	int set2[] = { 1,2,3,4,5,6,7,8,9,11 };

	Set_of_integers set11(set1, (sizeof(set1) / sizeof(int)));
	Set_of_integers set22(set2, (sizeof(set2) / sizeof(int)));

	cout << "Множество set11\n" << set11 << endl;
	cout << "Множество set22\n" << set22 << endl;

	set11 += set22;
	cout << "Множество set11 += set22\n" << set11 << endl;


	set22 += set11;
	cout << "Множество set22 += set11\n" << set22 << endl;


	set11 + 999;
	cout << "Множество set11 + 999\n" << set11 << endl;

	set22 - 9999;
	cout << "Множество set22 - 9999\n" << set22 << endl;

	set22 - 6;
	cout << "Множество set22 - 6\n" << set22 << endl;

	set11 / set22;
	cout << "Разность множеств set11 / set22\n" << set11 << endl;

	set22 / set11;
	cout << "Разность множеств set22 / set11\n" << set22 << endl;

}

