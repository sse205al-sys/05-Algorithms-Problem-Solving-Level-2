#include<iostream>
#include<string>
using namespace std;

int ReadPositivNumber(string message)
{
	int num = 0;
	do
	{
		cout << message;
		cin >> num;
	} while (num <= 0);
	return num;
}

int ReversNumber(int number)
{
	int reversNumber = 0;
	int remainder = 0;
	while (number > 0)
	{
		remainder = number % 10;
		number = number / 10;
		reversNumber = reversNumber * 10 + remainder;
	}
	return reversNumber;
}
void PrintDigits(int number)
{
	
	int remainder = 0;

	while (number > 0)
	{
		remainder = number % 10;
		number = number / 10;
	
		cout << remainder << endl;
	}
}

int main()
{
	
	PrintDigits(ReversNumber(ReadPositivNumber("enter number : "))) ;
	return 0;
}