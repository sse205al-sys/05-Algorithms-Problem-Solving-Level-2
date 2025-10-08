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
void LetterPattern(int number)
{
	int c = 1; // هون عملت عداد بعد عدد اللفات لكل مره حيث عند كل حرف راح يزيد العداد مره
	for (int i = 65 ; i <= number + 65 - 1; i++)
	{
		
		for (int j = 1; j <=c; j++)
		{
			cout << char(i);
			
		}
		cout << "\n";
		c++;
	}
}
int main()
{
	LetterPattern(ReadPositivNumber("enter number : "));
}