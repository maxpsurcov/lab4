#include <iostream>
#include"Bitstring.h"

int main()
{
	setlocale(LC_ALL, "ru");    //������� ����

	Bitstring First_bit, Second_bit;

	try
	{

		First_bit.Read();     //�������� ��� ������ ������ ������
		Second_bit.Read();   //������ ������ ������
		if (First_bit.SizeOfBitstring() != Second_bit.SizeOfBitstring()) //�������� �� ������������ ������� �����
			throw Bitstring::Error();

		int change = 0;
		while (change != 8)
		{
			cout << "������� (1) ���� ������ ������� ������� ������" << endl
				<< "������� (2) ���� ������ ����������� ������� ������" << endl
				<< "������� (3) ���� ������ ������� �� ������ ������� ������ " << endl
				<< "������� (4) ���� ������ ��������� ��������� ���������  �����" << endl
				<< "������� (5) ���� ������ ��������� ��������� ����� ������ �����" << endl
				<< "������� (6) ���� ������ ��������� ��������� ����� �����  ����� " << endl
				<< "������� (7) ���� ������ �������� �����" << endl
				<< "������� (8) ���� ������ �����" << endl;
			cin >> change;

			switch (change)
			{
			case 1: { cout << endl << "����� ����� :";
				First_bit.OR(Second_bit);
				cout << endl << endl; break; }
			case 2: { cout << endl << "������������ ����� :";
				First_bit.AND(Second_bit);
				cout << endl << endl; break; }
			case 3: { cout << endl << "����� �� ������ ����� : ";
				First_bit.XOR(Second_bit);
				cout << endl << endl; break; }
			case 4: { cout << endl << "��������� ��������� ������ ������ ����� " << First_bit.NOT() << endl
				<< "��������� ��������� ������ ������ ����� " << Second_bit.NOT() << endl << endl; break; }
			case 5: {
				cout << " �� ������� �� ������ �������� ������?" << endl;
				unsigned long n;
				cin >> n;
				if (n < 0)         //�������� �����
					throw Bitstring::Error();
				cout << "���������� ���������� ������:" << endl
					<< "   ������ ������ - " << First_bit.rShift(n) << endl
					<< "   ������ ������ - " << Second_bit.rShift(n) << endl << endl;
				break;
			}
			case 6: {
				cout << " �� ������� �� ������ �������� ������?" << endl;
				unsigned long n;
				cin >> n;
				if (n < 0)
					throw Bitstring::Error();
				cout << "���������� ���������� ������:" << endl
					<< "   ������ ������ - " << First_bit.lShift(n) << endl
					<< "   ������ ������ - " << Second_bit.lShift(n) << endl << endl;
				break;
			}
			case 7:  system("cls"); break;
			}
		}


	}
	catch (Bitstring::Error)
	{
		cout << "������! ��������� �������� �����������!" << endl;
	}
	return 0;

}