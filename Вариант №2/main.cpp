/*
Подключение библиотек
*/
#include "GeneralPrototypes.h"// Общие прототипы

// Точка входа в программу

int main(void)
{
	setlocale(LC_ALL, ".1251");// Русификация

	// Создание входящего потока и его открытие
	ifstream inStream("readme.txt");

	// Проверка на открытие файла
	if (!inStream.is_open()) {
		cout << "Ошибка открытия файла readme.txt" << endl;
		system("pause");
		exit(1);
	}

	// Создание динамического массива AEROFLOT на 8 элементов, если быть точнее мы всего лишь выделям память под эти объекты
	AEROFLOT *aeroflot = new AEROFLOT[8];

	char tmpDestinationFlight[200];// Временная переменная для хранения пункта назначения рейса
	char tmpTypeAircraft[200];// Временная переменная для хранения типа самолёта
	int tmpFlightNumber;// Временная переменная для хранения номера рейса

	// Цикл чтения из файла
	for (int i = 0; i < 8; i++)
	{
		// Считывание данных во временные переменные
		inStream >> tmpDestinationFlight >> tmpFlightNumber >> tmpTypeAircraft;

		// Создание временного объекта WORKER
		AEROFLOT tmpAEROFLOT(tmpDestinationFlight, tmpFlightNumber, tmpTypeAircraft);

		// Вставка временного объекта в массив aeroflot
		aeroflot[i] = tmpAEROFLOT;
	}

	// Закрываем поток
	inStream.close();

	/*
		Вывод массива до сортировки
	*/
	cout << endl << "Вывод массива до сортировки: " << endl << endl;

	for (int i = 0; i < 8; i++)
		aeroflot[i].show();

	// Сортируем массив AEROFLOT. Первый аргумент - это указатель на первый элемент массива, а второй - размер массива
	selectSort(aeroflot, 8);

	/*
		Вывод массива после сортировки
	*/
	cout << endl << "Вывод массива после сортировки: " << endl << endl;

	for (int i = 0; i < 8; i++)
		aeroflot[i].show();

	// Ввод типа самолёта
	cout << "Введите пожалуйста тип самолёта для поиска: ";
	cin >> tmpTypeAircraft;

	// Перевод из кракозябр в русские символы
	OemToCharA(tmpTypeAircraft, tmpTypeAircraft);

	// Очистка экрана
	system("cls");

	// Поиск информации
	for (int i = 0, count = 0; i <= 8; i++)
	{
		// Если пройдясь по всем записям и не нашлось ни одного совпадения
		if ((i == 8) && count == 0)
			cout << "Самолёт типа " << tmpTypeAircraft << " не летает." << endl << endl;

		// Если прошлись по всем записям и нашлись совпадения
		else if (i == 8 && count != 0)
			break;

		// Если не закончились записи, ищем
		else if (aeroflot[i] == tmpTypeAircraft) {

			// Вывод
			aeroflot[i].show();

			// Увеличение счётчика
			count++;
		}
	}

	// Приостановка программы для просмотра результата
	system("pause");

	return NULL;// Передача управления операционной системе
}