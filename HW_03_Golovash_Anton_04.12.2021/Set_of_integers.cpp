#include "Set_of_integers.h"

Set_of_integers::Set_of_integers()
{

}

Set_of_integers::Set_of_integers(int* set_of_integers[])// ����������� � �����������
{
}

Set_of_integers::Set_of_integers(const Set_of_integers& object)// ����������� �����������
{

}

Set_of_integers::~Set_of_integers()// ����������
{
	*this = nullptr;
	delete[] this;
}

bool Set_of_integers::Belonging_of_an_element_to_a_set(int element)
{

	return false;
}
