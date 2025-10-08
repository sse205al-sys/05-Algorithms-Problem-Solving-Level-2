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

int SumDigits(int number)
{
	int sum = 0;
	int remainder = 0;
	while (number > 0)
	{
		remainder = number % 10;
		number = number / 10;
		sum += remainder;
	}
	return sum;
}

int main()
{
	cout<<"Sum of digits = " << SumDigits(ReadPositivNumber("enter number : "))<<"\n";
	return 0;
}