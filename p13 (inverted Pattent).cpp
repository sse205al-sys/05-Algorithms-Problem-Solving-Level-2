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

void NumberPattern(int number)
{
	cout << "\n";
	for (int i = 1; i <= number; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i;
		}
		cout << "\n";
	}
}
int main()
{
	NumberPattern(ReadPositivNumber("enter number  : "));
	return 0;
}