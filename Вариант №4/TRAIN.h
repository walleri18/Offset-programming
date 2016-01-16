#pragma once
#define _CRT_SECURE_NO_WARNINGS
/*
	Plugins for the operation
*/
#include <iostream>// A C++ library for input / output
#include <iomanip>// Library With++ for use of manipulators with parameters
#include <fstream>// A C++ library for working with file streams
#include <cstdio>// Standard C library for input / output and other

using namespace std;// Plug the std namespace

/**
	Класс TRAIN (definitions)
*/
class TRAIN
{
/*
	Данные
*/
// Закрытые
private:
	char *nameDestination;// Название пункта назначения
	int trainNumber;// Номер поезда
	double departureTime;// Время отправления, формат: чч.мм
/*
	Функции
*/
// Открытые
public:

	/*
		Конструкторы
	*/

	TRAIN();// The default constructor

	~TRAIN();// The default destructor

	TRAIN(const char*, int, double);// Constructor with all parameters

	TRAIN(const TRAIN&);// The copy constructor

	/*
		Операции
	*/

	TRAIN& operator = (const TRAIN&);// The assignment operation

	bool operator < (const TRAIN&);// Операция сравнения "меньше"

	bool operator > (double);// Операция сравнения "больше"

	/*
		Методы
	*/

	void show();// Метод вывода на экран
};