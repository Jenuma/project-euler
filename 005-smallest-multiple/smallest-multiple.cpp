/*
* 2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any
* remainder.
*
* What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*
* Author: Clifton Roberts
* Date: 29 November 2016
*/

#include <algorithm>
#include <iostream>
#include <windows.h>

using namespace std;

bool areAllDivisors(bool[20]);
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

	bool divisorRecord[20];
	fill_n(divisorRecord, 20, false);

	unsigned long long smallestNumber = 20;
	while (!areAllDivisors(divisorRecord))
	{
		if (smallestNumber % 10000000 == 0)
		{
			indicator = getNextIndicator(indicator);
			WriteConsoleOutputCharacter(hStdOut, indicator, 1, write_head, &dw);
		}

		for (int i = 0; i < 20; i++)
		{
			if (smallestNumber % (i + 1) == 0)
			{
				divisorRecord[i] = true;
			}
			else
			{
				smallestNumber += 20;
				fill_n(divisorRecord, 20, false);
				break;
			}
		}
	}

	WriteConsoleOutputCharacter(hStdOut, "done.", 5, write_head, &dw);
	cout << smallestNumber << endl;

	cin.get();
	return 0;
}

bool areAllDivisors(bool divisors[20])
{
	for (int i = 0; i <= 20; i++)
	{
		if (!divisors[i])
		{
			return false;
		}
	}
	return true;
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
