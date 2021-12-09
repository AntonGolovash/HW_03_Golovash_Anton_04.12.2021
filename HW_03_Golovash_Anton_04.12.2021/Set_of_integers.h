#pragma once
#include <iostream>
#include <sstream>
#include <string>
#include <ostream>
using namespace std;

class Set_of_integers
{
public:
	Set_of_integers() = default;// ����������� �� ���������
	Set_of_integers(int* set_of_integers[]);// ����������� � �����������
	Set_of_integers(const Set_of_integers& object);// ����������� �����������
	~Set_of_integers();// ����������
	bool Belonging_of_an_element_to_a_set(int element);
	friend ostream& operator << (ostream& out, const Set_of_integers& date);
	Set_of_integers& operator+ (const int integer);// ���������� �������� �� ���������
	Set_of_integers& operator+ (const Set_of_integers& other_object);// ����������� ���� ��������
	Set_of_integers& operator- (const int index);// �������� �������� �� ���������
	Set_of_integers& operator- (const Set_of_integers& other_object);// �������� ��������
	Set_of_integers& operator* ();// ����������� ��������
	Set_of_integers& operator= (const Set_of_integers& object);// ������������ ���������
	Set_of_integers& operator== (const Set_of_integers& other_object);// ��������� ��������
private:
	int length_of_set;
	int* set_of_integers;
};

