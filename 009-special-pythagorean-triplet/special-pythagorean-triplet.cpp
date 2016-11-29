/*
* A Pythagorean triplet is a set of three natural numbers, a < b < c, for which a^2 + b^2 = c^2.
* For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.
*
* There exists exactly one Pythagorean triplet for which a + b + c = 1000.
* Find the product abc.
*
* Author: Clifton Roberts
* Date: 29 November 2016
*/

#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

LPCSTR getNextIndicator(LPCSTR);

int main()
{
	DWORD dw;
	COORD write_head;
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	if (hStdOut == INVALID_HANDLE_VALUE)
	{
		cout << "ERROR: Invalid handle." << endl;
		cin.get();
		return 1;
	}

	write_head.X = 0;
	write_head.Y = 1;
	SetConsoleCursorPosition(hStdOut, write_head);

	write_head.Y = 0;
	LPCSTR indicator = "|";
	WriteConsoleOutputCharacter(hStdOut, "Calculating... |", 16, write_head, &dw);
	write_head.X = 15;

	const int LIMIT = 1000;

	for (int a = 3; a < LIMIT; a++)
	{
		for (int b = 4; b < LIMIT; b++)
		{
			for (int c = 5; c < LIMIT; c++)
			{
				if ((a < b && b < c) && (pow(a, 2) + pow(b, 2) == pow(c, 2)) && a + b + c == LIMIT)
				{
					WriteConsoleOutputCharacter(hStdOut, "done.", 5, write_head, &dw);
					cout << a * b * c << endl;

					cin.get();
					return 0;
				}
			}
		}
		indicator = getNextIndicator(indicator);
		WriteConsoleOutputCharacter(hStdOut, indicator, 1, write_head, &dw);
	}

	return 1;
}

LPCSTR getNextIndicator(LPCSTR indicator)
{
	if (indicator == "|")
	{
		return "/";
	}
	else if (indicator == "/")
	{
		return "-";
	}
	else if (indicator == "-")
	{
		return "\\";
	}
	else if (indicator == "\\")
	{
		return "|";
	}
}
