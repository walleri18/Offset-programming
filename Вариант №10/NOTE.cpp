#include "NOTE.h"
/**
	Класс NOTE (реализация)
*/

/*
	Конструкторы
*/

// Конструктор по-умолчанию
NOTE::NOTE() : phoneNumber(0), surname(NULL)
{
	/*
		Дата рождения
	*/
	birthday[0] = 0;// День DD
	birthday[1] = 0;// Месяц MM
	birthday[2] = 0;// Год YYYY
}

// Деструктор по-умолчанию
NOTE::~NOTE()
{
	if (this->surname)
		delete[] this->surname;// Освобождение памяти из под фамилии
}

// Конструктор со всеми параметрами
NOTE::NOTE(const char *surname, int phoneNumber, int birthdayDD, int birthdayMM, int birthdayYYYY) : phoneNumber(phoneNumber)
{
	/*
		Фамилия
	*/
	this->surname = new char[strlen(surname) + 1];// Выделение памяти с учётом нулевого символа

	strcpy(this->surname, surname);// Вставка в память

	/*
		Дата рождения
	*/
	birthday[0] = birthdayDD;// День DD
	birthday[1] = birthdayMM;// Месяц MM
	birthday[2] = birthdayYYYY;// Год YYYY
}

// Конструктор копирования
NOTE::NOTE(const NOTE &note)
{
	/*
		Фамилия
	*/
	this->surname = new char[strlen(note.surname) + 1];// Выделение памяти с учётом нулевого символа

	strcpy(this->surname, note.surname);// Вставка в память

	/*
		Номер телефона
	*/
	this->phoneNumber = note.phoneNumber;// Получение и копирование номера телефона

	/*
		Дата рождения
	*/
	this->birthday[0] = note.birthday[0];// День DD
	this->birthday[1] = note.birthday[1];// Месяц MM
	this->birthday[2] = note.birthday[2];// Год YYYY
}

/*
	Операции
*/

// Операция присваивания
NOTE& NOTE::operator = (const NOTE &note)
{
	// Защита от самоприсваивания
	if (this == &note)
		return *this;
	/*
		Фамилия
	*/
	delete this->surname;// Освобождения ненужной памяти

	this->surname = new char[strlen(note.surname) + 1];// Выделение необходимой памяти с учётом нулевого символа

	strcpy(this->surname, note.surname);// Копирование

	/*
		Номер телефона
	*/
	this->phoneNumber = note.phoneNumber;

	/*
		Дата рождения
	*/
	this->birthday[0] = note.birthday[0];// День DD
	this->birthday[1] = note.birthday[1];// Месяц MM
	this->birthday[2] = note.birthday[2];// Год YYYY

	return *this;
}

// Операция сравнения "меньше"
bool NOTE::operator < (const NOTE &note)
{
	return (strcmp(this->surname, note.surname) < 0);
}

// Операция сравнения, сравнивается месяц объекта с переданным значением
bool NOTE::operator == (int birthdayMM)
{
	return (this->birthday[1] == birthdayMM);
}

/*
	Методы
*/

// Метод вывода на экран
void NOTE::show()
{
	cout << left << setw(30) << setfill('.') << "Фамилия"
		<< right << setw(30) << this->surname << endl
		<< left << setw(30) << setfill('.') << "Номер телефона"
		<< right << setw(30) << this->phoneNumber << endl
		<< left << setw(30) << setfill('.') << "Дата рождения"
		<< right << setw(30) << this->birthday[0] << "." << this->birthday[1] << "." << this->birthday[2] << endl;
}