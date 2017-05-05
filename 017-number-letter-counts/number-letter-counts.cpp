/* If the numbers 1 to 5 are written out in words : one, two, three, four, five,
 * then there are 3 + 3 + 5 + 4 + 4 = 19 letters used in total.
 *
 * If all the numbers from 1 to 1000 (one thousand) inclusive were written out in
 * words, how many letters would be used ?
 *
 *
 * NOTE : Do not count spaces or hyphens.For example, 342 (three hundred and
 * forty - two) contains 23 letters and 115 (one hundred and fifteen) contains
 * 20 letters.The use of "and" when writing out numbers is in compliance with
 * British usage.
 *
 * Author: Clifton Roberts
 * Date : 5 May 2017
 */

#include <iostream>
#include <string>

using namespace std;

int main()
{
	string oneStr = "one";
	string twoStr = "two";
	string threeStr = "three";
	string fourStr = "four";
	string fiveStr = "five";
	string sixStr = "six";
	string sevenStr = "seven";
	string eightStr = "eight";
	string nineStr = "nine";
	string tenStr = "ten";
	string elevenStr = "eleven";
	string twelveStr = "twelve";
	string thirteenStr = "thirteen";
	string fourteenStr = "fourteen";
	string fifteenStr = "fifteen";
	string sixteenStr = "sixteen";
	string seventeenStr = "seventeen";
	string eighteenStr = "eighteen";
	string nineteenStr = "nineteen";
	string twentyStr = "twenty";
	string thirtyStr = "thirty";
	string fortyStr = "forty";
	string fiftyStr = "fifty";
	string sixtyStr = "sixty";
	string seventyStr = "seventy";
	string eightyStr = "eighty";
	string ninetyStr = "ninety";
	string hundredStr = "hundred";
	string andStr = "and";
	string thousandStr = "thousand";

	unsigned long long sum = 0;

	for (int i = 1; i <= 1000; i++)
	{
		string numbersString = "";

		if (i == 1000)
		{
			sum += oneStr.length();
			sum += thousandStr.length();

			numbersString += oneStr + " " + thousandStr;
		}
		else if (i > 99)
		{
			sum += hundredStr.length();

			int hundredsDigit = i / 100;

			switch (hundredsDigit)
			{
				case 1:
					sum += oneStr.length();
					numbersString += " " + oneStr;
					break;
				case 2:
					sum += twoStr.length();
					numbersString += " " + twoStr;
					break;
				case 3:
					sum += threeStr.length();
					numbersString += " " + threeStr;
					break;
				case 4:
					sum += fourStr.length();
					numbersString += " " + fourStr;
					break;
				case 5:
					sum += fiveStr.length();
					numbersString += " " + fiveStr;
					break;
				case 6:
					sum += sixStr.length();
					numbersString += " " + sixStr;
					break;
				case 7:
					sum += sevenStr.length();
					numbersString += " " + sevenStr;
					break;
				case 8:
					sum += eightStr.length();
					numbersString += " " + eightStr;
					break;
				case 9:
					sum += nineStr.length();
					numbersString += " " + nineStr;
					break;
			}

			numbersString += " " + hundredStr;
		}

		int tensAndOnesDigits = i % 100;

		if (i > 100 && tensAndOnesDigits > 0)
		{
			sum += andStr.length();
			numbersString += " " + andStr;
		}

		if (tensAndOnesDigits < 20)
		{
			switch (tensAndOnesDigits)
			{
				case 1:
					sum += oneStr.length();
					numbersString += " " + oneStr;
					break;
				case 2:
					sum += twoStr.length();
					numbersString += " " + twoStr;
					break;
				case 3:
					sum += threeStr.length();
					numbersString += " " + threeStr;
					break;
				case 4:
					sum += fourStr.length();
					numbersString += " " + fourStr;
					break;
				case 5:
					sum += fiveStr.length();
					numbersString += " " + fiveStr;
					break;
				case 6:
					sum += sixStr.length();
					numbersString += " " + sixStr;
					break;
				case 7:
					sum += sevenStr.length();
					numbersString += " " + sevenStr;
					break;
				case 8:
					sum += eightStr.length();
					numbersString += " " + eightStr;
					break;
				case 9:
					sum += nineStr.length();
					numbersString += " " + nineStr;
					break;
				case 10:
					sum += tenStr.length();
					numbersString += " " + tenStr;
					break;
				case 11:
					sum += elevenStr.length();
					numbersString += " " + elevenStr;
					break;
				case 12:
					sum += twelveStr.length();
					numbersString += " " + twelveStr;
					break;
				case 13:
					sum += thirteenStr.length();
					numbersString += " " + thirteenStr;
					break;
				case 14:
					sum += fourteenStr.length();
					numbersString += " " + fourteenStr;
					break;
				case 15:
					sum += fifteenStr.length();
					numbersString += " " + fifteenStr;
					break;
				case 16:
					sum += sixteenStr.length();
					numbersString += " " + sixteenStr;
					break;
				case 17:
					sum += seventeenStr.length();
					numbersString += " " + seventeenStr;
					break;
				case 18:
					sum += eighteenStr.length();
					numbersString += " " + eighteenStr;
					break;
				case 19:
					sum += nineteenStr.length();
					numbersString += " " + nineteenStr;
					break;
			}
		}
		else
		{
			int tensDigit = tensAndOnesDigits / 10;
			int onesDigit = tensAndOnesDigits % 10;

			switch (tensDigit)
			{
				case 2:
					sum += twentyStr.length();
					numbersString += " " + twentyStr;
					break;
				case 3:
					sum += thirtyStr.length();
					numbersString += " " + thirtyStr;
					break;
				case 4:
					sum += fortyStr.length();
					numbersString += " " + fortyStr;
					break;
				case 5:
					sum += fiftyStr.length();
					numbersString += " " + fiftyStr;
					break;
				case 6:
					sum += sixtyStr.length();
					numbersString += " " + sixtyStr;
					break;
				case 7:
					sum += seventyStr.length();
					numbersString += " " + seventyStr;
					break;
				case 8:
					sum += eightyStr.length();
					numbersString += " " + eightyStr;
					break;
				case 9:
					sum += ninetyStr.length();
					numbersString += " " + ninetyStr;
					break;
			}

			if (onesDigit > 0)
			{
				switch (onesDigit)
				{
					case 1:
						sum += oneStr.length();
						numbersString += " " + oneStr;
						break;
					case 2:
						sum += twoStr.length();
						numbersString += " " + twoStr;
						break;
					case 3:
						sum += threeStr.length();
						numbersString += " " + threeStr;
						break;
					case 4:
						sum += fourStr.length();
						numbersString += " " + fourStr;
						break;
					case 5:
						sum += fiveStr.length();
						numbersString += " " + fiveStr;
						break;
					case 6:
						sum += sixStr.length();
						numbersString += " " + sixStr;
						break;
					case 7:
						sum += sevenStr.length();
						numbersString += " " + sevenStr;
						break;
					case 8:
						sum += eightStr.length();
						numbersString += " " + eightStr;
						break;
					case 9:
						sum += nineStr.length();
						numbersString += " " + nineStr;
						break;
				}
			}
		}

		cout << "Current: " << numbersString << "\nSum so far: " << sum << endl;
	}

	cout << "Sum: " << sum << endl;

	cin.get();
	return 0;
}
