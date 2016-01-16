#include "AEROFLOT.h"

/**
	Класс AEROFLOT (реализация)
*/

/*
	Конструкторы
*/

// Конструктор по-умолчанию;
AEROFLOT::AEROFLOT() : destinationFlight(NULL), typeAircraft(NULL), flightNumber(1)
{
}

// Деструктор по-умолчанию;
AEROFLOT::~AEROFLOT()
{
	if (this->destinationFlight)
		delete[] this->destinationFlight;// Освобождаю память
	if (this->typeAircraft)
		delete[] this->typeAircraft;// Аналогично
}

// Конструктор для заполнения всех полей класса
AEROFLOT::AEROFLOT(const char *destinationFlight, int flightNumber, const char *typeAircraft)
{
	/*
		Пункт назначения
	*/
	this->destinationFlight = new char[strlen(destinationFlight) + 1];// Выделяем динамически память столько сколько нужно

	strcpy(this->destinationFlight, destinationFlight);// Копируем значение в нужную область памяти

	/*
		Тип самолёта
	*/
	this->typeAircraft = new char[strlen(typeAircraft) + 1];// Аналогично

	strcpy(this->typeAircraft, typeAircraft);// Аналогично

	/*
		Номер рейса
	*/
	this->flightNumber = flightNumber;// Без комментариев)
}

// Конструктор копирования;
AEROFLOT::AEROFLOT(AEROFLOT &aeroflot)
{
	/*
		Пункт назначения
	*/
	this->destinationFlight = new char[strlen(aeroflot.destinationFlight) + 1];// Выделяем динамически память столько сколько нужно

	strcpy(this->destinationFlight, aeroflot.destinationFlight);// Копируем значение в нужную область памяти

	/*
		Тип самолёта
	*/
	this->typeAircraft = new char[strlen(aeroflot.typeAircraft) + 1];// Аналогично

	strcpy(this->typeAircraft, aeroflot.typeAircraft);// Аналогично

	/*
		Номер рейса
	*/
	this->flightNumber = aeroflot.flightNumber;// Без комментариев)
}

/*
	Операции;
*/

// Операция присваивания
AEROFLOT & AEROFLOT::operator = (AEROFLOT &aeroflot)
{
	// Защита от самоприсваивания
	if (this == &aeroflot)
		return *this;

	/*
	Пункт назначения
	*/
	delete this->destinationFlight;// Освобождаем ненужную память

	this->destinationFlight = new char[strlen(aeroflot.destinationFlight) + 1];// Выделяем динамически память столько сколько нужно

	strcpy(this->destinationFlight, aeroflot.destinationFlight);// Копируем значение в нужную область памяти

	/*
		Тип самолёта
	*/
	delete this->typeAircraft;// Аналогично

	this->typeAircraft = new char[strlen(aeroflot.typeAircraft) + 1];// Аналогично

	strcpy(this->typeAircraft, aeroflot.typeAircraft);// Аналогично

	/*
		Номер рейса
	*/
	this->flightNumber = aeroflot.flightNumber;// Без комментариев)


	return *this;// Возвращаем ссылку на объект для дальнейших манипуляций
}

// Операция сравнения "меньше" (название пункта назначения по алфавиту, в условии написано) 
bool AEROFLOT::operator < (AEROFLOT &aeroflot)
{
	return (strcmp(this->destinationFlight, aeroflot.destinationFlight) < 0);
}

// Операция сравнения. Сравниваем тип самолёта с переданным типом
bool AEROFLOT::operator == (const char *typeAircraft)
{
	return (strcmp(this->typeAircraft, typeAircraft) == 0);
}

/*
	Методы;
*/

// Метод вывода на экран значений полей класса;
void AEROFLOT::show()
{
	cout << left << setw(30) << setfill('.') << "Название пункта назначения"
		<< right << setw(30) << this->destinationFlight << endl
		<< left << setw(30) << setfill('.') << "Номер рейса"
		<< right << setw(30) << this->flightNumber << endl
		<< left << setw(30) << setfill('.') << "Тип самолёта"
		<< right << setw(30) << this->typeAircraft << endl << endl << endl;
}