#include "Set_of_integers.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;


Set_of_integers::Set_of_integers()// конструктор по умолчанию
{
	length_of_set = 10;
	int* set_of_integers = new int[length_of_set];
}

Set_of_integers::Set_of_integers(int* incoming_set_of_integers)// конструктор с параметрами
{
	set_of_integers = incoming_set_of_integers;
	incoming_set_of_integers = nullptr;
}

Set_of_integers::Set_of_integers(const Set_of_integers& object)// конструктор копирования
{

}

Set_of_integers::~Set_of_integers()// деструктор
{
	*this = nullptr;
	delete[] this;
}

bool Set_of_integers::Belonging_of_an_element_to_a_set(int element)
{

	return false;
}

Set_of_integers& Set_of_integers::operator+(const int integer)// добавление элемента во множество
{
	int* new_set_of_integers = new int[length_of_set + 1];
	for (int i = 0; i < length_of_set; i++)
	{
		new_set_of_integers[i] = set_of_integers[i];

	}
	new_set_of_integers[length_of_set] = integer;
	set_of_integers = nullptr;
	set_of_integers = new_set_of_integers;
}

int& Set_of_integers::operator[](const int index)
{
	return set_of_integers[index];
}