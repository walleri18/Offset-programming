#pragma once
/*
	Подключения
*/
#include "NOTE.h"// Подключение класса NOTE

/*
	Библиотека общих прототипов
*/

// Сортировка методом выбора
void selectSort(NOTE*, int);

// Номера цветов
enum ConsoleColor
{
	Black = 0,
	Blue = 1,
	Green = 2,
	Cyan = 3,
	Red = 4,
	Magenta = 5,
	Brown = 6,
	LightGray = 7,
	DarkGray = 8,
	LightBlue = 9,
	LightGreen = 10,
	LightCyan = 11,
	LightRed = 12,
	LightMagenta = 13,
	Yellow = 14,
	White = 15
};

// Манипуляция с цветом в консоли
void SetColor(int text, ConsoleColor background);