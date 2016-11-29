/*
* The prime factors of 13195 are 5, 7, 13, and 29.
* 
* What is the largest prime factor of the number 600,851,475,143? 7752
*
* Author: Clifton Roberts
* Date: 28 November 2016
*/

#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(unsigned long);

int main()
{
	const unsigned long long LIMIT = 600851475143;
	const unsigned long SQRT_LIMIT = sqrt(LIMIT);

	unsigned long largestPrime = 0;

	for (unsigned long i = 2; i <= SQRT_LIMIT; i++)
	{
		if (LIMIT % i == 0 && isPrime(i) && i > largestPrime)
		{
			largestPrime = i;
		}
	}

	cout << largestPrime << endl;

	cin.get();
	return 0;
}

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
