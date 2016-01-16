/*
	Реализация общих прототипов
*/

/*
	Подключения библиотек
*/
#include "GeneralPrototypes.h"// Подключение прототипов

// Сортировка методом выбора, по возростанию
void selectSort(NOTE *note, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int indexMinElement = i;

		for (int j = i + 1; j < size; j++)
		
			if (note[j] < note[indexMinElement])
				indexMinElement = j;
			
			swap(note[i], note[indexMinElement]);
		
	}
}