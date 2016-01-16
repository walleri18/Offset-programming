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
		cout << "Ошибка открытия файла file.txt" << endl;
		system("pause");
		exit(1);
	}

	// Создание динамического массива NOTE
	NOTE *notes = new NOTE[8];

	char tmpSurname[200];// Временная переменная фамилии
	int tmpPhoneNumber(0);// Временная переменная номера телефона
	int tmpBirthday[3] = { 0 };// Временная переменная даты рождения
	char tmpSeparator(' ');// Символ разделяющий дату рождения

	// Цикл чтения из файла
	for (int i = 0; i < 8; i++)
	{
		// Считывание данных во временные переменные
		inStream >> tmpSurname >> tmpPhoneNumber >> tmpBirthday[0] >> tmpSeparator >> tmpBirthday[1] >> tmpSeparator >> tmpBirthday[2];

		// Создание временного объекта NOTE
		NOTE tmpNote(tmpSurname, tmpPhoneNumber, tmpBirthday[0], tmpBirthday[1], tmpBirthday[2]);

		// Вставка временного объекта в массив notes
		notes[i] = tmpNote;
	}

	// Закрываем поток
	inStream.close();

	/*
		Вывод массива до сортировки
	*/
	cout << endl << "Вывод массива до сортировки: " << endl << endl;

	for (int i = 0; i < 8; i++)
		notes[i].show();

	// Сортируем массив NOTE
	selectSort(notes, 8);

	/*
		Вывод массива после сортировки
	*/
	cout << endl << "Вывод массива после сортировки: " << endl << endl;

	for (int i = 0; i < 8; i++)
		notes[i].show();

	// Временная переменная месяца рождения
	int birthdayMM;

	// Ввод месяца
	cout << "Введите пожалуйста номер месяца для сравнения: ";
	cin >> birthdayMM;

	// Очистка экрана
	system("cls");

	// Поиск информации
	for (int i = 0, count = 0; i <= 8; i++)
	{
		// Если пройдясь по всем записям и не нашлось ни одного совпадения
		if ((i == 8) && count == 0)
			cout << "Нет соответствующей записи" << endl;

		// Если прошлись по всем записям и нашлись совпадения
		else if (i == 8 && count != 0)
			break;

		// Если не закончились записи, ищем совпадения
		else if (notes[i] == birthdayMM) {
			
			// Вывод
			notes[i].show();

			// Увеличение счётчика
			count++;
		}
	}

	// Приостановка программы для просмотра результата
	system("pause");

	return NULL;// Передача управления операционной системе
}