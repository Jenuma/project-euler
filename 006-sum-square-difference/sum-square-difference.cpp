/*
* The sum of the squares of the first ten natural numbers is 1^2 + 2^2 + ... + 10^2 = 385.
*
* The square of the sum of the first ten natural numbers is (1 + 2 + ... + 10)^2 = 55^2 = 3025.
* 
* Hence the difference between the sum of the squares of the first ten natural numbers and the
* square of the sum is 3025 - 385 = 2640.
* 
* Find the difference between the sum of the squares of the first one hundred natural numbers and
* the square of the sum.
*
* Author: Clifton Roberts
* Date: 29 November 2016
*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{
	const int LIMIT = 100;

	int sumOfSquares = 0;
	int squareOfSum = 0;

	for (int i = 1; i <= LIMIT; i++)
	{
		sumOfSquares += pow(i, 2);
		squareOfSum += i;
	}

	squareOfSum = pow(squareOfSum, 2);

	cout << squareOfSum - sumOfSquares << endl;

	cin.get();
	return 0;
}
