#pragma once
#define _CRT_SECURE_NO_WARNINGS
/*
Plugins for the operation
*/
#include <iostream>// A C++ library for input / output
#include <iomanip>// Library With++ for use of manipulators with parameters
#include <fstream>// A C++ library for working with file streams
#include <cstdio>// Standard C library for input / output and other

using namespace std;// Plug the std namespace

/**
	Class NOTE (definitions)
*/
class NOTE
{
/*
	Data
*/
// Closed
private:
	char *surname;// Surname
	int phoneNumber;// Phone number
	int birthday[3];// Birthday format: birthday[0] = DD, birthday[1] = MM, birthday[2] = YYYY
/*
	Function
*/
// Open
public:

	/*
		Designers
	*/

	NOTE();// The default constructor

	~NOTE();// The default destructor

	NOTE(const char*, int, int, int, int);// Constructor with all parameters: last name, phone number, day of birth, month of birth, year of birth

	NOTE(const NOTE&);// The copy constructor

	/*
		Operations
	*/

	NOTE& operator = (const NOTE&);// The assignment operation

	bool operator < (const NOTE&);// Comparison operation "less than", returns true if the first operand is greater than second

	bool operator == (int);// The comparison of the month's birthday number

	/*
		Methods
	*/

	void show();// The output method values of an object on the screen
};