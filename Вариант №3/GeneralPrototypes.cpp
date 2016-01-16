/*
	Реализация общих прототипов
*/

/*
	Подключения библиотек
*/
#include "GeneralPrototypes.h"// Подключение прототипов

// Сортировка методом выбора, по возростанию
void selectSort(WORKER *worker, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int indexMinElement = i;

		for (int j = i + 1; j < size; j++)
		
			if (worker[j] < worker[indexMinElement])
				indexMinElement = j;

			swap(worker[i], worker[indexMinElement]);
		
	}
}