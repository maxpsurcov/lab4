#pragma once
#include <iostream>
/*
* � ��� ���������, ��� ���������� � �������� ��������, ����'������
������� ���� ���������� �������� ������:
� ����� ������������ Init();
� ����� �������� �� ��������� Read();
� ����� �������� �� ����� Display();
� ������������ � ����� toString().
*/
//17. �������� ���� Bitstring ��� ������ � 64 - ������� �������.������� �����
//������� ���� ������������ ����� ������ ���� unsigned long.������� ����
//���������� �� ���������� �������� ��� ������ � ����� : and, or , xor, not.
//���������� ���� ���� shiftleft() � ���� ������ shiftright() �� ������ �������
//���.
#include <string>
using namespace std;
class Bitstring
{
public:
    Bitstring();      //���������� ���� ������ �� ���������
    class Error {};             //�������� �� ������
    int SizeOfBitstring();     //������ �������� ������
    void Read();                //���� � ����������
    void Display();             //����� �� �����
    char  toString();
    Bitstring(unsigned long *one, unsigned long two);
	string rShift(unsigned long n); 
	string lShift(unsigned long n);
private:
    unsigned long *unit;       //��� �������� ���� �����
    unsigned long count;   //��� �������� ������� �����
}
;