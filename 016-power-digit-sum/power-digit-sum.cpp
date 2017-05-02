#include <iostream>
#include <string>
#include <list>

using namespace std;

int main()
{
	list<int> powerDigits;
	powerDigits.push_back(1);

	for (int i = 1; i <= 1000; i++)
	{
		//cout << "\nIteration: " << i << endl;

		int carry = 0;
		list<int> tempList;

		for (list<int>::reverse_iterator j = powerDigits.rbegin(); j != powerDigits.rend(); j++)
		{
			int newDigit = (*j * 2) + carry;
			//cout << *j << " * 2 + " << carry << + "= " << newDigit << endl;

			if (newDigit > 9)
			{
				tempList.push_front(newDigit % 10);
				carry = newDigit / 10;
			}
			else
			{
				tempList.push_front(newDigit);
				carry = 0;
			}

			if (next(j) == powerDigits.rend() && carry > 0)
			{
				tempList.push_front(carry);
			}
		}

		powerDigits = tempList;
	}

	unsigned long long sum = 0;
	for (list<int>::iterator i = powerDigits.begin(); i != powerDigits.end(); i++)
	{
		sum += *i;
	}

	cout << "Sum: " << sum << endl;

	cin.get();
	return 0;
}
