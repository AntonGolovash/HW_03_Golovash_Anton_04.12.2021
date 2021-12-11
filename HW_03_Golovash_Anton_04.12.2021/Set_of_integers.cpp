#include "Set_of_integers.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;


Set_of_integers::Set_of_integers()// конструктор по умолчанию
{
	Set_of_integers::length_of_set = 10;
	Set_of_integers::set_of_integers = new int[length_of_set];
	for (int i = 0; i < length_of_set; i++)
	{
		Set_of_integers::set_of_integers[i] = 0;
	}
}

Set_of_integers::Set_of_integers(int* incoming_set_of_integers, int length)// конструктор с параметрами
{
	Set_of_integers::length_of_set = length;
	Set_of_integers::set_of_integers = incoming_set_of_integers;
	incoming_set_of_integers = nullptr;
}

Set_of_integers::Set_of_integers(const Set_of_integers& object)// конструктор копировани€
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
	// провер€ем множество на наличие добавл€емого элемента
	for (int i = 0; i < length_of_set; i++)
	{
		if (set_of_integers[i] != integer)
		{
			continue;
		}
		else
		{
			return *this;// если добавл€емый элемент уже есть во множестве
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

	length_of_set = counter;
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
	// провер€ем множество на наличие удал€емого элемента
	for (int i = 0; i < length_of_set; i++)
	{
		if (set_of_integers[i] == integer)
		{
			is = true;
			break;
		}
	}

	if (is)// если удал€емый элемент найден
	{
		new_set_of_integers = new int[new_length_of_set];
		new_length_of_set = 0;
		int to = 0;
		for (int from = 0; from < length_of_set; from++)
		{
			if (set_of_integers[from] != integer)
			{
				new_set_of_integers[to] = set_of_integers[from];
				new_length_of_set++;
				to++;
			}
		}
		Set_of_integers::length_of_set = new_length_of_set;
		set_of_integers = nullptr;
		set_of_integers = new_set_of_integers;
	}
	return *this;
}

Set_of_integers& Set_of_integers::operator/(const Set_of_integers& other)// разность множеств
{
	int new_length_of_set = Set_of_integers::length_of_set;// длина временного массива
	int* new_set_of_integers = new int[new_length_of_set];// выделение пам€ти дл€ временного массива
	int new_set_of_integers_counter = 0;// счЄтчик количества записанных элементов во временный массив
	bool element_is_not_present = false;
	for (int i = 0; i < length_of_set; i++)
	{
		if (element_is_not_present)
		{
			new_set_of_integers[new_set_of_integers_counter] = set_of_integers[i];
			new_set_of_integers_counter++;
		}
		for (int j = 0; j < other.length_of_set; j++)
		{
			if (set_of_integers[i] == other.set_of_integers[j])
			{
				element_is_not_present = false;
				break;
			}
			if (set_of_integers[i] != other.set_of_integers[j])
			{
				element_is_not_present = true;
			}
		}
	}

	int* new_set_of_integers_2 = new int[new_set_of_integers_counter];

	for (int i = 0; i < new_set_of_integers_counter; i++)
	{
		new_set_of_integers_2[i] = new_set_of_integers[i];
	}

	Set_of_integers::length_of_set = new_set_of_integers_counter;
	set_of_integers = nullptr;
	set_of_integers = new_set_of_integers_2;
	return *this;
}

int& Set_of_integers::operator[](const int index)// перегрузка оператора[]
{
	return set_of_integers[index];
}

ostream& operator<< (ostream& out, const Set_of_integers& date)
{
	out << "set " << date.set_of_integers << "{ ";

	for (int i = 0; i < date.length_of_set; i++)
	{
		out << to_string(date.set_of_integers[i]) << ", ";
	}

	out << "}" << endl;

	return out;
}
