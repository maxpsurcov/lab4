#include "Bitstring.h"
#include <iostream>
using namespace std;

//Bitstring Bitstring::Init(unsigned long one, unsigned long two)
//{
//	Bitstring tmp;
//	tmp.one = one;
//	tmp.two = two;
//
//	return tmp;
//}


void Bitstring::Display()
{

}

char Bitstring::toString()
{

	return 0;
}


Bitstring::~Bitstring()
{
	unit = 0;
	count = 0;
}

void Bitstring::Read()         //������� ��� ����� � ����������
{
	string str;
	cout << "������� ������� ������ (������: 10011) " << endl;
	cin >> str;

	count = str.size();

	for (unsigned long i = 0; i < count; i++)          // ��������
		if ((str.at(i) != *"0") && (str.at(i) != *"1"))
			throw Error();                         //��������� ����������

	unit = new unsigned long;

	for (unsigned long i = 0; i < count; i++)        // ����������� � ������ ���� ������
		unit[i] = str.at(i);
}

void Bitstring::Display()            //������� ��� ������ �� �����
{
	for (unsigned long i = 0; i < count; i++)
		cout << unit[i];
}

int Bitstring::SizeOfBitstring()
{
	return count;
}

string Bitstring::NOT()      //�������� ���������
{
    string str;

    for (unsigned int i = 0; i < count; i++)
    {
        if (unit[i] == *"0")
            unit[i] = *"1";
        else
            if (unit[i] == *"1")
                unit[i] = *"0";

        str += unit[i];
    }
    return str;
}


string Bitstring::NOT(unsigned long)      //���������� �������� ���������
{
    string str;

    for (unsigned int i = 0; i < count; i++)
    {
        if (unit[i] == *"0")
            unit[i] = *"1";
        else
            if (unit[i] == *"1")
                unit[i] = *"0";

        str += unit[i];
    }
    return str;
}

string Bitstring::AND(Bitstring& bit)    //�������� �����������
{
    string str;

    for (unsigned int i = 0; i < count; i++)
    {
        if ((unit[i] == *"0") && (bit.unit[i] == *"1"))
            str += *"0";
        else
            if ((unit[i] == *"1") && (bit.unit[i] == *"0"))
                str += *"0";
            else
                str += unit[i];
    }
    return str;
}


string Bitstring::OR(Bitstring& bit)   //�������� �������
{
    string str;

    for (unsigned int i = 0; i < count; i++)
    {
        if ((unit[i] == *"0") && (bit.unit[i] == *"1"))
            str += *"1";
        else
            if ((unit[i] == *"1") && (bit.unit[i] == *"0"))
                str += *"1";
            else
                str += unit[i];
    }
    return str;
}

string Bitstring::XOR(Bitstring& bit)    //�������� ������� �� ������
{
    string str;

    for (unsigned int i = 0; i < count; i++)
    {
        if ((unit[i] == *"0") && (bit.unit[i] == *"1"))
            str += *"1";
        else
            if ((unit[i] == *"1") && (bit.unit[i] == *"0"))
                str += *"1";
            else
                if ((unit[i] == *"0") && (bit.unit[i] == *"0"))
                    str += *"0";
                else
                    if ((unit[i] == *"1") && (bit.unit[i] == *"1"))
                        str += *"0";
    }
    return str;
}


string Bitstring::rShift(unsigned long n)      //�������� ����� ����� �� n ��������� ������
{
	string str;

	for (unsigned long i = 0; i < count; i++)
		str += unit[i];

	str.erase(0, n);							 // ������� n �������� ������� � �������

	for (int i = 0; i < n; i++)                    // ��������� n ����� � �����
		str.append("0");

	return str;
}

string Bitstring::lShift(unsigned long n)  //�������� ����� ����� �� n ��������� �����
{
	string str;

	for (unsigned long i = 0; i < count; i++)
		str += unit[i];

	str.erase(count - n, n);  // ������� n �������� ������� � �������                   

	str.insert(0, n, *"0");           // ��������� n ����� �  ������

	return str;
}