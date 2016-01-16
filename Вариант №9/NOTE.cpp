#include "NOTE.h"
/**
	Класс NOTE (реализация)
*/

/*
	Конструкторы
*/

// Конструктор по умолчанию
NOTE::NOTE() : phoneNumber(0), surname(NULL)
{
	/*
		День рождения
	*/
	// Делаем валидные объекты
	this->birthday[0] = 1;// День DD
	this->birthday[1] = 1;// Месяц MM
	this->birthday[2] = 1;// Год YYYY
}

// Деструктор по умолчанию
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
	this->surname = new char[strlen(surname) + 1];// Выделяем динамически память под нужное количество

	strcpy(this->surname, surname);// Копируем из полученных данных в данные объекта

	/*
		День рождения
	*/

	// Валидация
	birthdayDD = validatorDays(birthdayDD);
	birthdayMM = validatorMonth(birthdayMM);
	birthdayYYYY = validatorYear(birthdayYYYY);

	// Запись валидных значений
	birthday[0] = birthdayDD;// День DD
	birthday[1] = birthdayMM;// Месяц MM
	birthday[2] = birthdayYYYY;// Год YYYY
}

// Конструктор копирования
NOTE::NOTE(const NOTE & note)
{
	/*
		Фамилия
	*/
	this->surname = new char[strlen(note.surname) + 1];// Выделяем динамически память под нужное количество

	strcpy(this->surname, note.surname);// Копируем из полученных данных в данные объекта

	/*
		Номер телефона
	*/
	this->phoneNumber = note.phoneNumber;// Получение значение номера телефона из копируемого объекта и запись этого значения в этот объект

	/*
		День рождения
	*/
	this->birthday[0] = note.birthday[0];// День DD
	this->birthday[1] = note.birthday[1];// Месяц MM
	this->birthday[2] = note.birthday[2];// Год YYYY
}

/*
	Операции
*/

// Операция присваивания
NOTE& NOTE::operator = (const NOTE & note)
{
	// Защита от самоприсваивания
	if (this == &note)
		return *this;

	/*
		Фамилия
	*/
	delete this->surname;// Освобождение от ненужной памяти

	this->surname = new char[strlen(note.surname) + 1];// Выделяем память под фамилию

	strcpy(this->surname, note.surname);// Копируем

	/*
		Номер телефона
	*/
	this->phoneNumber = note.phoneNumber;

	/*
		День рождения
	*/
	this->birthday[0] = note.birthday[0];// День DD
	this->birthday[1] = note.birthday[1];// Месяц MM
	this->birthday[2] = note.birthday[2];// Год YYYY

	return *this;
}

// Операция сравнения "меньше", возвращает истину, если первый операнд раньше по алфавиту чем второй
bool NOTE::operator < (const NOTE &note)
{
	// Вычисление количество дней
	long dataThis = this->birthday[2] * 360 + this->birthday[1] * 30 + this->birthday[0];
	long dataNote = note.birthday[2] * 360 + note.birthday[1] * 30 + note.birthday[0];

	// Сравнение
	return (dataThis < dataNote);
}

// Операция сравнения месяца дня рождения с числом
bool NOTE::operator == (int phoneNumber)
{
	return (this->phoneNumber == phoneNumber);
}

// Операция ввода объекта из потока файла
ifstream& operator >> (ifstream &inStream, NOTE &note)
{
	/*
		Временные переменные
	*/
	char surname[200];// Фамилия
	int phoneNumber;// Номер телефона
	int birthday[3];// Дата рождения
	char tmpSeparator;// Символ разделитель даты

	// Ввод из потока файла нужных данных
	inStream >> surname >> phoneNumber >> birthday[0] >> tmpSeparator >> birthday[1] >> tmpSeparator >> birthday[2];

	// Создание временного объекта
	NOTE tmpNote(surname, phoneNumber, birthday[0], birthday[1], birthday[2]);

	// Присваивание нужному объекту данные временного объекта
	note = tmpNote;

	// Возвращаем поток
	return inStream;
}

/*
	Методы
*/

// Метод вывода значений объекта на экран
void NOTE::show()
{
	cout << left << setw(20) << setfill('.') << "Фамилия"
		<< right << setw(30) << this->surname << endl
		<< left << setw(20) << setfill('.') << "Номер телефона"
		<< right << setw(30) << this->phoneNumber << endl
		<< left << setw(20) << setfill('.') << "День рождения"
		<< right << setw(22) << setfill('.') << this->birthday[0] << "." << right << setw(2) << setfill('0') << this->birthday[1] << "." << right << setw(2) << setfill('0') << this->birthday[2] << endl << endl << endl;
}

/*
	Валидаторы
*/

// Валидатор дня
int NOTE::validatorDays(int days)
{
	while (days < 1 || days > 30) {
		cout << endl << "Внимание ошибка формата дня: " << days << endl
			<< "Введите день вручную: ";
		cin >> days;
		cout << endl << endl;
	}

	return days;
}

// Валидатор месяца
int NOTE::validatorMonth(int month)
{
	while (month < 1 || month > 12) {
		cout << endl << "Внимание ошибка формата месяца: " << month << endl
			<< "Введите месяц вручную: ";
		cin >> month;
		cout << endl << endl;
	}

	return month;
}

// Валидатор года
int NOTE::validatorYear(int year)
{
	while (year < 0) {
		cout << endl << "Внимание ошибка формата года: " << year << endl
			<< "Введите год вручную: ";
		cin >> year;
		cout << endl << endl;
	}

	return year;
}