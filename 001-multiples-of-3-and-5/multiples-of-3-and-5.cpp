/*
 * Project Euler Problem #001 - Multiples of 3 and 5
 * If we list all the natural numbers below 10 that are multiples of
 * 3 or 5, we get 3, 5, 6, and 9. The sum of these multiples is 23.
 *
 * Find the sum of all the multiples of 3 or 5 below 1000.
 *
 * Author: Clifton Roberts
 * Date: 11 November 2016
 */

#include <iostream>

using namespace std;

int main()
{
	const int LIMIT = 1000;

	int sum = 0;
	for (int i = 0; i < LIMIT; i++)
	{
		if (i % 3 == 0 || i % 5 == 0)
		{
			sum += i;
		}
	}

	cout << sum << endl;

	cin.get();
	return 0;
}
