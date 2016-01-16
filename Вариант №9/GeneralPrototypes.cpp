/*
	Реализация общих функций
*/

/*
	Подключаемы модули
*/
#include "GeneralPrototypes.h"// Модуль общих прототипов

// Сортировка методом выбора, по возростанию
void selectSort(NOTE *note, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int indexMinElement = i;

		for (int j = i + 1; j < size; j++)
			// Ищем минимальный элемент из оставшихся
			if (note[j] < note[indexMinElement])
				indexMinElement = j;

		// Меняем местами
		swap(note[i], note[indexMinElement]);
		
	}
}

// Манипуляция с цветом в консоли
void SetColor(int text, ConsoleColor background)
{
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hStdOut, (WORD)((background << 4) | text));
}