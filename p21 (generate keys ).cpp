#include<iostream>
#include<string>
#include <cstdlib> //ممكن بزبط بدونها
#include <ctime>      // Include ctime for the time() function, used for seeding the random number generator.
using namespace std;

int ReadPositiveNumber(string m)
{
	int num = 0;
	do
	{
		cout << m ;
		cin >> num;
	} while (num < 0);
	return num;
}
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
string GenerateWorde(entype type, short length)
{
	string worde = "";
	for (int i = 1; i <= length; i++)
	{
		worde+= Random(type);
	}
	return worde;
}
string GenerateKey()
{
	string key = "";
	key += GenerateWorde(entype::CapitalLetter, 4)+"-";
	key += GenerateWorde(entype::CapitalLetter, 4)+"-";
	key += GenerateWorde(entype::CapitalLetter, 4)+"-";
	key += GenerateWorde(entype::CapitalLetter, 4);
	return key;
}
void GenerateKeyS(short NumberPfKey)
{
	for (int i = 1; i <= NumberPfKey; i++)
	{
		cout << "Key [" << i << "] : " << GenerateKey() <<endl;
	}
}
int main()
{
	srand((unsigned)time(NULL));
	GenerateKeyS(ReadPositiveNumber("enter number of keys : "));
	return 0;
}