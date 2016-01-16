/*
	Реализация общих функций
*/

/*
	Подключаемы модули
*/
#include "GeneralPrototypes.h"// Модуль общих прототипов

// Сортировка методом выбора
void selectSort(MARSH *marsh, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int indexMinElement = i;

		for (int j = i + 1; j < size; j++)
			if (marsh[j] < marsh[indexMinElement])
				indexMinElement = j;
			
		swap(marsh[i], marsh[indexMinElement]);
	}
}