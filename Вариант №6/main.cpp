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

	// Создаём динамический массив TRAIN
	TRAIN *train = new TRAIN[8];

	char tmpNameDestination[200];// Временное хранилище для названия пункта назвачения
	int tmpTrainNumber;// Временное хранилище для номера поезда
	double tmpDepartureTime;// Временное хранилище для времени отправления

					  // Цикл, пока из файла удаётся считать следующую порцию данных
	for (int i = 0; i < 8; i++)
	{
		// Считываем из файла во временные переменные
		inStream >> tmpNameDestination >> tmpTrainNumber >> tmpDepartureTime;

		// Создаём временный объект MARSH
		TRAIN tmpTRAIN(tmpNameDestination, tmpTrainNumber, tmpDepartureTime);

		// Вносим в массив новый объект
		train[i] = tmpTRAIN;
	}

	// Закрываем поток для чтения из файла
	inStream.close();

	/*
		Массив до сортировки
	*/
	cout << endl << "Массив до сортировки: " << endl << endl;

	for (int i = 0; i < 8; i++)
		train[i].show();

	// Отсортируем массив TRAIN
	selectSort(train, 8);

	/*
	Массив после сортировки
	*/
	cout << endl << "Массив после сортировки: " << endl << endl;

	for (int i = 0; i < 8; i++)
		train[i].show();

	// Ввод номер поезда
	cout << "Введите пожалуйста номер поезда: ";
	cin >> tmpTrainNumber;

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
		else if (train[i] == tmpTrainNumber) {

			// Вывод
			train[i].show();

			// Увеличение счётчика
			count++;
		}
	}

	// Приостонавливаем прогу, чтобы успеть увидеть результат
	system("pause");

	return NULL;// Передаём управление операционной системе
}