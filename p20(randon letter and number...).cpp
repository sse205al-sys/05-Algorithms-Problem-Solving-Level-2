#include<iostream>
#include<string>
#include <cstdlib> //ممكن بزبط بدونها
#include <ctime>      // Include ctime for the time() function, used for seeding the random number generator.
using namespace std;

int RandomNumber(int from, int to)
{
	int randNum = rand() % (to - from + 1) + from;
	return randNum;
}
enum entype { SmallLetter = 1, CapitalLetter = 2, SpecialChar = 3, Digit = 4 };

char Random(entype t)
{
	switch (t)
	{
	case entype::SmallLetter:
		return char(RandomNumber(97,122));
	case entype::CapitalLetter:
		return char(RandomNumber(65, 90));
	case entype::SpecialChar:
		return char(RandomNumber(33,47));
	case entype::Digit:
		return char(RandomNumber(48,57));
	}
}
int main()
{
	srand((unsigned)time(NULL));

	cout<<Random(entype::SmallLetter)<<endl;
	cout << Random(entype::CapitalLetter) << endl;
	cout << Random(entype::SpecialChar) << endl;
	cout << Random(entype::Digit) << endl;
}