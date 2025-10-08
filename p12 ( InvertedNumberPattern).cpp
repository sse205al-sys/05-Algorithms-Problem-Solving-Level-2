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

void InvertedPattern(int number)
{
	cout << "\n";
	for (int i = number; i >= 1; i--)
	{
		for (int j = i; j >= 1; j--)
		{
			cout << i;
		}
		cout << "\n";
	}
}
int main()
{
	InvertedPattern(ReadPositivNumber("enter number  : "));
	return 0;
}