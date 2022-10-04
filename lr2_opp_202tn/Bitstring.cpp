#include "Bitstring.h"
#include <iostream>
using namespace std;
char Bitstring::toString()
{
    return 0;
}
Bitstring::Bitstring()
{
    unit = 0;
    count = 0;
}
Bitstring::Bitstring(unsigned long *one, unsigned long two)
{
    unit = one;
    count = two;
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
    return this->count;
}
string Bitstring::rShift(unsigned long n)      //�������� ����� ����� �� n ��������� ������ 
{ 
 string str; 
 
 for (unsigned long i = 0; i < count; i++) 
  str += unit[i]; 
 
 str.erase(0, n);        // ������� n �������� ������� � ������� 
 
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