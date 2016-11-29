/*
* A palindromic number reads the same both ways. The largest palindrome made from the product of
* 2-digit numbers is 9009 = 91 x 99.
* 
* Find the largest palindrome made from the product of two 3-digit numbers.
*
* Author: Clifton Roberts
* Date: 29 November 2016
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

bool isPalindrome(string);

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

	unsigned int largestPalindrome = 0;
	unsigned int product = 0;
	string strProduct = "";

	write_head.X = 0;
	write_head.Y = 1;
	SetConsoleCursorPosition(hStdOut, write_head);

	write_head.Y = 0;
	WriteConsoleOutputCharacter(hStdOut, "[", 1, write_head, &dw);
	write_head.X = 101;
	WriteConsoleOutputCharacter(hStdOut, "] 0%", 5, write_head, &dw);
	write_head.X = 1;
	int writeHeadProgress = write_head.X;

	unsigned int iterations = 0;
	for (int i = 999; i >= 100; i--)
	{
		for (int j = 999; j >= 100; j--)
		{
			product = i * j;
			strProduct = to_string(product);

			if (isPalindrome(strProduct) && product > largestPalindrome)
			{
				largestPalindrome = product;
			}

			iterations++;
			if (iterations % 8100 == 0)
			{
				string percentStr = to_string(iterations / 8100) + "%";
				LPCSTR percent = percentStr.c_str();

				writeHeadProgress = write_head.X;
				write_head.X = 103;
				WriteConsoleOutputCharacter(hStdOut, percent, strlen(percent), write_head, &dw);

				write_head.X = writeHeadProgress;
				WriteConsoleOutputCharacter(hStdOut, ".", 1, write_head, &dw);
				write_head.X += 1;
			}
		}
	}

	cout << largestPalindrome << endl;

	cin.get();
	return 0;
}

bool isPalindrome(string strProduct)
{
	string product = strProduct;
	reverse(strProduct.begin(), strProduct.end());

	if (product == strProduct)
	{
		return true;
	}
	else
	{
		return false;
	}
}
