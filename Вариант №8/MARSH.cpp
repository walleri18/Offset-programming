#include "MARSH.h"
/**
	Класс NOTE (реализация)
*/

/*
	Конструкторы
*/

// Конструктор по умолчанию
MARSH::MARSH() : numberRout(0), beginPoint(NULL), finalPoint(NULL)
{
}

// Деструктор по умолчанию
MARSH::~MARSH()
{
	if (this->beginPoint)
		delete[] this->beginPoint;// Освобождение памяти
	if (this->finalPoint)
		delete[] this->finalPoint;// Освобождение памяти
}

// Конструктор со всеми параметрами
MARSH::MARSH(const char *beginPoint, const char *finalPoint, int numberRout) : numberRout(numberRout)
{
	/*
		Начальный пункт
	*/
	this->beginPoint = new char[strlen(beginPoint) + 1];// Выделяем динамически память под нужное количество

	strcpy(this->beginPoint, beginPoint);// Копируем из полученных данных в данные объекта

	/*
		Конечный пункт
	*/
	this->finalPoint = new char[strlen(finalPoint) + 1];// Выделяем динамически память под нужное количество

	strcpy(this->finalPoint, finalPoint);// Копируем из полученных данных в данные объекта
}

// Конструктор копирования
MARSH::MARSH(const MARSH & marsh)
{
	/*
		Начальный пункт
	*/
	this->beginPoint = new char[strlen(marsh.beginPoint) + 1];// Выделяем динамически память под нужное количество

	strcpy(this->beginPoint, marsh.beginPoint);// Копируем из полученных данных в данные объекта

	/*
		Конечный пункт
	*/
	this->finalPoint = new char[strlen(marsh.finalPoint) + 1];// Выделяем динамически память под нужное количество

	strcpy(this->finalPoint, marsh.finalPoint);// Копируем из полученных данных в данные объекта

	/*
		Номер марширута
	*/
	this->numberRout = marsh.numberRout;
}

/*
	Операции
*/

// Операция присваивания
MARSH& MARSH::operator = (const MARSH & marsh)
{
	// Защита от самоприсваивания
	if (this == &marsh)
		return *this;

	/*
		Начальный пункт
	*/
	delete this->beginPoint;// Освобождаем ненужную память

	this->beginPoint = new char[strlen(marsh.beginPoint) + 1];// Выделяем динамически память под нужное количество

	strcpy(this->beginPoint, marsh.beginPoint);// Копируем из полученных данных в данные объекта

	/*
		Конечный пункт
	*/
	delete this->finalPoint;// Освобождаем ненужную память

	this->finalPoint = new char[strlen(marsh.finalPoint) + 1];// Выделяем динамически память под нужное количество

	strcpy(this->finalPoint, marsh.finalPoint);// Копируем из полученных данных в данные объекта

	/*
		Номер марширута
	*/
	this->numberRout = marsh.numberRout;

	return *this;
}

// Операция сравнения "меньше"
bool MARSH::operator < (const MARSH &marsh)
{
	return (this->numberRout < marsh.numberRout);
}

// Операция сравнения
bool MARSH::operator == (const char *point)
{
	return (strcmp(this->beginPoint, point) || strstr(this->finalPoint, point) == 0);
}

/*
	Методы
*/

// Метод вывода значений объекта на экран
void MARSH::show()
{
	cout << left << setw(30) << setfill('.') << "Начальный пункт"
		<< right << setw(30) << this->beginPoint << endl
		<< left << setw(30) << setfill('.') << "Конечный пункт"
		<< right << setw(30) << this->finalPoint << endl
		<< left << setw(30) << setfill('.') << "Номер марширута"
		<< right << setw(30) << this->numberRout << endl << endl << endl;
}