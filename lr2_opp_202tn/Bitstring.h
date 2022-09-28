#pragma once
#include <iostream>

/*
* У всіх завданнях, крім зазначених у завданні операцій, обов'язково
повинні бути реалізовані наступні методи:
• метод ініціалізації Init();
• метод введення із клавіатури Read();
• метод вивідення на екран Display();
• перетворення в рядок toString().
*/
//17. Створити клас Bitstring для роботи з 64 - бітовими рядками.Бітовий рядок
//повинна бути представлено двома полями типу unsigned long.Повинні бути
//реалізовані всі традиційні операції для роботи з бітами : and, or , xor, not.
//Реалізувати зсув вліво shiftleft() і зсув вправо shiftright() на задану кількість
//бітів.

#include <string>

using namespace std;


class Bitstring
{
public:

	Bitstring();		//Перегрузка если ничего не вводиться
	Bitstring(unsigned long);    //Перегрузка для unsigned long
	~Bitstring();			 //Деструктор 

	class Error {};             //проверка на ошибки
	// Bitstring Init(unsigned long one, unsigned long two);
	int SizeOfBitstring();     //размер введённой строки
	void Read();                //ввод с клавиатуры
	void Display();             //вывод на экран
	char  toString();
	string NOT();
	string NOT(unsigned long);      //перегрузка

	

	//операция отрицание

	Bitstring& AND(const Bitstring&);          //операция перемножить

	Bitstring& OR(const Bitstring&);
	
	//операция сложить
	Bitstring& XOR(const Bitstring&);                 //операция сложить по модулю
	

	string rShift(unsigned long);       //операция сдвиг битов на n елементов вправо

	string lShift(unsigned long);			  //операция сдвиг битов на n елементов влево


	Bitstring operator &=(const Bitstring other)          //операция перемножить
	{
		return AND(other);
	}

	Bitstring& operator |=(const Bitstring& other)              //операция сложить
	{
		return OR(other);
	}

	Bitstring& operator ^=(const Bitstring& other)            //операция сложить по модулю
	{
		return XOR(other);
	}

	Bitstring operator &(const Bitstring& other)          //операция перемножить
	{
		Bitstring res(*this);
		res.AND(other);
		return res;
	}
	Bitstring operator |(const Bitstring& other) //операция сложить
	{
		Bitstring res(*this);
		res.OR(other);
		return res;
	}
	Bitstring operator ^(const Bitstring& other) //операция сложить по модулю
	{
		Bitstring res(*this);
		res.XOR(other);
		return res;
	}
private:

	unsigned long *unit;       //для хранения двух строк
	unsigned long count;   //для хранения размера строк
}
;
