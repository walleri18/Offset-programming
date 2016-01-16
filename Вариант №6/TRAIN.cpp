#include "TRAIN.h"

/**
	Класс TRAIN (реализация)
*/

/*
	Конструкторы
*/

// The default constructor
TRAIN::TRAIN() : trainNumber(0), departureTime(0.0), nameDestination(NULL)
{
}

// The default destructor
TRAIN::~TRAIN()
{
	if (this->nameDestination)
		delete[] this->nameDestination;// Освобождение не нужной памяти
}

// Constructor with all parameters
TRAIN::TRAIN(const char *nameDestination, int trainNumber, double departureTime) : trainNumber(trainNumber), departureTime(departureTime)
{
	/*
		Название пункта назначения
	*/
	this->nameDestination = new char[strlen(nameDestination) + 1];// Выделение необходимого количеств памяти

	strcpy(this->nameDestination, nameDestination);// Копирование необходимого в память
}

// The copy constructor
TRAIN::TRAIN(const TRAIN &train)
{
	/*
		Название пункта назначения
	*/
	this->nameDestination = new char[strlen(train.nameDestination) + 1];// Выделение необходимой памяти

	strcpy(this->nameDestination, train.nameDestination);// Копирование

	/*
		Номер поезда
	*/
	this->trainNumber = train.trainNumber;// Получение и присвоение номера поезда

	/*
		Время отправления
	*/
	this->departureTime = train.departureTime;// Получение и присвоение времени отправления поезда
}

/*
	Операции
*/

// The assignment operation
TRAIN & TRAIN::operator = (const TRAIN &train)
{
	// Защита от самоприсваивания
	if (this == &train)
		return *this;

	/*
		Название пункта назначения
	*/
	delete this->nameDestination;// Освобождение ненужной памяти

	this->nameDestination = new char[strlen(train.nameDestination) + 1];// Выделение необходимой памяти

	strcpy(this->nameDestination, train.nameDestination);// Копирование

	/*
		Номер поезда
	*/
	this->trainNumber = train.trainNumber;// Получение и присвоение номера поезда

	/*
		Время отправления
	*/
	this->departureTime = train.departureTime;// Получение и присвоение времени отправления поезда

	return *this;
}

// Comparison operation "less than", returns true if the first operand is greater than second
bool TRAIN::operator < (const TRAIN &train)
{
	return (this->trainNumber < train.trainNumber);
}

// Операция сравнения
bool TRAIN::operator == (int trainNumber)
{
	return (this->trainNumber == trainNumber);
}

/*
	Методы
*/

// Метод вывода на экран
void TRAIN::show()
{
	cout << left << setw(30) << setfill('.') << "Название пункта назначения"
		<< right << setw(30) << this->nameDestination << endl
		<< left << setw(30) << setfill('.') << "Номер поезда"
		<< right << setw(30) << this->trainNumber << endl
		<< left << setw(30) << setfill('.') << "Время отправления"
		<< right << setw(30) << this->departureTime << endl << endl << endl;
}