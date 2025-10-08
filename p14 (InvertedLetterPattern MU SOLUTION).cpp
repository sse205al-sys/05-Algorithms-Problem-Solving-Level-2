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
void InvertedLetter(int number)
{
	for (char i = 65 + number-1; i >= 65; i--)
	{
		for (char j = i; j >= 65; j--)
		{
			cout << i;
		}
		cout << "\n";
	}
}
int main()
{
	InvertedLetter(ReadPositivNumber("enter number : "));
}