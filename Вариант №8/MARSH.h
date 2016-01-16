#pragma once
#define _CRT_SECURE_NO_WARNINGS
/*
	Plugins for the operation
*/
#include <Windows.h>
#include <locale>
#include <iostream>// A C++ library for input / output
#include <iomanip>// Library With++ for use of manipulators with parameters
#include <fstream>// A C++ library for working with file streams
#include <cstdio>// Standard C library for input / output and other

using namespace std;// Plug the std namespace

/**
	Класс MARSH (definitions)
*/
class MARSH
{
/*
	Данные
*/
// Закрытые
private:
	char *beginPoint;// Начальный пункт
	char *finalPoint;// Конечный пункт
	int numberRout;// Номер марширута
/*
	Функции
*/
// Открытые
public:

	/*
		Конструкторы
	*/

	MARSH();// The default constructor

	~MARSH();// The default destructor

	MARSH(const char*, const char*, int);// Constructor with all parameters

	MARSH(const MARSH&);// The copy constructor

	/*
		Операции
	*/

	MARSH& operator = (const MARSH&);// The assignment operation

	bool operator < (const MARSH&);// Comparison operation "less than"

	bool operator == (const char*);// Операция сравнения

	/*
		Methods
	*/

	void show();// Метод вывода на экран
};