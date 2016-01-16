/*
	Подключаемые модули
*/
#include "GeneralPrototypes.h"// Общие объявления

// Точка входа в программу

int main(void)
{
	setlocale(LC_ALL, ".1251");// Русификация

	// Создание входного файлового потока и его открытие
	ifstream inStream("readme.txt");

	// Проверка на открытие файла
	if (!inStream.is_open()) {
		cout << "Ошибка открытия файла readme.txt" << endl;
		system("pause");
		exit(1);
	}

	// Создаём динамический массив NOTE
	MARSH *marsh = new MARSH[8];

	char tmpBeginPoint[200];// Временное хранилище для начального пункта
	char tmpFinalPoint[200];// Временное хранилище для конечного пункта
	int tmpNumberRout;// Временное хранилище номера марширута

	// Цикл, пока из файла удаётся считать следующую порцию данных
	for (int i = 0; i < 8; i++)
	{
		// Считываем из файла во временные переменные
		inStream >> tmpBeginPoint >> tmpFinalPoint >> tmpNumberRout;

		// Создаём временный объект MARSH
		MARSH tmpMARSH(tmpBeginPoint, tmpFinalPoint, tmpNumberRout);

		// Вносим в массив новый объект
		marsh[i] = tmpMARSH;
	}

	// Закрываем поток для чтения из файла
	inStream.close();

	/*
		Массив до сортировки
	*/
	cout << endl << "Массив до сортировки: " << endl << endl;

	for (int i = 0; i < 8; i++)
		marsh[i].show();


	// Отсортируем массив NOTE
	selectSort(marsh, 8);

	/*
		Массив после сортировки
	*/
	cout << endl << "Массив после сортировки: " << endl << endl;

	for (int i = 0; i < 8; i++)
		marsh[i].show();

	// Временная переменная для хранения названия пункта
	char tmpPoint[200];

	// Ввод месяца
	cout << "Введите пожалуйста название пункта для сравнения(на русском): ";
	cin >> tmpPoint;

	// Переводим введённые символы из аброкадабры в нормальный русский язык
	OemToCharA(tmpPoint, tmpPoint);

	// Очистка экрана
	system("cls");

	// Поиск и вывод информации о людях с совпадением месяца
	for (int i = 0, count = 0; i <= 8; i++)
	{
		// Если пройдясь по всем записям и не нашлось ни одного совпадения
		if ((i == 8) && count == 0)
			cout << "Нет соответствующей записи" << endl;

		// Если прошлись по всем записям и нашлись совпадения
		else if (i == 8 && count != 0)
			break;

		// Если не закончились записи, ищем совпадения
		else if (marsh[i] == tmpPoint) {

			// Вывод
			marsh[i].show();

			// Увеличение счётчика
			count++;
		}
	}

	// Приостонавливаем прогу, чтобы успеть увидеть результат
	system("pause");

	return NULL;// Передаём управление операционной системе
}