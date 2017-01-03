/*
* The following iterative sequence is defined for the set of positive integers:
*
* n -> n/2 (n is even)
* n -> 3n + 1 (n is odd)
* 
* Using the rule above and starting with 13, we generate the following sequence:
*
* 13 -> 40 -> 20 -> 10 -> 5 -> 16 -> 8 -> 4 -> 2 -> 1
* 
* It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms.
* Although it has not been proved yet (Collatz Problem), it is thought that all starting
* numbers finish at 1.
*
* Which starting number, under one million, produces the longest chain?
*
* Author: Clifton Roberts
* Date: 3 January 2017
*/

#include <iostream>

using namespace std;

int main()
{
	unsigned long long LIMIT = 1000000;
	unsigned long long longestChain = 0;
	int largestChainStarter = 0;

	for (int i = 1; i < LIMIT; i++)
	{
		unsigned long long n = i;
		unsigned long long chain = 1;

		while (n != 1)
		{
			if (n % 2 == 0)
			{
				n = n / 2;
			}
			else
			{
				n = (3 * n) + 1;
			}

			chain++;
		}

		if (chain > longestChain)
		{
			longestChain = chain;
			largestChainStarter = i;
		}
	}

	cout << largestChainStarter << endl;

	cin.get();
	return 0;
}
