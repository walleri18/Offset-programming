﻿/*
	Подключаем необходимые библиотеки;
*/
#include "WORKER.h"// Подключаем наши определения для того чтобы их реализовать здесь;

/*
	Класс WORKER(определения);
*/

/*
	Конструкторы;
*/

// Конструктор по-умолчанию;
WORKER::WORKER() : surnameWorking(NULL), post(NULL), experience(1)
{
}

// Деструктор по-умолчанию;
WORKER::~WORKER()
{
	if (this->surnameWorking)
		delete[] this->surnameWorking;// Освобождаем память из-под фамилии работника и возвращаем её во владении операционной системе
	if(this->post)
		delete[] this->post;
}

// Конструктор для заполнения всех полей класса: фамилия рабочего(surnameWorking), название занимаемой должности(post), год поступления на работу(yearEntry);
WORKER::WORKER(const char *surnameWorking, const char *post, int experience)
{
	/*
		Фамилия работника;
	*/
	this->surnameWorking = new char[strlen(surnameWorking) + 1];// С помощью функции strlen узнаём размер переданной нам строки (без учёта нуля символа) и прибаляем единицу, чтобы потом поместился нуль символ;
																
	strcpy(this->surnameWorking, surnameWorking);// Функция strcpy копирует побайтово (первый аргумент - это куда надо скопировать, второй аргумент откуда *в данном случае что нужно скопировать (на самом деле тоже откуда, но объяснять долго, ну да ладно, при выполнении программы создаётся таблица строк, в которую заносятся все строковые константы, ну и мы просто берём адрес таблицы, то есть строки в которой есть необходимые данные)*);

	/*
		Название должности;
	*/
	this->post = new char[strlen(post) + 1];// Аналогично из строки 50

	strcpy(this->post, post);// Где-то ты уже это читал, не правда ли?);

	/*
		Стаж работника;
	*/
	this->experience = experience;// Заносим поступившие данные из вне);
}

// Конструктор копирования;
WORKER::WORKER(WORKER &worker)
{
	/*
		worker.get..... - это всего лишь наши геттеры, они возвращают нам значения полей. Смекаешь? Ну а дальше всё аналогично
	*/

	/*
		Фамилия работника;
	*/
	this->surnameWorking = new char[strlen(worker.surnameWorking) + 1];// Где-то ты уже это читал, не правда ли?);

	strcpy(this->surnameWorking, worker.surnameWorking);// Где-то ты уже это читал, не правда ли?);

	/*
		Название должности;
	*/
	this->post = new char[strlen(worker.post) + 1];// Где-то ты уже это читал, не правда ли?);

	strcpy(this->post, worker.post);// Где-то ты уже это читал, не правда ли?);

	/*
		Стаж работника;
	*/
	this->experience = worker.experience;// Где-то ты уже это читал, не правда ли?);
}

/*
	Операции;
*/

// Операция присваивания
WORKER& WORKER::operator = (WORKER &worker)
{
	// Защита от самоприсваивания
	if (this == &worker)
		return *this;

	/*
		worker.get..... - Где-то ты уже это читал, не правда ли?);
	*/

	/*
		Фамилия работника;
	*/
	delete this->surnameWorking;// Освобождаем старую память, которая нам уже ненужна. Мы это делаем потому, что объект у нас уже есть, следовательно память для его фамилии и должности уже была выделена и мы конечно от неё благополучно избавляемся

	this->surnameWorking = new char[strlen(worker.surnameWorking) + 1];// Где-то ты уже это читал, не правда ли?);

	strcpy(this->surnameWorking, worker.surnameWorking);// Где-то ты уже это читал, не правда ли?);

	/*
		Название должности;
	*/
	delete this->post;// Аналогично

	this->post = new char[strlen(worker.post) + 1];// Где-то ты уже это читал, не правда ли?);

	strcpy(this->post, worker.post);// Где-то ты уже это читал, не правда ли?);

	/*
		Стаж работника;
	*/
	this->experience = worker.experience;// Где-то ты уже это читал, не правда ли?);

	/*
		Возвращение значения из метода;
	*/
	return *this;// Надеюсь ты помнишь, что в C++ разрешено множественное присваивание для простых типов таких как int и прочих. Ну вот мы сохраняем традиции) И возвращаем ссылку, чтобы над объектом могли потом дальше издеваться)
}

// Операция сравнения "меньше" (возвращает истину, если фамилия работника у первого операнда раньше по алфавиту чем у второго операнда. [первый операнд - это this - объект, который вызывает эту операцию, то есть (worker1 < worker2) worker1 является вызывающим, так как он стоит раньше, чтобы понять можно привести аналогию (worker1.operator<(worker2)) - так на самом деле выглядит вызов, но компилятор нам позволяет писать более элегантно, то сеть так (worker1 < worker2)]);
bool WORKER::operator < (WORKER &worker)
{
	// С помощью функции strcmp определём отношение строк друг другу. Рекомендую посмотреть документацию по этому поводу. Поставь указатель мыши на название функции и нажми F1, ну и читай)
	return (strcmp(this->surnameWorking, worker.surnameWorking) < 0);
}

// Операция сравнения "больше" (возвращает истину, если стаж работника превышает данное число. Под данным работником понимается объект this *читай предыдущий комментарий*);
bool WORKER::operator > (int experience)
{
	// Всё написано на строке 145
	return (this->experience > experience);
}

/*
	Методы;
*/

// Метод вывода на экран знаечний полей класса;
void WORKER::show()
{
	/*
		Мой вывод - это мой вывод, так что можешь поменять) Не боись, не сломаешь, я надеюсь)
	*/
	cout << left << setw(30) << setfill('.') << "Фамилия работника"
		<< right << setw(30) << this->surnameWorking << endl
		<< left << setw(30) << setfill('.') << "Название должности"
		<< right << setw(30) << this->post << endl
		<< left << setw(30) << setfill('.') << "Стаж работника"
		<< right << setw(30) << this->experience << endl << endl;
}