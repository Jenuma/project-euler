/*
* The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.
* 
* Find the sum of all the primes below two million.
*
* Author: Clifton Roberts
* Date: 29 November 2016
*/

#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;

bool isPrime(unsigned int);
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

	const unsigned int LIMIT = 2000000;
	unsigned long long sum = 0;

	for (int i = 2; i < LIMIT; i++)
	{
		if (i % 50000 == 0)
		{
			indicator = getNextIndicator(indicator);
			WriteConsoleOutputCharacter(hStdOut, indicator, 1, write_head, &dw);
		}

		if (isPrime(i))
		{
			sum += i;
		}
	}

	WriteConsoleOutputCharacter(hStdOut, "done.", 5, write_head, &dw);
	cout << sum << endl;

	cin.get();
	return 0;
}

bool isPrime(unsigned int n)
{
	if (n < 2)
	{
		return false;
	}
	else if (n == 2)
	{
		return true;
	}
	else
	{
		for (unsigned long i = 2; i <= sqrt(n); i++)
		{
			if (n % i == 0)
			{
				return false;
			}
		}

		return true;
	}
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
