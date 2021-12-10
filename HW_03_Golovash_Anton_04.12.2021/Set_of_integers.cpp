#include "Set_of_integers.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;


Set_of_integers::Set_of_integers()// конструктор по умолчанию
{
	length_of_set = 10;
	Set_of_integers::set_of_integers = new int[length_of_set];
	for (int i = 0; i < length_of_set; i++)
	{
		set_of_integers[i] = 0;
	}
}

Set_of_integers::Set_of_integers(int* incoming_set_of_integers, int length)// конструктор с параметрами
{
	Set_of_integers::length_of_set = length;
	Set_of_integers::set_of_integers = incoming_set_of_integers;
	incoming_set_of_integers = nullptr;
}

Set_of_integers::Set_of_integers(const Set_of_integers& object)// конструктор копирования
{

}

Set_of_integers::~Set_of_integers()// деструктор
{
	delete[] Set_of_integers::set_of_integers;
}

bool Set_of_integers::Belonging_of_an_element_to_a_set(const int integer)
{
	return false;
}

Set_of_integers& Set_of_integers::operator+(const int integer)// добавление элемента во множество
{
	// проверяем множество на наличие добавляемого элемента
	for (int i = 0; i < length_of_set; i++)
	{
		if (set_of_integers[i] != integer)
		{
			continue;
		}
		else
		{
			return *this;// если добавляемый элемент уже есть во множестве
		}
	}

	int* new_set_of_integers = new int[length_of_set + 1];

	for (int i = 0; i < length_of_set; i++)
	{
		new_set_of_integers[i] = set_of_integers[i];
	}

	new_set_of_integers[length_of_set] = integer;
	length_of_set++;
	set_of_integers = nullptr;
	set_of_integers = new_set_of_integers;
	return *this;
}

Set_of_integers& Set_of_integers::operator+=(const Set_of_integers& other)// объединение множеств
{
	int new_length_of_set = length_of_set + other.length_of_set;
	int* new_set_of_integers = new int[new_length_of_set];
	int counter = 0;

	for (int i = 0; i < length_of_set; i++)
	{
		new_set_of_integers[counter] = set_of_integers[i];
		counter++;
	}

	for (int i = 0; i < other.length_of_set; i++)
	{
		new_set_of_integers[counter] = other.set_of_integers[i];
		counter++;
	}

	length_of_set = --counter;
	set_of_integers = nullptr;
	set_of_integers = new_set_of_integers;
	return *this;
}

Set_of_integers& Set_of_integers::operator-(const int integer)// удаление элемента из множества
{
	bool is = false;
	int new_length_of_set = Set_of_integers::length_of_set;
	new_length_of_set--;
	int* new_set_of_integers = nullptr;
	// проверяем множество на наличие удаляемого элемента
	for (int i = 0; i < length_of_set; i++)
	{
		if (set_of_integers[i] == integer)
		{
			is = true;
			break;
		}
	}

	if (is)
	{
		new_set_of_integers = new int[new_length_of_set];
		int to = 0;
		for (int from = 0; from < length_of_set; from++)
		{
			if (set_of_integers[from] != integer)
			{
				new_set_of_integers[to] = set_of_integers[from];
				to++;
			}
			else
			{
				from++;
			}
		}
	}

	Set_of_integers::length_of_set = new_length_of_set;
	set_of_integers = nullptr;
	set_of_integers = new_set_of_integers;
	return *this;
}

//Set_of_integers& Set_of_integers::operator/(const Set_of_integers& other)// разность множеств
//{
//	// TODO: вставьте здесь оператор return
//}

int& Set_of_integers::operator[](const int index)// перегрузка оператора[]
{
	return set_of_integers[index];
}

ostream& operator<< (ostream& out, const Set_of_integers& date)
{
	out << "set " << date << "{ ";

	for (int i = 0; i < date.length_of_set; i++)
	{
		out << to_string(date.set_of_integers[i]) << ", ";
	}

	out << " }" << endl;

	return out;
}
