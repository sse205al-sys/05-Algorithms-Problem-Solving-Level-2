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

bool IsPrefect(int number)
{
	int sum = 0;
	for (int i = 1; i < number; i++)
	{
		if (number % i == 0)
			sum += i;
	}
	return sum == number;
}

void AllPrefectNumbers(int num)
{
	for (int i = 1; i < num; i++)
	{
		if (IsPrefect(i))
			cout << i << " is prefect\n";
	}
}

int main()
{
	AllPrefectNumbers( ReadPositivNumber("write the number you want to check if it prefect or not : "));
	return 0;

}