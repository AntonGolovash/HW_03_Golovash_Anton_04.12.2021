#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ostream>
using namespace std;

class Set_of_integers
{
public:
	Set_of_integers();// конструктор по умолчанию
	Set_of_integers(int* set_of_integers, int length);// конструктор с параметрами
	Set_of_integers(const Set_of_integers& object);// конструктор копирования
	~Set_of_integers();// деструктор
	bool Belonging_of_an_element_to_a_set(const int integer);
	//friend ostream& operator << (ostream& out, const Set_of_integers& date);
	Set_of_integers& operator+ (const int integer);// добавление элемента во множество
	//Set_of_integers& operator+ (const Set_of_integers& other);// объединение множеств
	Set_of_integers& operator- (const int integer);// удаление элемента из множества
	//Set_of_integers& operator- (const Set_of_integers& other_object);// разность множеств
	//Set_of_integers& operator* ();// пересечение множеств
	//Set_of_integers& operator= (const Set_of_integers& object);// присваивание множества
	//Set_of_integers& operator== (const Set_of_integers& other_object);// сравнение множеств
	int& operator[] (const int index);// перегрузка оператора[]

private:
	int length_of_set;
	int* set_of_integers;
};


