#include "Set_of_integers.h"
#include <stdio.h>
#include <stdlib.h>
using namespace std;


Set_of_integers::Set_of_integers()// ����������� �� ���������
{
	length_of_set = 10;
	Set_of_integers::set_of_integers = new int[length_of_set];
	for (int i = 0; i < length_of_set; i++)
	{
		set_of_integers[i] = 0;
	}
}

Set_of_integers::Set_of_integers(int* incoming_set_of_integers)// ����������� � �����������
{
	length_of_set = sizeof(*incoming_set_of_integers) / sizeof(int);
	set_of_integers = incoming_set_of_integers;
	incoming_set_of_integers = nullptr;
}

Set_of_integers::Set_of_integers(const Set_of_integers& object)// ����������� �����������
{

}

Set_of_integers::~Set_of_integers()// ����������
{
	*this = nullptr;
	delete[] this;
}

bool Set_of_integers::Belonging_of_an_element_to_a_set(const int integer)
{
	return false;
}

Set_of_integers& Set_of_integers::operator+(const int integer)// ���������� �������� �� ���������
{
	// ��������� ��������� �� ������� ������������ ��������
	for (int i = 0; i < length_of_set; i++)
	{
		if (set_of_integers[i] != integer)
		{
			continue;
		}
		else
		{
			return *this;// ���� ����������� ������� ��� ���� �� ���������
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

Set_of_integers& Set_of_integers::operator+(const Set_of_integers& other)// ����������� ��������
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
		new_set_of_integers[counter] = other[i];// ����� �� ��������
		counter++;
	}
	length_of_set = --counter;
	set_of_integers = nullptr;
	set_of_integers = new_set_of_integers;
	return *this;

}

Set_of_integers& Set_of_integers::operator-(const int integer)// �������� �������� �� ���������
{
	bool is = false;
	// ��������� ��������� �� ������� ���������� ��������
	for (int i = 0; i < length_of_set; i++)
	{
		if (set_of_integers[i] == integer)
		{
			is = true;
		}
	}

	if (is)
	{
		int new_length_of_set = --length_of_set;
		int* new_set_of_integers = new int[new_length_of_set];
		for (int i = 0; i < new_length_of_set; i++)
		{
			if (set_of_integers[i] != integer)
			{
				new_set_of_integers[i] = set_of_integers[i];
			}
		}
	}
}

int& Set_of_integers::operator[](const int index)// ���������� ���������[]
{
	return set_of_integers[index];
}