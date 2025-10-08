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
	for (int i = 65 + number-1; i >= 65; i--)
	{
		for (int j = 1; j <= number - (65 + number - 1 - i); j++)//هاذ لايجاد عدد التكرارات اللازمه وهو عباره عن الفرق بسن اخر عدد و العدد الي احنا فيه
		{
			cout << char(i);
			
		}
		cout << "\n";
	}
}
int main()
{
	InvertedLetter(ReadPositivNumber("enter number : "));
}