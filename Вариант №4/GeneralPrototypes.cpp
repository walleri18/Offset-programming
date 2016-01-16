/*
	Реализация общих функций
*/

/*
	Подключаемы модули
*/
#include "GeneralPrototypes.h"// Модуль общих прототипов

// Сортировка методом выбора
void selectSort(TRAIN *train, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int indexMinElement = i;

		for (int j = i + 1; j < size; j++)
			if (train[j] < train[indexMinElement])
				indexMinElement = j;
		
		swap(train[i], train[indexMinElement]);
	}
}