/*
* By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.
* 
* What is the 10001st prime number?
*
* Author: Clifton Roberts
* Date: 29 November 2016
*/

#include <iostream>
#include <math.h>

using namespace std;

bool isPrime(unsigned long);

int main()
{
	const int LIMIT = 10001;
	int discoveredPrimes = 0;
	unsigned long long i = 1;

	while (discoveredPrimes < LIMIT)
	{
		i++;
		if (isPrime(i))
		{
			discoveredPrimes++;
		}
	}

	cout << i << endl;

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
