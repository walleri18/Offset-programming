#pragma once
#define _CRT_SECURE_NO_WARNINGS
/*
	Подключаемые библиотеки
*/
#include <Windows.h>// API Windows
#include <iostream>// Библиотека C++ для ввода\вывода
#include <iomanip>// Библиотека C++ для использования манипуляторов
#include <fstream>// Библиотека C++ для использования файловых потоков
#include <cstdio>// Стандартная библиотека C для ввода\вывода и прочих штук

using namespace std;
/**
	Класс NOTE (объявления)
*/
class NOTE
{
/*
	Данные
*/
// Закрытые
private:
	char *surname;// Фамилия
	int phoneNumber;// Номер телефона
	int birthday[3];// Дата рождение в формате: birthday[0] = DD, birthday[1] = MM, birthday[2] = YYYY
/*
	Поведение
*/
// Открытое
public:

	/*
		Конструкторы
	*/

	NOTE();// Конструктор по-умолчанию

	~NOTE();// Деструктор по-умолчанию

	NOTE(const char*, int, int, int, int);// Конструктор со всеми параметрами: фамилия, номер телефона, день рождения, месяц рождения, год рождения

	NOTE(const NOTE&);// Копирующий конструктор

	/*
		Операции
	*/

	NOTE& operator = (const NOTE&);// Операция присваивания

	bool operator < (const NOTE&);// Операция сравнения "меньше"

	bool operator == (int);// Операция сравнения

	friend ifstream& operator >> (ifstream&, NOTE&);// Операция ввода объекта из потока файла

	/*
		Методы
	*/

	void show();// Метод вывода данных на экран

	/*
		Валидаторы
	*/
	static int validatorDays(int);// Валидатор дня
	static int validatorMonth(int);// Валидатор месяца
	static int validatorYear(int);// Валидатор года
};