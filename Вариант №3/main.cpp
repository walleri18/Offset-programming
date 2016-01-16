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

	// Создание динамического массива WORKER на 8 элементов, если быть точнее мы всего лишь выделям память под эти объекты
	WORKER *worker = new WORKER[8];

	char tmpSurnameWorking[200];// Временная переменная для хранения фамилии рабочего
	char tmpPost[200];// Временная переменная для хранения названии должности рабочего
	int tmpYearEntry;// Временная переменная для хранения года поступления на работу

	// Цикл чтения из файла
	for (int i = 0; i < 8; i++)
	{
		// Считывание данных во временные переменные
		inStream >> tmpSurnameWorking >> tmpPost >> tmpYearEntry;

		// Создание временного объекта WORKER
		WORKER tmpWORKER(tmpSurnameWorking, tmpPost, tmpYearEntry);

		// Вставка временного объекта в массив worker
		worker[i] = tmpWORKER;
	}

	// Закрываем поток
	inStream.close();

	/*
		Вывод массива до сортировки
	*/
	cout << endl << "Вывод массива до сортировки: " << endl << endl;

	for (int i = 0; i < 8; i++)
		worker[i].show();

	// Сортируем массив WORKER. Первый аргумент - это указатель на первый элемент массива, а второй - размер массива
	selectSort(worker, 8);

	/*
		Вывод массива после сортировки
	*/
	cout << endl << "Вывод массива после сортировки: " << endl << endl;

	for (int i = 0; i < 8; i++)
		worker[i].show();

	// Временная переменная для хранения стажа работника
	int tmpExperience;

	// Ввод стажа
	cout << "Введите пожалуйста стаж для сравнения: ";
	cin >> tmpExperience;

	// Очистка экрана
	system("cls");

	// Поиск информации
	for (int i = 0, count = 0; i <= 8; i++)
	{
		// Если пройдясь по всем записям и не нашлось ни одного совпадения
		if ((i == 8) && count == 0)
			cout << "Со cтажем " << tmpExperience << " таких работников у нас нету(" << endl << endl;

		// Если прошлись по всем записям и нашлись совпадения
		else if (i == 8 && count != 0)
			break;

		// Если не закончились записи, ищем
		else if (worker[i] > tmpExperience) {

			// Вывод
			worker[i].show();

			// Увеличение счётчика
			count++;
		}
	}

	// Приостановка программы для просмотра результата
	system("pause");

	return NULL;// Передача управления операционной системе
}