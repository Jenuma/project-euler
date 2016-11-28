/*
* The prime factors of 13195 are 5, 7, 13, and 29.
* 
* What is the largest prime factor of the number 600,851,475,143? 7752
*
* Author: Clifton Roberts
* Date: 28 November 2016
*/

#include <iostream>
#include <windows.h>
#include <math.h>

using namespace std;

bool isPrime(unsigned long n)
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

	const unsigned long long LIMIT = 600851475143;
	const unsigned long SQRT_LIMIT = sqrt(LIMIT);
	const unsigned int INCREMENT = (SQRT_LIMIT / 100);

	unsigned long largestPrime = 0;

	write_head.X = 0;
	write_head.Y = 0;
	WriteConsoleOutputCharacter(hStdOut, "[", 1, write_head, &dw);
	write_head.X += 1;

	for (unsigned long i = 2; i <= SQRT_LIMIT; i++)
	{
		if (INCREMENT % i == 0)
		{
			WriteConsoleOutputCharacter(hStdOut, ".", 1, write_head, &dw);
			write_head.X += 1;
		}

		if (LIMIT % i == 0 && isPrime(i) && i > largestPrime)
		{
			largestPrime = i;
		}
	}

	WriteConsoleOutputCharacter(hStdOut, "]", 1, write_head, &dw);
	write_head.X = 0;
	write_head.Y += 1;
	SetConsoleCursorPosition(hStdOut, write_head);

	cout << largestPrime << endl;

	cin.get();
	return 0;
}
