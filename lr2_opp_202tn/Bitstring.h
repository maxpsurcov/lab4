#pragma once
#include <iostream>

/*
* � ��� ���������, ��� ���������� � ������� ��������, ����'������
������ ���� ��������� ������� ������:
� ����� ����������� Init();
� ����� �������� �� ��������� Read();
� ����� �������� �� ����� Display();
� ������������ � ����� toString().
*/
//17. �������� ���� Bitstring ��� ������ � 64 - ������� �������.������� �����
//������� ���� ������������ ����� ������ ���� unsigned long.������ ����
//��������� �� ��������� �������� ��� ������ � ����� : and, or , xor, not.
//���������� ���� ���� shiftleft() � ���� ������ shiftright() �� ������ �������
//���.

#include <string>

using namespace std;


class Bitstring
{
public:

	Bitstring();		//���������� ���� ������ �� ���������
	Bitstring(unsigned long);    //���������� ��� unsigned long
	~Bitstring();			 //���������� 

	class Error {};             //�������� �� ������
	// Bitstring Init(unsigned long one, unsigned long two);
	int SizeOfBitstring();     //������ �������� ������
	void Read();                //���� � ����������
	void Display();             //����� �� �����
	char  toString();
	string NOT();
	string NOT(unsigned long);      //����������

	

	//�������� ���������

	Bitstring& AND(const Bitstring&);          //�������� �����������

	Bitstring& OR(const Bitstring&);
	
	//�������� �������
	Bitstring& XOR(const Bitstring&);                 //�������� ������� �� ������
	

	string rShift(unsigned long);       //�������� ����� ����� �� n ��������� ������

	string lShift(unsigned long);			  //�������� ����� ����� �� n ��������� �����


	Bitstring operator &=(const Bitstring other)          //�������� �����������
	{
		return AND(other);
	}

	Bitstring& operator |=(const Bitstring& other)              //�������� �������
	{
		return OR(other);
	}

	Bitstring& operator ^=(const Bitstring& other)            //�������� ������� �� ������
	{
		return XOR(other);
	}

	Bitstring operator &(const Bitstring& other)          //�������� �����������
	{
		Bitstring res(*this);
		res.AND(other);
		return res;
	}
	Bitstring operator |(const Bitstring& other) //�������� �������
	{
		Bitstring res(*this);
		res.OR(other);
		return res;
	}
	Bitstring operator ^(const Bitstring& other) //�������� ������� �� ������
	{
		Bitstring res(*this);
		res.XOR(other);
		return res;
	}
private:

	unsigned long *unit;       //��� �������� ���� �����
	unsigned long count;   //��� �������� ������� �����
}
;
